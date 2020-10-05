#include <bits/stdc++.h>
#define MAXN 3005
using namespace std;

struct triple
{
	int l,r,x;
};

triple A[MAXN],B[MAXN];
int n,a,b,dis[MAXN],cnt[MAXN];
vector <pair<int,int> > g[MAXN];
bool vis[MAXN];

inline void add(int u,int v,int w)
{
	g[u].push_back({v,w});
}

inline bool SPFA(int S)
{
	queue <int> q;
	memset(dis,0x3f,(n+5)<<2);
	memset(cnt,0,(n+5)<<2);memset(vis,false,n+5);
	q.push(S);cnt[S]=1;dis[S]=0;vis[S]=true;
	while (!q.empty())
	{
		int u=q.front();q.pop();vis[u]=false;
		for (auto [v,w]:g[u])
			if (dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;cnt[v]=cnt[u]+1;
				if (cnt[v]>=n+2) return false;
				if (!vis[v]) vis[v]=true,q.push(v);
			}
	}
	return true;
}

inline bool check(int Sn)
{
	for (int i=0;i<=n;i++) g[i].resize(0);
	for (int i=0;i<n;i++) add(i,i+1,1),add(i+1,i,0);
	for (int i=1;i<=a;i++) add(A[i].r,A[i].l-1,-A[i].x);
	for (int i=1;i<=b;i++) add(B[i].l-1,B[i].r,Sn-B[i].x);
	add(0,n,Sn);add(n,0,-Sn);
	return SPFA(0);
}

inline void Solve()
{
	scanf("%d %d %d",&n,&a,&b);
	for (int i=1;i<=a;i++) scanf("%d %d %d",&A[i].l,&A[i].r,&A[i].x);
	for (int i=1;i<=b;i++) scanf("%d %d %d",&B[i].l,&B[i].r,&B[i].x);
	int l=0,r=n,ans=n;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)){ans=mid;r=mid-1;}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}