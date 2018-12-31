#include<cstdio>
#include<algorithm>

#define Rep(i) for (int i=0;i<9;i++)
#define in(i,j,x,y) (i>=x&&i<=y&&j>=x&&j<=y)
using namespace std;

const int R = 9 * 9 * 9 + 19, C = 9 * 9 * 4 + 19;
struct node;
typedef node *nd;
struct node
{
	nd L, R, U, D, col;
	int sz, row;
} ND[R * C];
nd rt, Col[C], Row[R];
int A[9][9], cnt, tmp, Ans, a, b, c;

int IDx(int i, int j, int k)
{
	return i * 81 + j * 9 + k;
}
int IDy(int k, int i, int j)
{
	return k * 81 + i * 9 + j + 1;
}
void reID(int x, int &a, int &b, int &c)
{
	x--;
	c = x % 9;
	x /= 9;
	b = x % 9;
	x /= 9;
	a = x;
}
int score(int x, int y)
{
	return in(x, y, 4, 4) ? 10 : in(x, y, 3, 5) ? 9 : in(x, y, 2, 6) ? 8 : in(x, y, 1, 7) ? 7 : 6;
}

void Add_node(int r, int c)
{
	nd x = &ND[++cnt];
	x->col = Col[c];
	x->row = r;
	if (Row[r] == 0)
	{
		Row[r] = x;
		x->L = x->R = x;
	}
	Row[r]->L->R = x, x->L = Row[r]->L, x->R = Row[r], Row[r]->L = x;
	Col[c]->U->D = x, x->U = Col[c]->U, x->D = Col[c], Col[c]->U = x, Col[c]->sz++;
}
void remove(nd x)
{
	x->L->R = x->R;
	x->R->L = x->L;
	for (nd i = x->D; i != x; i = i->D)
		for (nd j = i->R; j != i; j = j->R) j->U->D = j->D, j->D->U = j->U, j->col->sz--;
}
void remuse(nd x)
{
	for (nd i = x->U; i != x; i = i->U)
		for (nd j = i->R; j != i; j = j->R) j->U->D = j->D->U = j, j->col->sz++;
	x->L->R = x->R->L = x;
}
int Dancing()
{
	if (rt->R == rt) return Ans = max(Ans, tmp), 1;
	int Min = 1 << 30, f = 0;
	nd x;
	for (nd i = rt->R; i != rt; i = i->R) if (i->sz < Min) Min = i->sz, x = i;
	remove(x);
	for (nd i = x->D; i != x; i = i->D)
	{
		reID(i->row, a, b, c), tmp += score(a, b) * (c + 1);
		for (nd j = i->R; j != i; j = j->R) remove(j->col);
		f |= Dancing();
		for (nd j = i->L; j != i; j = j->L) remuse(j->col);
		reID(i->row, a, b, c), tmp -= score(a, b) * (c + 1);
	}
	remuse(x);
	return f;
}

int main()
{
	Rep(i) Rep(j) scanf("%d", &A[i][j]);
	rt = Col[0] = &ND[0];
	for (int i = 1; i <= 9 * 9 * 4; i++) Col[i] = &ND[i];
	for (int i = 1; i <= 9 * 9 * 4; i++)
		Col[i]->L = Col[i - 1], Col[i]->R = Col[i + 1],
				Col[i]->U = Col[i]->D = Col[i], Col[i]->sz = 0;
	rt->L = Col[9 * 9 * 4], rt->R = Col[1];
	Col[cnt = 9 * 9 * 4]->R = rt;
	Rep(i) Rep(j) for (int k = 1; k <= 9; k++)
		if (A[i][j] == k || !A[i][j])
		{
			int r = IDx(i, j, k);
			Row[r] = 0;
			Add_node(r, IDy(0, i, j));
			Add_node(r, IDy(1, i, k - 1));
			Add_node(r, IDy(2, j, k - 1));
			Add_node(r, IDy(3, i / 3 * 3 + j / 3, k - 1));
		}
	printf("%d\n", Dancing() ? Ans : -1);
}