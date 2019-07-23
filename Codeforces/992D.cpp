#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,pos[MAXN];
long long a[MAXN],ans,k;

int main()
{
	scanf("%d %lld",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	pos[n+1]=n+1;
	for (int i=n;i;i--)
	{
		if (a[i]!=1) pos[i]=i;
		else pos[i]=pos[i+1];
	}
	for (int i=1;i<=n;i++)
	{
		long long p=a[i],s=a[i];
		if (p==s*k) ++ans;
		int j=i;
		while (true)
		{
			int pt=pos[j+1];
			long long _1=pt-j-1;
			if (p%k==0&&p/k>=(s+1)&&p/k<=(s+_1)) ++ans;
			if (pt>n) break;
			if ((double)p*(double)a[pt]>2e18) break;
			j=pt;
			p=p*a[j];s+=a[j]+_1;
			if (p==s*k) ++ans;
		}
	}
	printf("%lld\n",ans);
	return 0;
}