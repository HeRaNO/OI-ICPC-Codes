#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const ll inf=999999999999999LL;
const ll mod=1e9+7;
const int N=100050;
int n,q,S;
struct edge
{
	int v,nxt;
	ll w;
}e[N<<5];
int head[N<<5],ecnt;
int h[N];
inline void ad(int u,int v,ll w)
{
	e[++ecnt].v=v;e[ecnt].w=w;
	e[ecnt].nxt=head[u];head[u]=ecnt;
}
ll dis[N<<5];
priority_queue<pii,vector<pii>,greater<pii> >pq;
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while(!pq.empty())pq.pop();
	pq.push({0,s});
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				pq.push({dis[v],v});
			}
		}
	}
}
int build(int l,int r,int id,int val)
{
	if(l==r)return id;
	int mid=(l+r)>>1;
	if(val<=mid)return build(l,mid,ls,val);
	else return build(mid+1,r,rs,val);
}

void query(int l,int r,int id,int L,int R,int rt,bool f,ll cost)
//f==0:rt->id     f==1:id->rt
{
	if(r<=R&&L<=l)
	{
		if(f==0)
		{
			ad(h[rt]+(n<<2),id,cost);
		}
		else
		{
			ad(id+(n<<2),h[rt],cost);
		}
		return;
	}
	int mid=(l+r)>>1;
	if(R<=mid)query(l,mid,ls,L,R,rt,f,cost);
	else if(L>mid)query(mid+1,r,rs,L,R,rt,f,cost);
	else
	{
		query(l,mid,ls,L,mid,rt,f,cost);
		query(mid+1,r,rs,mid+1,R,rt,f,cost);
	}
}
void dfs(int l,int r,int id)
{
	if(l==r)
	{
		ad(id,id+(n<<2),0);
		return;
	}
	ad(id,ls,0);ad(id,rs,0);
	ad((ls)+(n<<2),id+(n<<2),0);
	ad((rs)+(n<<2),id+(n<<2),0);
	int mid=(l+r)>>1;
	dfs(l,mid,ls);
	dfs(mid+1,r,rs);
}

int main()
{
	cin>>n>>q>>S;
	for(int i=1;i<=n;++i)
	{
		h[i]=build(1,n,1,i);
//        printf("%d\n",h[i]);
	}
	for(int i=1;i<=q;++i)
	{
		int type,u,v,L,R;ll w;
		scanf("%d",&type);
		switch(type)
		{
		case 1:
			{
				scanf("%d%d%lld",&u,&v,&w);
				query(1,n,1,v,v,u,0,w);
				break;
			}
		case 2:
			{
				scanf("%d%d%d%lld",&u,&L,&R,&w);
				query(1,n,1,L,R,u,0,w);
				break;
			}
		case 3:
			{
				scanf("%d%d%d%lld",&v,&L,&R,&w);
				query(1,n,1,L,R,v,1,w);
				break;
			}
		}
	}
	dfs(1,n,1);
	dijkstra(h[S]);
	for(int i=1;i<=n;++i)
	{
		ll ans=dis[h[i]];
		if(ans==dis[0])ans=-1;
		printf("%lld ",ans);
	}
	return 0;
}
