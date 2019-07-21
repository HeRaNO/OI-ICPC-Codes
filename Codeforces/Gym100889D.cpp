#include <bits/stdc++.h>
#define MAXN 2000010
using namespace std;

const long long M=1e9+7;

int T,n,m,prime[MAXN],tot;
long long fac[MAXN],inv[MAXN],invfac[MAXN];
bool not_prime[MAXN];

inline void Sieve()
{
	int n=2e6;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	fac[0]=invfac[0]=inv[1]=1LL;
	for (int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%M;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) invfac[i]=(invfac[i-1]*inv[i])%M;
	return ;
}

inline long long C(int n,int m)
{
	if (n>=M) return 0LL;
	if (!m) return 1LL;
	long long ans=invfac[m];
	for (int i=n;i>n-m;i--) ans=(ans*i)%M;
	return ans;
}

int main()
{
	Sieve();not_prime[1]=true;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);int pt=1;long long ans=1;
		while (n!=1)
		{
			int cnt=0;
			while (!(n%prime[pt])) n/=prime[pt],++cnt;
			(ans*=C(m+cnt-1,cnt))%=M;
			if (!not_prime[n])
			{
				(ans*=m)%=M;
				break;
			}
			++pt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}