#include <bits/stdc++.h>
using namespace std;

const long long M=1e9+7;
const long long inv24=41666667LL;

int T;
long long n,ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);
		ans=n;
		(ans*=(n+1))%=M;
		(ans*=(n+2))%=M;
		(ans*=(n+3))%=M;
		(ans*=inv24)%=M;
		printf("%lld\n",ans);
	}
	return 0;
}