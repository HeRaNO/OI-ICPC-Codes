#include <bits/stdc++.h>
#define MAXN 31
using namespace std;

int n,a[MAXN],ans[MAXN],p;

bool dfs(int x,long long sta)
{
	if (x==p)
	{
		for (int i=1;i<x;i++)
		{
			int np=ans[x]-ans[i];
			int pos=lower_bound(a,a+n,np)-a;
			if (a[pos]==np) sta|=(1LL<<pos);
		}
		return sta==(1LL<<n)-1;
	}
	for (int i=1;i<x;i++)
		for (int j=0;j<n-1;j++)
		{
			if (sta&(1LL<<j)) continue;
			if (ans[i]+a[j]<=ans[x-1]||ans[i]+a[j]>=a[n-1]) continue;
			ans[x]=ans[i]+a[j];
			int nxt=sta;
			for (int k=1;k<x;k++)
			{
				int np=ans[x]-ans[k];
				int pos=lower_bound(a,a+n,np)-a;
				if (a[pos]==np) nxt|=(1LL<<pos);
			}
			if (dfs(x+1,nxt)) return true;
		}
	return false;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	if (n==1) return printf("2\n0 %d\n",a[0]),0;
	sort(a,a+n);n=unique(a,a+n)-a;
	for (p=3;p<=n+1;p++)
	{
		memset(ans,0,sizeof ans);ans[p]=a[n-1];
		if (dfs(2,1LL<<(n-1)))
		{
			printf("%d\n",p);
			for (int j=1;j<=p;j++) printf("%d%c",ans[j],j==p?'\n':' ');
			return 0;
		}
	}
	return 0;
}