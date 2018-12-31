#include <cstdio>
#include <cstring>
#define MAXN 6010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, u, v, dp[MAXN][2], happy[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

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

inline void TreeDP(int x, int father)
{
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			TreeDP(e[i].to, x);
			dp[x][0] += mymax(dp[e[i].to][1], dp[e[i].to][0]);
			dp[x][1] += dp[e[i].to][0];
		}
	dp[x][1] += happy[x];
	return ;
}

inline int read()
{
	int x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return f ? -x : x;
}

int main()
{
	memset(head, -1, sizeof head);
	n = read();
	for (int i = 1; i <= n; i++) happy[i] = read();
	while (u = read()) v = read(), add(u, v);
	TreeDP(1, -1);
	printf("%d\n", mymax(dp[1][0], dp[1][1]));
	return 0;
}