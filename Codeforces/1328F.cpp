#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,k,a[MAXN],scnt;
long long s[MAXN],ans=~(1LL<<63);
map <int,int> mp;

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		mp[a[i]]++;
		s[i]=s[i-1]+a[i];
	}
	for (auto i:mp)
	{
		int x=i.first,cnt=i.second;
		if (cnt>=k) return puts("0"),0;
		int l=k-cnt;
		long long f1=1LL*(x-1)*scnt-s[scnt];
		long long f2=(s[n]-s[scnt+cnt])-1LL*(x+1)*(n-scnt-cnt);
		if (scnt>=l) ans=min(ans,f1+l);
		if (n-scnt-cnt>=l) ans=min(ans,f2+l);
		ans=min(ans,l+f1+f2);scnt+=cnt;
	}
	printf("%lld\n",ans);
	return 0;
}