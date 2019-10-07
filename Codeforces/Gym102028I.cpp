#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int n;
ll pos[N];

int main()
{
	int Test;scanf("%d",&Test);
	while(Test--)
	{
		pos[1]=0;
		scanf("%d",&n);
		for(int i=2;i<=n;++i)
		{
			ll a;scanf("%lld",&a);
			pos[i]=pos[i-1]+a;
		}
		int L=0,R=n+1;
		ll tmp=0,ans=0;
		for(int k=1;k<=n;++k)
		{
			if(k&1)
			{
				ans+=tmp;
				L++;
			}
			else
			{
				R--;
				tmp+=pos[R]-pos[L];
				ans+=tmp;
			}
			printf("%lld%c",ans,k!=n?' ':'\n');
		}
	}
	return 0;
}