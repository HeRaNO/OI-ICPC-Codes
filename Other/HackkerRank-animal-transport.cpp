#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;

int T,n,m,l[MAXN],r,ans[MAXN],dp[MAXN];
int x[1<<17][2],lazy[1<<17][2];
char c;
bool t[MAXN];
vector <pair<int,bool> > v[MAXN];

inline void add(int u,int t,int v)
{
	if (t<=0){x[u][0]+=v;lazy[u][0]+=v;t+=2;}
	if (t==1){x[u][1]+=v;lazy[u][1]+=v;}
	return ;
}

inline void PushDown(int u)
{
	if (lazy[u][0]) add(u<<1,0,lazy[u][0]),add(u<<1|1,0,lazy[u][0]);
	if (lazy[u][1]) add(u<<1,1,lazy[u][1]),add(u<<1|1,1,lazy[u][1]);
	lazy[u][0]=lazy[u][1]=0;
	return ;
}

inline void modify(int u,int t,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr){add(u,t,v);return ;}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,t,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,t,l,r,v,m,pr);
	else
	{
		modify(u<<1,t,l,m,v,pl,m);
		modify(u<<1|1,t,m,r,v,m,pr);
	}
	x[u][0]=max(x[u<<1][0],x[u<<1|1][0]);
	x[u][1]=max(x[u<<1][1],x[u<<1|1][1]);
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

inline void read(char &x)
{
	do x=getchar(); while (x<'A'||x>'Z');
	return ;
}

inline void minimumZooNumbers()
{
	read(m);read(n);memset(ans,-1,sizeof ans);
	for (int i=1;i<=n;i++) read(c),t[i]=(c=='M'||c=='D');
	for (int i=1;i<=n;i++) read(l[i]);
	for (int i=1;i<=n;i++)
	{
		read(r);
		if (l[i]<r) v[r].push_back({l[i],t[i]});
	}
	for (int i=1;i<=m;i++)
	{
		for (auto j:v[i]) modify(1,j.second,1,j.first+1,1,1,m+1);
		dp[i]=max(x[1][0],x[1][1]);
		modify(1,-1,i,i+1,dp[i],1,m+1);
	}
	for (int i=1,las=0;i<=m;i++)
		if (dp[i]>las)
		{
			for (int j=las+1;j<=dp[i];j++) ans[j]=i;
			las=dp[i];
		}
	for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	for (int i=1;i<=m;i++) v[i].clear();
	memset(x,0,sizeof x);memset(lazy,0,sizeof lazy);memset(dp,0,sizeof dp);
	return ;
}

int main()
{
	read(T);
	while (T--) minimumZooNumbers();
	return 0;
}
