#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXN 31000
using namespace std;

struct node
{
	int fa;
	int d;//i飞船前面有多少飞船 b
	int l;//当i是并查集根时，i后面有多少飞船 c
};
char flag;
node f[MAXN];
int i, t, x, y;

int getfather(int x)
{
	int t;
	if (x == f[x].fa) return x;
	t = f[x].fa;
	f[x].fa = getfather(f[x].fa);
	f[x].d += f[t].d;
	return f[x].fa;
}

void merg(int x, int y)
{
	int tx = getfather(x);
	int ty = getfather(y);
	if (tx != ty)
	{
		f[tx].fa = ty;
		f[tx].d = f[ty].l + 1;
		f[ty].l = f[ty].l + f[tx].l + 1;
	}
}

int query(int x, int y)
{
	if (getfather(x) == getfather(y))
		return (abs(f[x].d - f[y].d) - 1);
	else return -1;
}

int main()
{
	for (i = 1; i <= MAXN; i++)
	{
		f[i].fa = i;
		f[i].d = 0;
		f[i].l = 0;
	}
	scanf("%d\n", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%c %d %d\n", &flag, &x, &y);
		if (flag == 'M')
			merg(x, y);
		else
			printf("%d\n", query(x, y));
	}
	return 0;
}