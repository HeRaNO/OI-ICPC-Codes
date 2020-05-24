/*
 * Greater NY Regional - Remdoku
 * Fred Pickel
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//#define FIND_ALL
//#define ONE_SHOT

typedef unsigned short WORD;
typedef unsigned char BYTE;
char inbuf[256];

/*
 * this is a standard recursive sudoku solver with two additions
 * 1. An initila scan of the remainder constraints to see if they restrict the
 *		available values in each box (MaskInit)
 * 2. at each recursive search step, once we have set a value in a row & col
 *		and used sudoku constrints to remove available values in the row, col and 3x3 box
 *		scan through the remainder constraints to see if they further restrict the
 *		available values in each box (check_constraints)
 */
int initCnt;
int constraints[15][9];
WORD valid_masks[10] = {0, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x100};
#define ALL_MASK	0x1ff

int dbcnt = 0;

BYTE bit_cnts[32] = {
	0, 1, 1, 2, 1, 2, 2, 3,
	1, 2, 2, 3, 2, 3, 3, 4,
	1, 2, 2, 3, 2, 3, 3, 4,
	2, 3, 3, 4, 3, 4, 4, 5
};

// number of bits on (in low 10 bits) in mask
int get_bitcnt(WORD mask)
{
	return (bit_cnts[mask & 0x1f] + bit_cnts[(mask >> 5) & 0x1f]);
}

// return first on bit in mask (in use should be the only one)
int get_bit_index(WORD mask)
{
	int i;
	WORD test = 0x01;
	for(i = 1; i <= 9 ; i++, test <<= 1) {
		if(mask & test) {
			return i;
		}
	}
	return 0;
}

/*
 * depth first search stack struct for sudoku
 */
typedef struct _search_state_
{
	WORD avail_mask[9][9];	// which values (valid_masks) can still be used in thsi box
	BYTE row_avail_counts[9][9];	// for each row, counts of how many boxes in the row have each value available
	BYTE col_avail_counts[9][9];	// for each col, counts of how many boxes in the col have each value available
	BYTE box_avail_counts[3][3][9];	// for each 3x3 box, counts of how many boxes in the 3x3 box have each value available
	BYTE val_set[9][9];	// if non-zero, this box is set to the current value in the current search
} SEARCH_STATE;

SEARCH_STATE states[81];

/*
 * intialize the search stack to no values chosen and all values available
 * in all boxes
 */
void search_init()
{
	SEARCH_STATE *pss = &(states[0]);
	int i, j, k;
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9 ; j++) {
			pss->avail_mask[i][j] = ALL_MASK;
			pss->val_set[i][j] = 0;
			pss->row_avail_counts[i][j] = 9;
			pss->col_avail_counts[i][j] = 9;
		}
	}
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3 ; j++) {
			for(k = 0; k < 9 ; k++){
				pss->box_avail_counts[i][j][k] = 9;
			}
		}
	}
}

// read constraints from stdin
int scan_constraints()
{
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(fgets(&(inbuf[0]), 255, stdin) == NULL)
			{
				fprintf(stderr, "Read of first line of region %d block %d failed\n", j, i);
				return -21;
			}
			if(sscanf(&(inbuf[0]), "%d %d %d %d %d %d",
				&(constraints[5*i+2*j][0]), &(constraints[5*i+2*j][1]), &(constraints[5*i+2*j][2]), 
				&(constraints[5*i+2*j][3]), &(constraints[5*i+2*j][4]), &(constraints[5*i+2*j][5])) != 6) {
				fprintf(stderr, "Scan of first line of region %d block %d failed\n", j, i);
				return -22;
			}
			if(j < 2) {
				if(fgets(&(inbuf[0]), 255, stdin) == NULL)
				{
					fprintf(stderr, "Read of second line of region %d block %d failed\n", j, i);
					return -23;
				}
				if(sscanf(&(inbuf[0]), "%d %d %d %d %d %d %d %d %d",
					&(constraints[5*i+2*j+1][0]), &(constraints[5*i+2*j+1][1]), &(constraints[5*i+2*j+1][2]), 
					&(constraints[5*i+2*j+1][3]), &(constraints[5*i+2*j+1][4]), &(constraints[5*i+2*j+1][5]), 
					&(constraints[5*i+2*j+1][6]), &(constraints[5*i+2*j+1][7]), &(constraints[5*i+2*j+1][8])) != 9) {
					fprintf(stderr, "Scan of second line of region %d block %d failed\n", j, i);
					return -24;
				}
			}
		}
	}
	return 0;
}

