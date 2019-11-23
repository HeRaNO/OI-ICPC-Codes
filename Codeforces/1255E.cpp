#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,a[MAXN];
long long s,ans=~(1LL<<63);

inline void f(long long i)
{
	long long res=0,cnt=0;
	for (int j=1;j<=n;j++)
	{
		(cnt+=a[j])%=i;
		res+=min(cnt,i-cnt);
	}
	ans=min(ans,res);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
	if (s==1) return puts("-1"),0;
	for (long long i=2,p=s;i*i<=p&&s!=1;i++)
		if (!(s%i))
		{
			f(i);
			while (!(s%i)) s/=i;
		}
	if (s!=1) f(s);
	printf("%lld\n",ans);
	return 0;
}
