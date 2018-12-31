#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN * MAXN];
int head[MAXN], cnt;
int n, T, a, b, s[MAXN], dfn[MAXN], low[MAXN];
bool ans[MAXN];

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

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void Tarjan(int x)
{
	dfn[x] = low[x] = ++T;
	int c = 0;
	for (int i = head[x]; ~i; i = e[i].nxt)
	{
		if (!dfn[e[i].to])
		{
			Tarjan(e[i].to);
			c++;
			low[x] = mymin(low[x], low[e[i].to]);
			if (x != 1 && dfn[x] <= low[e[i].to]) ans[x] = true;
		}
		else low[x] = mymin(low[x], dfn[e[i].to]);
	}
	if (x == 1 && c > 1) ans[x] = true;
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	scanf("%d", &n);
	while (~scanf("%d %d", &a, &b)) add(a, b);
	Tarjan(1);
	for (int i = 1; i <= n; i++) if (ans[i]) s[++s[0]] = i;
	for (int i = 0; i <= s[0]; i++) printf("%d\n", s[i]);
	return 0;
}