#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 301
using namespace std;

int n, m;
int a, b, c;
int num, o;
int son[MAXN][MAXN];
int parent[MAXN][3];
int w[MAXN][3];
int rudu[MAXN], z[MAXN];
int dp[MAXN][MAXN];
int tt[MAXN * MAXN][MAXN];
int len[MAXN * MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void work(int kk, int a, int b)
{
	int max_l = mymax(len[a], len[b]);
	len[kk] = max_l;
	int jin = 0;
	for (int i = len[kk]; i; i--)
	{
		tt[kk][i] = (tt[a][i] + tt[b][i] + jin) % 10;
		jin = (tt[a][i] + tt[b][i] + jin) / 10;
	}
	tt[kk][0] = tt[a][0] + tt[b][0] + jin;
	for (int i = len[kk]; i; i--)
	{
		if (tt[kk][i]) break;
		len[kk]--;
	}
	int jie = (tt[kk][0] % 2) * 10, flag;
	tt[kk][0] /= 2;
	for (int i = 1; i <= len[kk]; i++)
	{
		flag = (jie + tt[kk][i]) % 2;
		tt[kk][i] = (jie + tt[kk][i]) / 2;
		jie = flag * 10;
	}
	if (jie)
	{
		len[kk]++;
		tt[kk][len[kk]] = 5;
	}
	return ;
}

int f(int a, int b)
{
	if (w[a][2] < w[b][2]) swap(a, b);
	if (tt[dp[a][b]][0] != -1) return dp[a][b];
	else
	{
		work(dp[a][b], f(parent[a][1], b), f(parent[a][2], b));
		return dp[a][b];
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		parent[a][1] = b;
		parent[a][2] = c;
		son[b][++son[b][0]] = a;
		son[c][++son[c][0]] = a;
		rudu[a] += 2;
	}
	while (w[0][1] != n)
	{
		z[0] = 0;
		for (int i = 1; i <= n; i++)
			if (!rudu[i])
			{
				w[0][1]++;
				w[i][2] = w[0][1];
				w[w[0][1]][1] = i;
				for (int j = 1; j <= son[i][0]; j++)
					z[++z[0]] = son[i][j];
				rudu[i] = -1;
			}
		for (int i = 1; i <= z[0]; i++)
			rudu[z[i]]--;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			o++;
			dp[i][j] = o;
			if (i == j) tt[o][0] = 100;
			else if (!parent[i][1] && !parent[j][1])
				tt[o][0] = 0;
			else tt[o][0] = -1;
		}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		int ans = f(a, b);
		if (!len[ans]) printf("%d", tt[ans][0]);
		else
		{
			printf("%d.", tt[ans][0]);
			for (int i = 1; i <= len[ans]; i++)
				printf("%d", tt[ans][i]);
		}
		putchar('%');
		printf("\n");
	}
	return 0;
}
