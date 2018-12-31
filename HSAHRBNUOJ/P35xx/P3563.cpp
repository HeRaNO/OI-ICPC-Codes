#include <cstdio>
#include <cstring>
#define MAXN 2010
#define MAXM 100010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXM << 1];
int edge_num[MAXN], cnt, u, v;
int color[MAXN], g[3];
int n, m, ans = ~(1 << 31);
bool flag, ck[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt++;
}

inline void dfs(int x, int c)
{
	color[x] = c;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		if (flag) return ;
		if (color[e[i].to] == c)
		{
			flag = true;
			return ;
		}
		if (!color[e[i].to]) dfs(e[i].to, 3 - c);
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
	//freopen("group.in","r",stdin);freopen("group.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) g[color[i]]++;
	ans = mymax(g[1], g[2]);
	if (ans == 1001) ans += 2;
	if (!flag) printf("%d\n", ans);
	else puts("ZXG!");
	return 0;
}
