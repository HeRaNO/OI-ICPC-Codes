#include <bits/stdc++.h>
#define MAXN 70000
using namespace std;

int T,l,r;
int prime[MAXN],tot;
bool not_prime[MAXN];

inline void Linear_Shaker(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i]) prime[++tot] = i;
		for (int j = 1; i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j])) break;
		}
	}
	return ;
}

int main()
{
	Linear_Shaker(1<<16);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&l,&r);bool f=true;
		for (int i=1;i<=tot;i++)
			if (l<=prime[i]&&prime[i]<=r)
			{
				if (f){printf("%d",prime[i]);f=false;}
				else printf(" %d",prime[i]);
			}
		puts("");
	}
	return 0;
}