/*
 * before starting depth first search
 * scan constraints for any restrictions on values in each box
 */
int MaskInit(SEARCH_STATE *pss)
{
	int i, con, row, col, baseConsRow, baseConsCol, con_cnts[10], ncons, mincon, maxconcnt;
	WORD remMask, OKmask;
	for(row = 0, baseConsRow = 0; row < 9 ; row++) {
		for(col = 0, baseConsCol = 0; col < 9 ; col++) {
			for(i = 0; i < 10 ; i++) con_cnts[i] = 0;
			ncons = maxconcnt = 0;
			mincon = 9;
			if((row == 0) && (col == 2)) {
				dbcnt++;
			}
			remMask = 0;
			if((col %3) != 0) {	// if not first col in 3x3 block, check constraint with box to left
				con = constraints[baseConsRow][baseConsCol-1];
				con_cnts[con]++;
				ncons++;
				if(mincon > con) mincon = con;
				if((con < 9) && (con_cnts[con] > maxconcnt)) maxconcnt = con_cnts[con];
			}
			if((col %3) != 2) {	// if not last col in 3x3 block, check constraint with box to right
				con = constraints[baseConsRow][baseConsCol];
				con_cnts[con]++;
				ncons++;
				if(mincon > con) mincon = con;
				if((con < 9) && (con_cnts[con] > maxconcnt)) maxconcnt = con_cnts[con];
			}
			if((row %3) != 0) {	// if not top row in 3x3 block, check constraint with box above
				con = constraints[baseConsRow-1][col];
				con_cnts[con]++;
				ncons++;
				if(mincon > con) mincon = con;
				if((con < 9) && (con_cnts[con] > maxconcnt)) maxconcnt = con_cnts[con];
			}
			if((row %3) != 2) {	// if not bottom row in 3x3 block, check constraint with box below
				con = constraints[baseConsRow+1][col];
				con_cnts[con]++;
				ncons++;
				if(mincon > con) mincon = con;
				if((con < 9) && (con_cnts[con] > maxconcnt)) maxconcnt = con_cnts[con];
			}
			if(mincon != 9) { // constraints
				if(con_cnts[4] > 0) {	// one si 5 and the other 9
					OKmask = valid_masks[5] | valid_masks[9];
					remMask |= ~OKmask;
				}
				if(con_cnts[3] > 0) { // either 4 & 7 or 5 & 8 or 6 & 9
					remMask |= valid_masks[1] | valid_masks[2] | valid_masks[3];
				}
				if(con_cnts[2] > 0) { // cannot be 1 or 2 
					remMask |= valid_masks[1] | valid_masks[2];
				}
				if(con_cnts[1] > 0) { // cannot be 1
					remMask |= valid_masks[1];
				}
				if(remMask != 0) {	// adjust counts for boxes in same row, col or 3x3 box
					pss->avail_mask[row][col] &= ~remMask; 
					for(i = 0; i < 9 ; i++) {
						if(valid_masks[i] & remMask) {
							pss->col_avail_counts[col][i-1]--;
							pss->row_avail_counts[row][i-1]--;
							pss->box_avail_counts[row/3][col/3][i-1]--;
						}
					}
				}
			}
			if((col %3) != 2) {	// advance to next row constraint if not last col in 3x3 box
				baseConsCol++;
			}
		}
		if((row % 3) != 2) {	// if not last row of 3x3 box used 2 rows of constrsints, else 1
			baseConsRow += 2;
		} else {
			baseConsRow++;
		}
	}
	return 0;
}

/*
 * determine if any values available in the current box (baseMask) can
 * be excluded by applying constraint with the available values in the neighboring box (chkMask)
 * return mask of values to be REMOVED
 */
WORD checkConstraint(int constraint, WORD baseMask, WORD chkMask)
{
	WORD OKmask, result;
	int i, j;
	OKmask = 0;
	if(constraint == 9) { // no restricition
		return 0;
	}
	// if value in chkMask is the larger, values in base can be in range
	// (chkval/(constraint+1)) + 1. to chkval/constraint (could be empty set)
	for(i = constraint+1; i <= 9 ; i++) {
		if(chkMask & valid_masks[i]) {
			for(j = constraint+1; j <= 9; j++) {
				if((j != i) && (((j%i) == constraint) || ((i % j) == constraint))) OKmask |= valid_masks[j];
			}
		}
	}
	result = baseMask & ~OKmask;
	return result;
}

