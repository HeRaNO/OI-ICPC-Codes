#include <cstdio>
#include <cstring>
#define MAXN 100010
#define MAXDEP 61
using namespace std;

struct link
{
	int to;
	long long val;
	int nxt;
};

link e[MAXN * 2];
int edge_num[MAXN], cnt;
int n, T, x, y, v, u, opt, c1, c2;
long long w, dis[MAXN];
int father[MAXN], dep[MAXN], f[MAXN];
long long s1[MAXDEP], s2[MAXDEP];

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

inline void add(int u, int v, long long w)
{
	e[++cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt;
	e[++cnt] = (link)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = cnt;
}

inline void dfs(int node, int father)
{
	for (int i = edge_num[node]; i; i = e[i].nxt)
		if (father != e[i].to)
		{
			f[e[i].to] = node;
			dep[e[i].to] = dep[node] + 1;
			dis[e[i].to] = e[i].val;
			dfs(e[i].to, node);
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

inline void read(long long &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	read(T);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	dfs(1, 1);
	f[1] = 1;
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= n; i++)
		if (dis[i] == 1LL)
			father[getfather(i)] = getfather(f[i]);
	while (T--)
	{
		read(opt);
		opt--;
		if (!opt)
		{
			read(x);
			read(y);
			read(w);
			c1 = c2 = 0;
			x = getfather(x);
			y = getfather(y);
			while (x != y && c1 + c2 < MAXDEP)
			{
				if (dep[x] > dep[y])
				{
					s1[c1++] = dis[x];
					x = getfather(f[x]);
				}
				else
				{
					s2[c2++] = dis[y];
					y = getfather(f[y]);
				}
			}
			if (c1 + c2 >= MAXDEP) puts("0");
			else
			{
				for (int i = 0; i < c1; i++) w /= s1[i];
				for (int i = 0; i < c2; i++) w /= s2[i];
				printf("%lld\n", w);
			}
		}
		else
		{
			read(v);
			read(w);
			v <<= 1;
			x = f[e[v].to];
			y = e[v].to;
			if (f[e[v - 1].to] == e[v].to)
			{
				v--;
				y = e[v].to;
				x = f[y];
			}
			dis[y] = w;
			if (dis[y] == 1LL) father[getfather(y)] = getfather(x);
		}
	}
	return 0;
}
