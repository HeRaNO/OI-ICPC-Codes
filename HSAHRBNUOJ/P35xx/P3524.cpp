#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct link
{
	int to;
	int id;
	int nxt;
};

link e[MAXN * 2];
int edge_num[MAXN], cnt;
int n, m, T, R, u, v, ans;
int dfn[MAXN], low[MAXN], sta[MAXN], top;
int dep[MAXN], LCAFather[MAXN][20];
int _2pow[20], k, belong[MAXN];
bool vis[MAXN], odd[MAXN];
int dis[MAXN];

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = cnt++;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

void Tarjan(int x, int father)
{
	dfn[x] = low[x] = ++R;
	sta[++top] = x;
	vis[x] = true;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		if (e[i].id == father) continue;
		if (dfn[e[i].to] && vis[e[i].to])
		{
			low[x] = mymin(low[x], dfn[e[i].to]);
			if ((dep[e[i].to] & 1) == (dep[x] & 1)) odd[x] = true;
		}
		else
		{
			LCAFather[e[i].to][0] = x;
			dep[e[i].to] = dep[x] + 1;
			Tarjan(e[i].to, e[i].id);
			low[x] = mymin(low[x], low[e[i].to]);
		}
	}
	if (dfn[x] == low[x])
	{
		int t = top;
		ans++;
		bool v = false;
		while (sta[t] != x) v |= odd[sta[t--]];
		if (v) for (int i = t + 1; i <= top; i++) dis[sta[i]]++;
		do
		{
			t = sta[top--];
			vis[t] = false;
			belong[t] = ans;
		}
		while (t != x);
	}
}

inline int pre_LCA()
{
	_2pow[0] = 1;
	int kk;
	for (kk = 0; _2pow[kk] <= n; kk++) _2pow[kk + 1] = _2pow[kk] << 1;
	return kk;
}

inline void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
	return ;
}

void dfs(int x)
{
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (LCAFather[e[i].to][0] == x)
		{
			dis[e[i].to] += dis[x];
			dfs(e[i].to);
		}
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

inline int LCA(int x, int y)
{
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[y] - dep[x])
			y = LCAFather[y][i];
	if (x == y) return x;
	for (int i = k; ~i; i--)
		if (LCAFather[x][i] != LCAFather[y][i]) x = LCAFather[x][i], y = LCAFather[y][i];
	return LCAFather[y][0];
}

int main()
{
	//freopen("sunset.in","r",stdin);freopen("sunset.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		add(u, v, i);
	}
	k = pre_LCA();
	for (int i = 1; i <= n; i++) if (!dfn[i])
		{
			LCAFather[i][0] = i;
			dep[i] = 1;
			Tarjan(i, 0);
		}
	for (int i = 1; i <= n; i++) if (LCAFather[i][0] == i) dfs(i);
	LCA();
	read(T);
	while (T--)
	{
		read(u);
		read(v);
		if (LCAFather[u][k] != LCAFather[v][k])
		{
			puts("No");
			continue;
		}
		int w = LCA(u, v);
		if ((dep[u] + dep[v] - 2 * dep[w]) & 1 || dis[u] + dis[v] - 2 * dis[w] > 0) puts("Yes");
		else puts("No");
	}
	return 0;
}
