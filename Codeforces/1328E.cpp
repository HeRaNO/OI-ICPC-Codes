#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,u,v,m,k,x,T,R,lg[MAXN<<1],pt[MAXN],dep[MAXN<<1];
int fa[19][MAXN<<1],euler[MAXN<<1],rf[MAXN],rdep[MAXN];
vector <int> q,g[MAXN];

inline void dfs(int x,int f,int deep)
{
	pt[x]=++R;euler[R]=x;dep[R]=deep;rf[x]=f;rdep[x]=deep;
	for (auto v:g[x])
		if (v!=f)
		{
			dfs(v,x,deep+1);
			euler[++R]=x;dep[R]=deep;
		}
	return ;
}

inline void RMQLCA()
{
	dfs(1,-1,0);
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

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	RMQLCA();
	while (m--)
	{
		scanf("%d",&k);q.clear();bool f=true;
		for (int i=1;i<=k;i++)
		{
			scanf("%d",&x);
			if (x!=1) q.push_back(rf[x]);
		}
		sort(q.begin(),q.end(),[&](int a,int b){return rdep[a]>rdep[b];});
		k=q.size();
		for (int i=0;i<k-1&&f;i++)
			if (getLCA(q[i],q[i+1])!=q[i+1])
				f=false;
		puts(f?"YES":"NO");
	}
	return 0;
}