/*
 * for each box, check if constraints with respect to neighboring boxes eliminate
 * any available values
 * return -1 if some box has no remaining available values
 */
int check_constraints(SEARCH_STATE *pss)
{
	int i, row, col, baseConsRow, baseConsCol, scan_count, change_count = 1;
	WORD baseMask, chkMask, resultMask, totResult;
	scan_count = 0;
	// sacn all constraints until no more changes
	while(change_count > 0) {
		scan_count++;
		change_count = 0;
		for(row = 0, baseConsRow = 0; row < 9 ; row++) {
			for(col = 0, baseConsCol = 0; col < 9 ; col++) {
				if((row == 2) && (col == 8)) {
					dbcnt++;
				}
				if(pss->val_set[row][col] == 0) {	// if we have not already set this box in search see if it can change
					baseMask = pss->avail_mask[row][col];
					totResult = 0;	// all changes to baseMask
					if((col %3) != 0) {	// if not first col in 3x3 block, check constraint with box to left
						chkMask = pss->avail_mask[row][col-1];
						resultMask = checkConstraint(constraints[baseConsRow][baseConsCol-1], baseMask, chkMask);
						if(resultMask != 0) {
							baseMask &= ~resultMask;
							change_count++;
							totResult |= resultMask;
						}
					}
					if((col %3) != 2) {	// if not last col in 3x3 block, check constraint with box to right
						chkMask = pss->avail_mask[row][col+1];
						resultMask = checkConstraint(constraints[baseConsRow][baseConsCol], baseMask, chkMask);
						if(resultMask != 0) {
							baseMask &= ~resultMask;
							change_count++;
							totResult |= resultMask;
						}
					}
					if((row %3) != 0) {	// if not top row in 3x3 block, check constraint with box above
						chkMask = pss->avail_mask[row-1][col];
						resultMask = checkConstraint(constraints[baseConsRow-1][col], baseMask, chkMask);
						if(resultMask != 0) {
							baseMask &= ~resultMask;
							change_count++;
							totResult |= resultMask;
						}
					}
					if((row %3) != 2) {	// if not bottom row in 3x3 block, check constraint with box below
						chkMask = pss->avail_mask[row+1][col];
						resultMask = checkConstraint(constraints[baseConsRow+1][col], baseMask, chkMask);
						if(resultMask != 0) {
							baseMask &= ~resultMask;
							change_count++;
							totResult |= resultMask;
						}
					}
					if(baseMask == 0) {	// not already set and no values available for box
#ifdef _DEBUG
						fprintf(stderr, "cc row %d col %d bcr %d bcc %d\n",
							row, col, baseConsRow, baseConsCol);
#endif
						return -1;
					}
					pss->avail_mask[row][col] = baseMask; 
					if(totResult != 0) {	// adjust counts for boxes in same row, col or 3x3 box
						for(i = 0; i < 9 ; i++) {
							if(valid_masks[i] & totResult) {
								pss->col_avail_counts[col][i-1]--;
								pss->row_avail_counts[row][i-1]--;
								pss->box_avail_counts[row/3][col/3][i-1]--;
							}
						}
					}
				}
				if((col %3) != 2) {	// advance to next row constraint if not last col in 3x3 box
					baseConsCol++;
				}
			}
			if((row % 3) != 2) {	// if not last row of 3x3 box used 2 rows of constrsints, else 1
				baseConsRow += 2;
			} else {
				baseConsRow++;
			}
		}
	}
	return 0;
}

/*
 * depth first search step choice info
 */
#define STYP_ROW	1	// depth first search on boxes with a value available in a given row
#define STYP_COL	2	// depth first search on boxes with a value available in a given col
#define STYP_BOX	3	// depth first search on boxes with a value available in a given 3x3 box
#define STYP_VAL	4	// depth first search on values available in a given box (row & col)
typedef struct _solve_data_ {
	int solve_type;
	int solve_val;
	int solve_row;
	int solve_col;
	int solve_cnt;
	int solve_index;
	int test_row;
	int test_col;
} SOLVE_DATA;

/*
 * choose how to branch for the next sudoku depth first search step
 * choose the branching with the smallest number of children in the tree
 * either the sammlest number of values still available in a box (row & col)
 * or the smallest number of boxes in a row, col or 3x3 sub-box with a particular value available
 * on return *psd has the information on the branch choice
 */
