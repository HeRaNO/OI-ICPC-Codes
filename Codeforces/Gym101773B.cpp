#include <bits/stdc++.h>
using namespace std;

const int MAXN=100050;

int n;
long long a[MAXN],b[MAXN];
long long cnt[MAXN],ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)
		if(a[i]==0&&a[i-1]!=0)
			return puts("-1"),0;
	for(int i=2;i<=n;++i)
	{
		if(a[i]>a[i-1])
		{
			if(a[i-1]>0)
			{
				while(a[i-1]*2<=a[i])
				{
					a[i-1]<<=1;
					cnt[i]--;
				}
			}
		}
		else
		{
			ll tmp=a[i];
			while(tmp<a[i-1])
			{
				tmp<<=1;
				cnt[i]++;
			}
		}
		cnt[i]=max(0LL,cnt[i]+cnt[i-1]);
		ans+=cnt[i];
	}
	printf("%lld\n",ans);
	return 0;
}