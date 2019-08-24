#include <bits/stdc++.h>
#define fi first
#define se second
#define MAXN 50005
using namespace std;

struct D
{
	long long d;int u,p;
	D(){}
	D(long long _,int __,int ___):d(_),u(__),p(___){}
	bool operator < (const D &a)const{
		return d>a.d;
	}
};

int n,m,T,TT,u,v,w,a[MAXN],mx;
long long ans[MAXN];
priority_queue <D> q;
vector <pair<long long,int> > g[MAXN];

int main()
{
	scanf("%d",&TT);
	while (TT--)
	{
		while (!q.empty()) q.pop();mx=0;
		scanf("%d %d %d",&n,&m,&T);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back(make_pair(1LL*w,v));
		}
		for (int i=1;i<=n;i++)
			if (g[i].size())
			{
				sort(g[i].begin(),g[i].end());
				q.push(D(g[i][0].fi,i,0));
			}
		for (int i=1;i<=T;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
		for (int i=1;i<=mx;i++)
		{
			D x=q.top();q.pop();ans[i]=x.d;
			if (x.p+1<g[x.u].size())
				q.push(D(x.d-g[x.u][x.p].fi+g[x.u][x.p+1].fi,x.u,x.p+1));
			int nxt=g[x.u][x.p].se;
			if (g[nxt].size())
				q.push(D(x.d+g[nxt][0].fi,nxt,0));
		}
		for (int i=1;i<=T;i++) printf("%lld\n",ans[a[i]]);
	}
	return 0;
}
