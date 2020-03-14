#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define flush fflush(stdout)
#define pb(x) push_back(x)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=3050;
int d[N][N];
int n,m;
int s1,t1,l1;
int s2,t2,l2;
struct edge
{
	int v,nxt;
}e[N<<1];
int head[N],ecnt;
inline void ad(int u,int v)
{
	e[++ecnt].v=v;e[ecnt].nxt=head[u];head[u]=ecnt;
}
bool vis[N];
inline void sp(int S)
{
	d[S][S]=0;
	queue <int> q;
	q.push(S);
	vis[S]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(d[S][v]>d[S][u]+1)
			{
				d[S][v]=d[S][u]+1;
				if(!vis[v])q.push(v),vis[v]=1;
			}
		}
	}
}
inline int dis(int c1,int c2,int c3,int c4)
{
	return d[c1][c2]+d[c2][c3]+d[c3][c4];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ad(x,y),ad(y,x);
	}
	scanf("%d%d%d",&s1,&t1,&l1);
	scanf("%d%d%d",&s2,&t2,&l2);
	mem(d,inf);
	for(int i=1;i<=n;++i)sp(i);
	if(d[s1][t1]>l1||d[s2][t2]>l2)return puts("-1"),0;
	int ans=d[s1][t1]+d[s2][t2];
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if(dis(s1,i,j,t1)<=l1&&dis(s2,i,j,t2)<=l2)
			{
				ans=min(ans,dis(s1,i,j,t1)+dis(s2,i,j,t2)-d[i][j]);
			}
			if(dis(s1,j,i,t1)<=l1&&dis(s2,i,j,t2)<=l2)
			{
				ans=min(ans,dis(s1,j,i,t1)+dis(s2,i,j,t2)-d[i][j]);
			}
			if(dis(s1,j,i,t1)<=l1&&dis(s2,j,i,t2)<=l2)
			{
				ans=min(ans,dis(s1,j,i,t1)+dis(s2,j,i,t2)-d[i][j]);
			}
			if(dis(s1,i,j,t1)<=l1&&dis(s2,j,i,t2)<=l2)
			{
				ans=min(ans,dis(s1,i,j,t1)+dis(s2,j,i,t2)-d[i][j]);
			}
		}
	}
	printf("%d\n",m-ans);
	return 0;
}