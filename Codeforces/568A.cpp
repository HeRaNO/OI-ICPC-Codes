#include <bits/stdc++.h>
#define MAXN 5000005
using namespace std;

int rub[MAXN],prime[MAXN],pi[MAXN];
bool not_prime[MAXN];
int tot,p,q,mx;

inline void LinearShaker(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i,++pi[i];
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	for (int i=1;i<=n;i++) pi[i]+=pi[i-1];
	return ;
}

inline bool isp(int x)
{
	int rev=0;
	for (int t=x;t;t/=10) rev=rev*10+t%10;
	return x==rev;
}

int main()
{
	int n=5e6;
	LinearShaker(n);
	for (int i=1;i<=n;i++)
	{
		rub[i]=rub[i-1];
		if (isp(i)) ++rub[i];
	}
	scanf("%d %d",&p,&q);
	for (int i=1;i<=n;i++)
		if (1LL*q*pi[i]<=1LL*p*rub[i])
			mx=max(mx,i);
	printf("%d\n",mx);
	return 0;
}