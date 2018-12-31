#include <cstdio>
#include <cstring>
#define MAXN 1<<10
using namespace std;

const long long MOD = 1e9 + 7;
const long long rev = (MOD + 1) >> 1;

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, m, T, u, v, val[MAXN];
long long dp[MAXN][MAXN], ans[MAXN], tmp[MAXN];

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, head[v]
	};
	head[v] = cnt++;
}

inline void FWT(long long c[], int n, int f)
{
	long long x, y;
	for (int i = 1; i < n; i <<= 1)
		for (int p = i << 1, j = 0; j < n; j += p)
			for (int k = 0; k < i; k++)
			{
				x = c[j + k];
				y = c[j + k + i];
				c[j + k] = (x + y) % MOD;
				c[j + k + i] = (x - y + MOD) % MOD;
				if (!~f)
				{
					c[j + k] = (c[j + k] * rev) % MOD;
					c[j + k + i] = (c[j + k + i] * rev) % MOD;
				}
			}
	return ;
}

inline void Calculate(long long a[], long long b[])
{
	FWT(a, m, 1);
	FWT(b, m, 1);
	for (int i = 0; i < m; i++) a[i] = (a[i] * b[i]) % MOD;
	FWT(a, m, -1);
	return ;
}

inline void TreeDP(int x, int father)
{
	dp[x][val[x]] = 1;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			TreeDP(e[i].to, x);
			memcpy(tmp, dp[x], sizeof dp[x]);
			Calculate(dp[x], dp[e[i].to]);
			for (int k = 0; k < m; k++) dp[x][k] = (dp[x][k] + tmp[k]) % MOD;
		}
	for (int i = 0; i < m; i++) ans[i] = (ans[i] + dp[x][i]) % MOD;
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		memset(dp, 0, sizeof dp);
		memset(ans, 0, sizeof ans);
		memset(head, -1, sizeof head);
		cnt = 0;
		read(n);
		read(m);
		for (int i = 1; i <= n; i++) read(val[i]);
		for (int i = 1; i < n; i++)
		{
			read(u);
			read(v);
			add(u, v);
		}
		TreeDP(1, -1);
		for (int i = 0; i < m; i++) printf("%d%c", ans[i], i == m - 1 ? '\n' : ' ');
	}
	return 0;
}