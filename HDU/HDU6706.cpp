//ans = 1/2 \sum_{i=1}^n i*phi(i)
#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

const int mx=1e6;
const long long M=1e9+7;
const long long inv2=(M+1)>>1;
const long long inv3=(M+1)/3;
const long long inv6=inv2*inv3%M;

int T,n,a,b;
long long prime[MAXN],tot,phi[MAXN];
bool not_prime[MAXN];
map<int,long long> mp;

inline void LinearShaker(int n)
{
	phi[1] = 1LL;
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i])
		{
			prime[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j]))
			{
				phi[i * prime[j]] = phi[i] * prime[j] % M;
				break;
			}
			phi[i * prime[j]] = 1LL * phi[i] * (prime[j] - 1) % M;
		}
	}
	for(long long i=1;i<=n;i++) phi[i]=(phi[i-1]+1LL*phi[i]*i%M)%M;
	return ;
}

long long Work(long long n)
{
	if (n<mx) return phi[n];
	if (mp[n]) return mp[n];
	long long ans1=n*(n+1)%M*(n<<1|1)%M*inv6%M,ans=0;
	for (long long i=2,j;i<=n;i=j+1)
	{
		j=n/(n/i);
		long long sumi=((i+j)*(j-i+1)/2)%M;
		ans=(ans+Work(n/i)%M*sumi)%M;
	}
	ans=(ans1-ans+M)%M;
	return mp[n]=ans;
}

int main()
{
	LinearShaker(mx);
	scanf("%d",&T);
	while (T--)
	{
		mp.clear();
		scanf("%d %d %d",&n,&a,&b);
		printf("%lld\n",(Work(n)-1+M)%M*inv2%M);
	}
	return 0;
}