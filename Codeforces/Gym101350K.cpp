#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n,cnt[10],ans[10];
long long a,b;

long long f(long long x)
{
	return a*x*x+b*x;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(ans,0,sizeof ans);
		scanf("%lld %lld %d",&a,&b,&n);
		if (a+b>n){puts("-1");continue;}
		for (int x=1;f(x)<=n;x++)
		{
			long long p=f(x);memset(cnt,0,sizeof cnt);
			while (p)
			{
				++cnt[p%10];p/=10;
			}
			int pt=0;
			for (int i=1;i<=9;i++) if (cnt[i]>cnt[pt]) pt=i;
			for (int i=0;i<=9;i++) if (cnt[pt]==cnt[i]) ++ans[i];
		}
		int p=0;
		for (int i=1;i<=9;i++) if (ans[i]>ans[p]) p=i;
		printf("%d\n",p);
	}
	return 0;
}