int GetSolveStep(SEARCH_STATE *pss, SOLVE_DATA *psd)
{
	int i, j, k;
	psd->solve_cnt = 10;
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			if(pss->val_set[i][j] == 0) {
				k = get_bitcnt(pss->avail_mask[i][j]);
				if(k < psd->solve_cnt) {
					psd->solve_cnt = k;
					psd->solve_type = STYP_VAL;
					psd->solve_row = i;
					psd->solve_col = j;
					psd->solve_val = get_bit_index(pss->avail_mask[i][j]);
				}
			}
		}
	}
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			if(pss->row_avail_counts[i][j] < psd->solve_cnt) {
				psd->solve_cnt = pss->row_avail_counts[i][j];
				psd->solve_type = STYP_ROW;
				psd->solve_row = i;
				psd->solve_val = j+1;
			}
		}
	}
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			if(pss->col_avail_counts[i][j] < psd->solve_cnt) {
				psd->solve_cnt = pss->col_avail_counts[i][j];
				psd->solve_type = STYP_COL;
				psd->solve_col = i;
				psd->solve_val = j+1;
			}
		}
	}
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			for(k = 0; k < 9 ; k++) {
				if(pss->box_avail_counts[i][j][k] < psd->solve_cnt) {
					psd->solve_cnt = pss->box_avail_counts[i][j][k];
					psd->solve_type = STYP_BOX;
					psd->solve_row = i;
					psd->solve_col = j;
					psd->solve_val = k+1;
				}
			}
		}
	}
	if(psd->solve_cnt == 0) {	// if some value has no choices left, fail
		return -1;
	} else {
		return 0;
	}
}

/*
 * after we have made a branch choice, we have to try each of the branches
 * at the search node bay scanning through boxes in the selected row, col or 3x3 box
 * or values within a selected box, thsi routine steps to the next choice
 * for first try, start with 0, else start with location after previous try
 * and scan to the next available box or value
 */
int FindNextTest(SEARCH_STATE *pss, SOLVE_DATA *psd)
{
	int i, j, starti, startj;
	WORD mask = valid_masks[psd->solve_val];
	if(psd->solve_index >= psd->solve_cnt) {
		return -1;
	}
	switch(psd->solve_type) {
	case STYP_VAL:
		if(psd->solve_index == 0) {
			j = 0;
		} else {
			j = psd->solve_val+1;
		}
		psd->test_col = psd->solve_col;
		psd->test_row = psd->solve_row;
		mask = pss->avail_mask[psd->solve_row][psd->solve_col];
		for(i = j ; i < 10 ; i++) {
			if(mask & valid_masks[i]) {
				psd->solve_val = i;
				psd->solve_index++;
				return 0;
			}
		}
		return -1;
	case STYP_ROW:
		if(psd->solve_index == 0) {
			startj = 0;
		} else {
			startj = psd->test_col+1;
		}
		i = psd->solve_row;
		for(j = startj ; j < 9 ; j++) {
			if(pss->avail_mask[i][j] & mask) {
				psd->test_col = j;
				psd->test_row = i;
				psd->solve_index++;
				return 0;
			}
		}
		return -1;
	case STYP_COL:
		if(psd->solve_index == 0) {
			starti = 0;
		} else {
			starti = psd->test_row+1;
		}
		j = psd->solve_col;
		for(i = starti ; i < 9 ; i++) {
			if(pss->avail_mask[i][j] & mask) {
				psd->test_col = j;
				psd->test_row = i;
				psd->solve_index++;
				return 0;
			}
		}
		return -1;
	case STYP_BOX:
		if(psd->solve_index == 0) {
			starti = 0;
			startj = 0;
		} else {
			starti = psd->test_row - 3*psd->solve_row;
			startj = psd->test_col+1 - 3*psd->solve_col;
		}
		for(i = starti; i < 3 ; i++) {
			for(j = startj ; j < 3; j++) {
				if(pss->avail_mask[i + 3*psd->solve_row][j + 3*psd->solve_col] & mask) {
					psd->test_col = j + 3*psd->solve_col;
					psd->test_row = i + 3*psd->solve_row;
					psd->solve_index++;
					return 0;
				}
			}
		}
		return -1;
	default:
		fprintf(stderr, "bad solve type %d\n", psd->solve_type);
		return -1;
	}
}

/*
 * apply a choice to set a box at row, col,to value
 * then clear all other avail masks at row, col and
 * apply sudoku constraints to decrement counts
 * for other boxes in row, col and 3x3 box not already set,
 * remove val from avail_masks and decrement counts
 */
