#include <cstdio>
#include <climits>
#include <iostream>
#define MAXN 500
using namespace std;
struct node
{
	int father;
	bool kill;
	int num;
	int lev;
};

node a[MAXN];
bool g[MAXN][MAXN] = {false};
int number[MAXN][MAXN] = {0};
int ans = INT_MAX, maxdep = 0;
int n, p, flag1, flag2, i;

void Build_A_Tree(int k)
{
	int j;
	a[k].num = 1;
	a[k].kill = false;
	for (j = 2; j <= n; j++)
	{
		if (g[k][j] && a[j].father == 0)
		{
			a[j].father = k;
			a[j].lev = a[k].lev + 1;
			number[a[j].lev][0]++;
			number[a[j].lev][number[a[j].lev][0]] = j;
			Build_A_Tree(j);
			a[k].num += a[j].num;
		}
	}
	maxdep = a[k].lev > maxdep ? a[k].lev : maxdep;
}

void dfs(int dep, int now)
{
	if (dep > maxdep)
	{
		if (now < ans)
		{
			ans = now;
			return ;
		}
	}
	if (now < ans) ans = now;
	for (int i = 1; i <= number[dep][0]; i++)
	{
		if (a[a[number[dep][i]].father].kill)
			a[number[dep][i]].kill = true;
	}
	for (int j = 1; j <= number[dep][0]; j++)
	{
		if (a[number[dep][j]].kill)
		{
			a[number[dep][j]].kill = false;
			dfs(dep + 1, now - a[number[dep][j]].num);
			a[number[dep][j]].kill = true;
		}
	}
	for (int q = 1; q <= number[dep][0]; q++)
		a[number[dep][q]].kill = false;
}

int main()
{
	scanf("%d %d", &n, &p);
	for (i = 1; i <= p; i++)
	{
		scanf("%d %d", &flag1, &flag2);
		g[flag1][flag2] = true;
		g[flag2][flag1] = true;
	}
	a[1].lev = 0;
	a[1].father = 0;
	Build_A_Tree(1);
	a[1].kill = true;
	dfs(1, n);
	printf("%d", ans);
	return 0;
}
