#include <bits/stdc++.h>
#define MAXN 200010
#define MAXL 19
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,x,y,k;
int dep[MAXN],_2pow[MAXL],LCAFather[MAXN][MAXL],LCADis[MAXN][MAXL];
long long ans;

inline void add(int u, int v)
{
	e[cnt] = (link){v, head[u]}; head[u] = cnt++;
	e[cnt] = (link){u, head[v]}; head[v] = cnt++;
}

inline void pre_work()
{
	for (_2pow[0] = 1; _2pow[k] <= n; k++) _2pow[k + 1] = _2pow[k] << 1;
	return ;
}

inline void dfs(int x, int father, int val, int deep)
{
	LCAFather[x][0] = father;
	LCADis[x][0] = val;
	dep[x] = deep;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, x, 1, deep + 1);
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

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);pre_work();
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
	}
	dfs(1,0,0,1);LCA();
	for (int i=1;i<=n;i++)
		for (int j=i<<1;j<=n;j+=i)
			ans+=GetDis(i,j)+1;
	printf("%lld\n",ans);
	return 0;
}