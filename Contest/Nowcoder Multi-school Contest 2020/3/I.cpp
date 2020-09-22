#include <bits/stdc++.h>
#define MAXN 800005
using namespace std;

int T,n,m,ans[MAXN],a[MAXN],t[MAXN],p[MAXN],mx,cnt;
bool vis[MAXN];
long long k;

inline void dfs(int pos,int x,int n,long long k)
{
	if (pos>n) return ;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			vis[i]=true;
			long long fac=1;int cnt=pos;
			for (int j=1;j<=n;j++)
			{
				if (vis[j]) --cnt;
				else fac*=min(m,n-j+1)-cnt;
			}
			if (fac>=k)
			{
				p[pos+x]=i+x;
				break;
			}
			k-=fac;vis[i]=false;
		}
	dfs(pos+1,x,n,k);
	vis[p[pos+x]-x]=false;
	return ;
}

inline void Solve()
{
	t[0]=0;
	scanf("%d %d %lld",&n,&m,&k);mx=0;cnt=n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),ans[i]=0;
	for (int i=1;i<=n;i++)
	{
		if (mx>a[i]) ans[i+m-1]=a[i],--cnt;
		else mx=a[i],t[++t[0]]=a[i];
	}
	__int128 fac=1;int x=0;
	for (x=1;fac<k;x++) fac*=min(m,x);
	--x;
	for (int i=0;i<=cnt-x;i++) p[i]=i;
	dfs(1,cnt-x,x,k);
	for (int i=1;i<=n;i++)
	{
		if (!ans[i]) ans[i]=t[p[++p[0]]];
		printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}