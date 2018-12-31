#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXW 2010
#define MAXP 200010
using namespace std;

struct edge
{
	int to;
	int val;
	int nxt;
};

const int delta[4][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};
edge e[MAXP << 1], dislink[MAXW * MAXW];
int w, h, p, T, x, y, k;
int g[MAXW][MAXW];
int d[MAXW][MAXW], belong[MAXW][MAXW];
int father[MAXP];
int disedge[MAXW * MAXW], cnt;
int edge_num[MAXP], ecnt;
int _2pow[20];
int LCAFather[MAXP][20], LCADis[MAXP][20], dep[MAXP];
queue <pair<int, int> > q;

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline int Prepare()
{
	memset(d, -1, sizeof d);
	memset(edge_num, -1, sizeof edge_num);
	int kk;
	_2pow[0] = 1;
	memset(disedge, -1, sizeof disedge);
	for (kk = 0; _2pow[kk] <= p; kk++) _2pow[kk + 1] = _2pow[kk] << 1;
	return kk;
}

inline void add(int u, int v, int w)
{
	e[ecnt] = (edge)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = ecnt++;
	e[ecnt] = (edge)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = ecnt++;
}

inline void adddis(int u, int v, int w)
{
	dislink[cnt] = (edge)
	{
		v, w, disedge[u]
	};
	disedge[u] = cnt++;
}

inline void BFS()
{
	while (!q.empty())
	{
		pair<int, int> u = q.front();
		q.pop();
		int x = u.first, y = u.second;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + delta[i][0], ty = y + delta[i][1];
			if (tx < 1 || tx > w || ty < 1 || ty > h || !g[tx][ty]) continue;
			if (!~d[tx][ty])
			{
				d[tx][ty] = d[x][y] + 1;
				belong[tx][ty] = belong[x][y];
				q.push(make_pair(tx, ty));
			}
			if (belong[tx][ty] != belong[x][y]) adddis(d[x][y] + d[tx][ty], belong[x][y], belong[tx][ty]);
		}
	}
	return ;
}

inline void Kruskal()
{
	for (int i = 0; i <= w * h; i++)
		for (int j = disedge[i]; ~j; j = dislink[j].nxt)
		{
			int x = getfather(dislink[j].to);
			int y = getfather(dislink[j].val);
			if (x != y)
			{
				father[y] = x;
				add(dislink[j].to, dislink[j].val, i);
			}
		}
	return ;
}

inline void dfs(int x, int father, int val, int deep)
{
	LCAFather[x][0] = father;
	LCADis[x][0] = val;
	dep[x] = deep;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, x, e[i].val, deep + 1);
	return ;
}

inline void LCA()
{
	for (int i = 1; i <= p; i++) if (!LCAFather[i][0]) dfs(i, 0, 0, 1);
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= p; i++)
		{
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
			LCADis[i][j] = mymax(LCADis[i][j - 1], LCADis[LCAFather[i][j - 1]][j - 1]);
		}
	return ;
}

inline int query(int u, int v)
{
	int res = 0;
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[v] - dep[u])
		{
			res = mymax(res, LCADis[v][i]);
			v = LCAFather[v][i];
		}
	for (int i = k; ~i; i--)
		if (LCAFather[u][i] != LCAFather[v][i])
		{
			res = mymax(res, mymax(LCADis[u][i], LCADis[v][i]));
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	if (u != v) res = mymax(res, mymax(LCADis[u][0], LCADis[v][0]));
	return res;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '.')
		{
			x = 1;
			return ;
		}
		if (ch == '#')
		{
			x = 0;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("bottle.in","r",stdin);freopen("bottle.out","w",stdout);
	read(w);
	read(h);
	read(p);
	read(T);
	k = Prepare();
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
			read(g[i][j]);
	for (int i = 1; i <= p; i++)
	{
		read(x);
		read(y);
		q.push(make_pair(x, y));
		d[x][y] = 0;
		belong[x][y] = i;
		father[i] = i;
	}
	BFS();
	Kruskal();
	LCA();
	while (T--)
	{
		read(x);
		read(y);
		if (getfather(x) != getfather(y)) puts("-1");
		else printf("%d\n", query(x, y));
	}
	return 0;
}