int ApplyChoice(SEARCH_STATE *pss, int row, int col, int val)
{
	int i, j, boxr, boxc;
	WORD mask = valid_masks[val];
	if(pss->val_set[row][col] != 0) {
		fprintf(stderr, "ApplyChoice: row %d col %d val %d already set to %d\n", row, col, val, pss->val_set[row][col]);
		return -1;
	}
	pss->val_set[row][col] = val;
	// remove val from other avails in row, col and box
	boxr = row/3;
	boxc = col/3;
	for(j = 0; j < 9 ; j++) {
		if(pss->avail_mask[row][j] & mask) {	// reduce counts
			pss->box_avail_counts[boxr][j/3][val-1]--;
			pss->col_avail_counts[j][val-1]--;
		}
		pss->avail_mask[row][j] &= ~mask;
	}
	for(i = 0; i < 9 ; i++) {
		if(pss->avail_mask[i][col] & mask) {
			pss->box_avail_counts[i/3][boxc][val-1]--;
			pss->row_avail_counts[i][val-1]--;
		}
		pss->avail_mask[i][col] &= ~mask;
	}
	boxr = row/3;
	boxc = col/3;
	for(i = 3*boxr; i < 3*(boxr+1); i++) {
		for(j = 3*boxc; j < 3*(boxc+1); j++) {
			if(pss->avail_mask[i][j] & mask) {
				pss->col_avail_counts[j][val-1]--;
				pss->row_avail_counts[i][val-1]--;
			}
			pss->avail_mask[i][j] &= ~mask;
		}
	}
	//for each other value at row/col, decrement ist counts
	for(i = 1; i <= 9 ; i++) {
		if((i != val) && ((pss->avail_mask[row][col] & valid_masks[i]) != 0)){
			pss->box_avail_counts[row/3][col/3][i-1]--;
			pss->col_avail_counts[col][i-1]--;
			pss->row_avail_counts[row][i-1]--;
		}
	}
	pss->avail_mask[row][col] = mask;	// no one can use it but we need to tell neighbors that other vals not avail
	pss->row_avail_counts[row][val-1] = 32;	// never choose the row and val again
	pss->col_avail_counts[col][val-1] = 32;	// never choose the col and val again
	pss->box_avail_counts[boxr][boxc][val-1]= 32;	// never choose the box and val again
	return 0;
}

int solnCnt = 0;

void PrintSoln(SEARCH_STATE *pss)
{
	int i, j;
	printf("%d\n", solnCnt);
	for(i = 0; i < 9 ; i++) {
		for(j = 0; j < 9 ; j++) {
			printf("%d ", pss->val_set[i][j]);
		}
		printf("\n");
	}
}


/*
 * sudoku recursive step
 * at given level, copy current state to next slot, 
 * pick a branch row col or 3x3 box and value
 * if we are down the last choice (depth = 80) just set the (only remaining) choice and return 0
 * for each branch. set the value at the row & col to the appropriate value
 * and update avail counts to reflect sudoku constraints
 * then chack remainder constraints
 * if any box has no more available values, go on to the next choice on the branch
 * else call Solve recursively
 * If the recursive call returns -1, go on to the next choice on the branch
 *  and if you run out of boxes return -1
 * if recursive call returns 0, copy soln (val_set from next slot to current and return 0
 * so when top level returns, val_set is the soln
 */
