#include <bits/stdc++.h>
#define MAXN 40005
using namespace std;

int T,n,prime[MAXN],tot,pfcnt;
bool not_prime[MAXN];
long long pf[MAXN];

inline void LinearShaker(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	return ;
}

void pfact(int n)
{
	pfcnt=0;
	for (int i=1;1LL*prime[i]*prime[i]<=n;i++)
	{
		if (n%prime[i]) continue;
		pf[++pfcnt]=prime[i];
		while (!(n%prime[i])) n/=prime[i];
	}
	if (n!=1) pf[++pfcnt]=n;
	return ;
}

int main()
{
	LinearShaker(40000);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		pfact(n);
		long long G=n,L=1;
		for (int i=1;i<=pfcnt;i++)
		{
			G=G*(pf[i]-1)/pf[i];
			L=L*(1-pf[i]);
		}
		L=L*n+n;
		bool f=(L%2!=0);
		bool neg=(L<0);
		L=neg?-L/2:L/2;
		printf("%lld.000 ",G);
		if (neg) putchar('-');
		printf("%lld%s",L,f?".500\n":".000\n");
	}
	return 0;
}