#include <vector>
#include <cstdio>
#include <cstring>
#define MAXN 3010
#define MAXM 8010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXM];
int head[MAXN], cnt;
int n, m, T, p, x, y, scc_cnt, ans, a[MAXN], in[MAXN];
int dfn[MAXN], low[MAXN], belong[MAXN], sta[MAXN], v[MAXN], top, need[MAXN];
bool vis[MAXN], bought[MAXN];
vector <int> b[MAXN];

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
			b[scc_cnt].push_back(t);
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
	memset(need, 0x7f, sizeof need);
	read(n);
	read(p);
	for (int i = 1; i <= p; i++) read(a[i]), read(v[a[i]]), bought[a[i]] = true;
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(x);
		read(y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) Tarjan(i);
	for (int i = 1; i <= n; i++)
		for (int j = head[i]; ~j; j = e[j].nxt)
			if (belong[i] != belong[e[j].to])
				++in[belong[e[j].to]];
	for (int i = 1; i <= scc_cnt; i++)
		if (!in[i])
			for (int j = 0; j < b[i].size(); j++)
				if (bought[b[i][j]]) need[i] = mymin(need[i], v[b[i][j]]);
	for (int i = 1; i <= scc_cnt; i++)
		if (need[i] == 0x7f7f7f7f && !in[i])
		{
			for (int j = 1; j <= n; j++)
				if (belong[j] == i)
				{
					printf("NO\n%d\n", j);
					return 0;
				}
		}
		else if (!in[i]) ans += need[i];
	printf("YES\n%d\n", ans);
	return 0;
}