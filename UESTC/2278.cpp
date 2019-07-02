#include <bits/stdc++.h>
#define MAXN 10000010
using namespace std;

const long long M=1e9+7;

long long sphi,ans;
bool not_prime[MAXN];
int n,tot,mu[MAXN],prime[664580];

void Linear_Shaker()
{
	mu[1]=1LL;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i])
		{
			mu[i]=-1;prime[++tot]=i;
		}
		for (int j=1;i*prime[j]<=n&&j<=tot;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j]))
			{
				mu[i*prime[j]]=0LL;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
	}
	return ;
}

int main()
{
	scanf("%d",&n);
	if (!n) return puts("1"),0;
	Linear_Shaker();
	for (int i=1;i<=n;i++) printf("%d ",mu[i]);puts("");
	for (int i=1;i<=n;i++)
	{
		long long p=n/i;
		(p*=p)%=M;
		sphi=(sphi+p*mu[i]+M)%M;
		p=(p*1LL*(n/i))%M;
		ans=(ans+p*mu[i]+M)%M;
	}
	printf("%lld\n",(8*ans%M+12*sphi%M+7)%M);
	return 0;
}