#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,u,v,x,y,k,T,R;
int dis[18][MAXN<<1],lg[MAXN<<1],pt[MAXN],dep[MAXN<<1];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void dfs(int x,int f)
{
	dis[0][++R]=dep[x];pt[x]=R;
	for (int i=head[x],v;~i;i=e[i].nxt)
		if ((v=e[i].to)!=f)
		{
			dep[v]=dep[x]+1;dfs(v,x);
			dis[0][++R]=dep[x];
		}
	return ;
}

inline int getDis(int x,int y)
{
	int d=dep[x]+dep[y];x=pt[x];y=pt[y];
	if (x>y) swap(x,y);int t=lg[y-x+1];
	return d-2*min(dis[t][x],dis[t][y-(1<<t)+1]);
}

inline void RMQLCA()
{
	dfs(1,-1);
	for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=lg[R];j++)
		for (int i=1;i+(1<<j)-1<=R;i++)
			dis[j][i]=min(dis[j-1][i],dis[j-1][i+(1<<(j-1))]);
	return ;
}

inline bool check(int a,int b)
{
	return (a<=b)&&(!((b-a)&1));
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	RMQLCA();scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d %d",&x,&y,&u,&v,&k);
		int a=getDis(u,v);
		int b=getDis(u,x)+getDis(v,y)+1;
		int c=getDis(u,y)+getDis(v,x)+1;
		if (check(a,k)||check(b,k)||check(c,k))
			puts("YES");
		else puts("NO");
	}
	return 0;
}