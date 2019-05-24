#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pii pair<long long,long long>
#define MAXN 1000010
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int fx,n,a[MAXN],u,v,in[MAXN];
pii dp[MAXN];

void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;++in[v];
}
//eom - 0
//moe - 1
void TreeDP(int x,int fa,int f)
{
	pii p;
	if (!f) p=mp(0,~(1LL<<63));
	else p=mp(~(1LL<<63),0);
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa)
		{
			TreeDP(e[i].to,x,1-f);
			if (!f)
			{
				if (dp[e[i].to].fi>p.fi) p=dp[e[i].to];
				else if (dp[e[i].to].fi==p.fi&&dp[e[i].to].se<p.se) p=dp[e[i].to];
			}
			else
			{
				if (dp[e[i].to].fi<p.fi) p=dp[e[i].to];
				else if (dp[e[i].to].fi==p.fi&&dp[e[i].to].se>p.se) p=dp[e[i].to];
			}
		}
	if (!f)
	{
		if (p.se==~(1LL<<63)) dp[x]=mp(0LL,(long long)a[x]);
		else dp[x]=mp(p.fi,p.se+a[x]);
	}
	else
	{
		if (p.fi==~(1LL<<63)) dp[x]=mp((long long)a[x],0LL);
		else dp[x]=mp(p.fi+a[x],p.se);
	}
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9')
	{
		if (ch=='e')
		{
			getchar();getchar();x=0;return ;
		}
		if (ch=='m')
		{
			getchar();getchar();x=1;return ;
		}
		if (ch=='-') f=true;ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	memset(head,-1,sizeof head);
	read(fx);read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i< n;i++) read(u),read(v),add(u,v);
	TreeDP(1,-1,1-fx);
	printf("%lld %lld\n",dp[1].fi,dp[1].se);
	return 0;
}
