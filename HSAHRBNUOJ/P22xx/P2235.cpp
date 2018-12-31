#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 110
#define MAXL 1000010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN * MAXN];
int edge_num[MAXN * MAXN], cnt;
string S;
int n, T[MAXN], w[MAXN], dp[MAXN], ans;

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
}

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void read(int x)
{
	getline(cin, S);
	int len = S.length(), cnt = 0, r = 0;
	for (int i = 0; i < len; i++)
	{
		if (S[i] < '0' || S[i] > '9') T[++cnt] = r, r = 0;
		else r = r * 10 + S[i] - '0';
	}
	if (r) T[++cnt] = r;
	if (!x) n = T[1];
	else
	{
		w[x] = T[1];
		for (int i = 2; i <= cnt; i++) add(x, T[i]);
	}
	return ;
}

inline void TreeDP(int x)
{
	if (dp[x]) return ;
	dp[x] = w[x];
	int mx = 0;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		TreeDP(e[i].to);
		mx = mymax(mx, dp[e[i].to]);
	}
	dp[x] += mx;
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	read(0);
	for (int i = 1; i <= n; i++) read(i);
	for (int i = 1; i <= n; i++)
	{
		TreeDP(i);
		for (int j = 1; j <= n; j++) ans = mymax(ans, dp[j]);
	}
	printf("%d\n", ans);
	return 0;
}
