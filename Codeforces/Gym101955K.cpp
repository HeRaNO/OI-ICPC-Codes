#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m,k;

int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;++kase)
	{
		scanf("%lld%lld%lld",&n,&k,&m);
		printf("Case #%d: ",kase);
		if(n==1){puts("1");continue;}
		if(m==1){printf("%lld\n",k);continue;}
		ll sum=n-k+1,ans=(sum+m-1)%sum;
		while(sum<n)
		{
			if(k>m)
			{
				ll tmp=min((sum-ans)/m,n-sum);
				sum+=tmp;
				ans=(ans+tmp*m)%sum;
				if(sum>=n)break;
			}
			sum++;
			ans=(ans+m)%sum;
		}
		ans++;
		printf("%lld\n",ans);
	}
	return 0;
}