int Solve(int level)
{
	SEARCH_STATE *pssnxt, *pss = &(states[level]);
	SOLVE_DATA sd;
	int i, j;
	if(GetSolveStep(pss, &sd) != 0) {	// find row, col or 3x3 box) + value to scan
		return -1;
	}
	sd.solve_index = 0;
	while(FindNextTest(pss, &sd) == 0) {	// for each candidate in chosen row, col or 3x3 box, get row& col to set
		if(level == 80 - initCnt) {	// if this is the last box to fill in we are done, set it and return 0 (success)
			pss->val_set[sd.test_row][sd.test_col] = sd.solve_val;
#ifdef FIND_ALL
			solnCnt++;
			PrintSoln(pss);
			return -1;
#else
			return 0;
#endif
		} else {	// else copy current to next and try each possiblility
			pssnxt = &(states[level+1]);
			*pssnxt = *pss;
			if(ApplyChoice(pssnxt, sd.test_row, sd.test_col, sd.solve_val) == 0) { // set this value choice
				if(check_constraints(pssnxt) == 0) {	// if not killed by constraints	
					if(Solve(level+1) == 0) {	// call solve recursively, if success, copy val_set
						for(i = 0; i < 9; i++) {
							for(j = 0; j < 9 ; j++) {
								pss->val_set[i][j] = pssnxt->val_set[i][j];
							}
						}
						return 0;
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int ret, i, row, col, val;
#ifndef FIND_ALL
	int j;
#endif
#ifdef ONE_SHOT
	int nprob, curprob, index;
	if(fgets(&(inbuf[0]), 255, stdin) == NULL)
	{
		fprintf(stderr, "Read failed on problem count\n");
		return -1;
	}
	if(sscanf(&(inbuf[0]), "%d", &nprob) != 1)
	{
		fprintf(stderr, "Scan failed on problem count\n");
		return -2;
	}
	for(curprob = 1; curprob <= nprob ; curprob++)
	{
		if(fgets(&(inbuf[0]), 255, stdin) == NULL)
		{
			fprintf(stderr, "Read failed on problem %d header\n", curprob);
			return -3;
		}
		// get prob num degree
		if(sscanf(&(inbuf[0]), "%d", &index) != 1)
		{
			fprintf(stderr, "scan failed on problem header problem index %d\n",
				curprob);
			return -6;
		}
		if(index != curprob)
		{
			fprintf(stderr, "problem index %d not = expected problem %d\n",
				index, curprob);
			return -7;
		}
#endif
		// get num init vals
		if(fgets(&(inbuf[0]), 255, stdin) == NULL)
		{
			fprintf(stderr, "Read failed on initCnt\n");
			return -6;
		}
		if(sscanf(&(inbuf[0]), "%d", &initCnt) != 1)
		{
			fprintf(stderr, "scan failed on initCnt\n");
			return -7;
		}
		if((initCnt < 0) || (initCnt > 81)) {
			fprintf(stderr, "init val cnt %d not in range 0 .. 81\n",
				initCnt);
			return -8;
		}
		search_init();	// init first atate
		if((ret = scan_constraints()) != 0) {	// read constriants
			return ret;
		}
		MaskInit(&(states[0]));
		if(check_constraints(&(states[0])) != 0) { // apply constraints to first state
#ifdef ONE_SHOT
			fprintf(stderr, "problem index %d init check constraints failed\n",
				index);
#else
			fprintf(stderr, "problem init check constraints failed\n");
#endif
			return -8;
		}
		for(i = 0; i < initCnt ; i++) {
			if(fgets(&(inbuf[0]), 255, stdin) == NULL)
			{
				fprintf(stderr, "Read failed on init val %d\n", i+1);
				return -9;
			}
			// get prob num degree
			if(sscanf(&(inbuf[0]), "%d %d %d", &row, &col, &val) != 3)
			{
				fprintf(stderr, "scan failed on init val %d\n", i+1);
				return -10;
			}
			if((row < 1) || (row > 9) || (col < 1) || (col > 9) || (val < 0) || (val > 9)) {
				fprintf(stderr, "init val %d row %d col %d or val %d not in range 1 .. 9\n",
					i+1, row, col, val);
				return -11;
			}
			if(ApplyChoice(&(states[0]), row-1, col-1, val) != 0) {
				fprintf(stderr, "init val %d error adding row %d col %d or val %d\n",
					i+1, row, col, val);
				return -12;
			}
			if(check_constraints(&(states[0])) != 0) { // apply constraints to first state
				fprintf(stderr, "check constraints failed after init val %d\n",
					i+1);
				return -13;
			}
		}
#ifdef FIND_ALL
		solnCnt = 0;
#ifdef ONE_SHOT
		printf("%d\n", index);
#endif
		Solve(0); 	// call solve
		if(solnCnt == 0) {
			fprintf(stderr, "no solution\n");
			return -9;
		}
#else
		if(Solve(0) != 0) {	// call solve
#ifdef ONE_SHOT
			fprintf(stderr, "problem index %d no solution\n",
				index);
#else
			fprintf(stderr, "problem no solution\n");
#endif
			return -9;
		}
		// if it works, print out soln
#ifdef ONE_SHOT
		printf("%d\n", index);
#endif
		for(i = 0; i < 9 ; i++) {
			for(j = 0; j < 9 ; j++) {
				printf("%d ", states[0].val_set[i][j]);
			}
			printf("\n");
		}
#endif
#ifdef ONE_SHOT
	}
#endif
	return 0;
}