#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

int n,prime[MAXN],mn[MAXN],tot;
bool not_prime[MAXN],f[MAXN];

inline void LinearShaker(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			mn[i*prime[j]]=prime[j];
			if (!(i%prime[j])) break;
		}
	}
	return ;
}

int main()
{
	scanf("%d",&n);
	LinearShaker(n);
	putchar('1');
	for (int i=1;i<tot;i++) printf(" 1");
	for (int i=2;i<=n;i++)
	{
		if (!mn[i]) mn[i]=i;
		for (int j=1;prime[j]<=i&&i*prime[j]<=n&&prime[j]<=mn[i];j++)
			if (!f[i*prime[j]])
			{
				f[i*prime[j]]=true;
				printf(" %d",i);
			}
	}
	puts("");
	return 0;
}