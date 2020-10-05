#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,T,R,k,opt,u,v;
int LCAFather[MAXN][18];
int dfn[MAXN],seq[MAXN],_2pow[18],dep[MAXN];
vector <int> g[MAXN];
set <int> s;

inline void dfs(int x,int fa,int deep)
{
	dfn[x]=++R;seq[R]=x;LCAFather[x][0]=fa;dep[x]=deep;
	for (int v:g[x]) if (v!=fa) dfs(v,x,deep+1);
	return ;
}

inline void LCA()
{
	for (int j=1;j<=k;j++)
		for (int i=1;i<=n;i++)
			LCAFather[i][j]=LCAFather[LCAFather[i][j-1]][j-1];
	return ;
}

inline int query(int u,int v)
{
	if (dep[u]<dep[v]) swap(u,v);
	for (int i=k;~i;i--)
		if (_2pow[i]<=dep[u]-dep[v])
			u=LCAFather[u][i];
	if (u==v) return u;
	for (int i=k;~i;i--)
		if (LCAFather[u][i]!=LCAFather[v][i])
			u=LCAFather[u][i],v=LCAFather[v][i];
	return LCAFather[u][0];
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='+') {x=-1;return ;}
		if (ch=='-') return ;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

inline void Solve()
{
	read(n);
	for (_2pow[k=0]=1;_2pow[k]<=n;k++) _2pow[k+1]=_2pow[k]<<1;
	for (int i=1;i<=n;i++) g[i].resize(0);s.clear();R=0;
	for (int i=1;i<n;i++)
	{
		read(u);read(v);++u;++v;
		g[u].push_back(v);g[v].push_back(u);
	}
	dfs(1,1,1);LCA();read(T);
	while (T--)
	{
		read(opt);read(u);++u;
		if (!~opt) s.insert(dfn[u]);
		else s.erase(dfn[u]);
		if (s.empty()) puts("-1");
		else printf("%d\n",query(seq[*s.begin()],seq[*s.rbegin()])-1);
	}
	return ;
}

int main()
{
	int TT;read(TT);
	while (TT--) Solve();
	return 0;
}