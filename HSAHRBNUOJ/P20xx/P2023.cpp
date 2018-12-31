#include <cstdio>
#include <cstring>
#define MAXN 105
#define MAXM 10010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXM];
int head[MAXN], cnt;
int n, T, x, scc_cnt, cnt1, cnt2;
int dfn[MAXN], low[MAXN], belong[MAXN], sta[MAXN], top;
int in[MAXN], out[MAXN];
bool vis[MAXN];

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void Tarjan(int x)
{
	dfn[x] = low[x] = ++T;
	sta[++top] = x;
	for (int i = head[x]; ~i; i = e[i].nxt)
	{
		if (vis[e[i].to]) continue;
		if (dfn[e[i].to]) low[x] = mymin(low[x], dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to);
			low[x] = mymin(low[x], low[e[i].to]);
		}
	}
	if (dfn[x] == low[x])
	{
		int t;
		++scc_cnt;
		do
		{
			t = sta[top--];
			vis[t] = true;
			belong[t] = scc_cnt;
		}
		while (t != x);
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			read(x);
			if (!x) break;
			add(i, x);
		}
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) Tarjan(i);
	for (int i = 1; i <= n; i++)
		for (int j = head[i]; ~j; j = e[j].nxt)
			if (belong[i] != belong[e[j].to])
				++out[belong[i]], ++in[belong[e[j].to]];
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (!in[i]) ++cnt1;
		if (!out[i]) ++cnt2;
	}
	printf("%d\n%d\n", cnt1, scc_cnt == 1 ? 0 : mymax(cnt1, cnt2));
	return 0;
}