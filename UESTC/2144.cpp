#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct link
{
	int to,val,nxt;
};

link e[MAXN<<1];
int head[MAXN], cnt;
int n, m, u, v, w, k;
int LCAFather[MAXN][18], LCAVal[MAXN][18], dep[MAXN], _2pow[18];

inline void add(int u, int v, int w)
{
	e[cnt] = (link){v, w, head[u]}; head[u] = cnt++;
	e[cnt] = (link){u, w, head[v]}; head[v] = cnt++;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int x, int f, int val, int deep)
{
	LCAFather[x][0] = f; LCAVal[x][0] = val; dep[x] = deep;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != f)
			dfs(e[i].to, x, e[i].val, deep + 1);
	return ;
}

inline void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
		{
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
			LCAVal[i][j] = mymin(LCAVal[i][j - 1], LCAVal[LCAFather[i][j - 1]][j - 1]);
		}
	return ;
}

inline int query(int u, int v)
{
	int ans = ~(1<<31);
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
	{
		if (_2pow[i] <= dep[v] - dep[u])
		{
			ans = mymin(ans, LCAVal[v][i]);
			v = LCAFather[v][i];
		}
	}
	for (int i = k; ~i; i--)
	{
		if (LCAFather[v][i] != LCAFather[u][i])
		{
			ans = mymin(ans, mymin(LCAVal[u][i], LCAVal[v][i]));
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	}
	if (u != v) ans = mymin(ans, mymin(LCAVal[u][0], LCAVal[v][0]));
	return ans;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n); read(m);
	for (_2pow[0] = 1; _2pow[k] <= n; k++) _2pow[k + 1] = _2pow[k] << 1;
	for (int i = 1; i < n; i++)
	{
		read(u); read(v); read(w);
		add(u, v, w);
	}
	dfs(1, 0, ~(1<<31), 1);
	LCA();
	while (m--)
	{
		read(u); read(v);
		printf("%d\n", query(u, v));
	}
	return 0;
}