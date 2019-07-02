#include <bits/stdc++.h>
#define MAXN 10000010
using namespace std;

long long phi[MAXN],s[MAXN],ans;
bool not_prime[MAXN];
int T,n,tot,prime[664580];

void Linear_Shaker()
{
	phi[1]=1LL;
	for (int i=2;i<=10000000;i++)
	{
		if (!not_prime[i])
		{
			phi[i]=i-1;prime[++tot]=i;
		}
		for (int j=1;i*prime[j]<=10000000;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j]))
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	for (int i=1;i<=10000000;i++) s[i]=s[i-1]+phi[i];
	return ;
}

int main()
{
	Linear_Shaker();
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=0;
		for (int i=1,j;i<=n;i=j+1)
		{
			j=n/(n/i);
			ans=ans+s[n/i]*(s[j]-s[i-1]);
		}
		printf("%lld\n",ans*2-s[n]);
	}
	return 0;
}