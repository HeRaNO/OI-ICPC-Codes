#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MAXM 100010
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt;
int n, m, k, T, u, v, w;
int LCAFather[MAXN][20], LCADis[MAXN][20];
int _2pow[20], lg2[MAXN], dep[MAXN];

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, head[v]
	};
	head[v] = cnt++;
}

inline void pre_work()
{
	lg2[1] = 0;
	for (_2pow[0] = 1; _2pow[k] <= n; k++) _2pow[k + 1] = _2pow[k] << 1;
	for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
	return ;
}

inline void dfs(int x, int father, int val, int deep)
{
	LCAFather[x][0] = father;
	LCADis[x][0] = val;
	dep[x] = deep;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, x, e[i].val, deep + 1);
	return ;
}

inline void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
		{
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
			LCADis[i][j] = LCADis[i][j - 1] + LCADis[LCAFather[i][j - 1]][j - 1];
		}
	return ;
}

inline int GetDis(int u, int v)
{
	int res = 0;
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[v] - dep[u])
		{
			res += LCADis[v][i];
			v = LCAFather[v][i];
		}
	for (int i = k; ~i; i--)
		if (LCAFather[u][i] != LCAFather[v][i])
		{
			res += LCADis[u][i] + LCADis[v][i];
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	if (u != v) res += LCADis[u][0] + LCADis[v][0];
	return res;
}

namespace RMQLCA
{
	int n,u,v,rt,T,R,lg[MAXN<<1],pt[MAXN],dep[MAXN<<1];
	int fa[18][MAXN<<1],euler[MAXN<<1],dis[MAXN];

	inline void dfs(int x,int f,int deep,int v)
	{
		pt[x]=++R;euler[R]=x;dep[R]=deep;dis[x]=v;
		for (int i=head[x];~i;i=e[i].nxt)
			if (e[i].to!=f)
			{
				dfs(e[i].to,x,deep+1,e[i].val+v);
				euler[++R]=x;dep[R]=deep;
			}
		return ;
	}

	inline void RMQLCA()
	{
		dfs(1,-1,0,0);
		for (int i=1;i<=R;i++) fa[0][i]=i;
		for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
		for (int j=1;j<=lg[R];j++)
			for (int i=1;i+(1<<j)-1<=R;i++)
			{
				int a=fa[j-1][i],b=fa[j-1][i+(1<<(j-1))];
				fa[j][i]=dep[a]<=dep[b]?a:b;
			}
		return ;
	}

	inline int getLCA(int x,int y)
	{
		x=pt[x];y=pt[y];
		if (x>y) swap(x,y);
		int t=lg[y-x+1];int a=fa[t][x],b=fa[t][y-(1<<t)+1];
		return dep[a]<=dep[b]?euler[a]:euler[b];
	}

	inline int getDis(int x,int y)
	{
		return dis[x]+dis[y]-2*dis[getLCA(x,y)];
	}
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n);
	read(m);
	pre_work();
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++) if (!LCAFather[i][0]) dfs(i, 0, 0, 1);
	LCA();
	read(T);
	while (T--)
	{
		read(u);
		read(v);
		printf("%d\n", GetDis(u, v));
	}
	return 0;
}
