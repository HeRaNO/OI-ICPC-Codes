#include <bits/stdc++.h>
#define MAXK 65
using namespace std;

int T,n,k,cas;
long long M,_k[MAXK],ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %lld",&n,&k,&M);ans=1;
		if (n<=k)
		{
			for (int i=1;i<=n;i++) (ans*=i)%=M;
		}
		else
		{
			_k[0]=1;
			for (int i=1;i<=n;i++) _k[i]=_k[i-1]*(k+1)%M;
			ans=_k[n-k];
			for (int i=2;i<=n-k;i++)
			{
				ans+=(n-k-i+1)*_k[n-k-1]%M;
				ans%=M;
			}
			for (int i=3;i<=n-k;i++)
			{
				ans+=(n-k-i+1)*_k[n-k-i+1]%M;
				ans%=M;
			}
			for (int i=1;i<=k;i++) (ans*=i)%=M;
		}
		printf("Case #%d: %lld\n",++cas,ans);
	}
	return 0;
}