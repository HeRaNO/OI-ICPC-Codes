#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int n, m, row, col;
int answer = INF;

int matrix[20][20];
int scoreCol[20]; //scoreCol[i] = score of column i
int score2Col[20][20];  //score2Col[i][j] = additional score when column i & column j be combined
int f[20][20];

int MIN(int a, int b)
{
	return a < b ? a : b;
}
int DP(int rowStatus)
{
	int i, j, k, fMin = INF;
	int rows[20];
	j = 0;
	for (i = 0; i < n; i++)
	{
		if ((rowStatus >> i) & 1)
			rows[j++] = i;
	}
	for (i = 0; i < m; i++)
	{
		scoreCol[i] = 0;
		for (j = 1; j < row; j++)
			scoreCol[i] += abs(matrix[rows[j]][i] - matrix[rows[j - 1]][i]);
		for (j = i + 1; j < m; j++)
		{
			score2Col[i][j] = 0;
			for (k = 0; k < row; k++)
				score2Col[i][j] += abs(matrix[rows[k]][j] - matrix[rows[k]][i]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			f[i][j] = INF;
	}
	for (j = 0; j < m; j++)
		f[1][j] = scoreCol[j];
	for (i = 2; i <= col; i++) //i columns have been selected
	{
		for (j = i - 1; j < m; j++) //current column
		{
			for (k = 0; k < j; k++) //previous column
				f[i][j] = MIN(f[i][j], f[i - 1][k] + scoreCol[j] + score2Col[k][j]);
		}
	}
	for (j = 0; j < m; j++)
		fMin = MIN(fMin, f[col][j]);
	return fMin;
}
void solve(int depth, int status, int rowLeft)
{
	if (depth >= n)
	{
		if (rowLeft == 0)
			answer = MIN(answer, DP(status));
	}
	else
	{
		if (rowLeft > 0)
			solve(depth + 1, (status << 1) | 1, rowLeft - 1);
		if (rowLeft <= n - depth)
			solve(depth + 1, status << 1, rowLeft);
	}
}
int main()
{
	int i, j;
	scanf("%d %d %d %d", &n, &m, &row, &col);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			scanf("%d", &matrix[i][j]);
	}
	solve(0, 0, row);
	printf("%d\n", answer);
	return 0;
}