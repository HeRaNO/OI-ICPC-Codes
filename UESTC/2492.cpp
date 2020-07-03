#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

inline int mu(long long x)
{
	int r=1;
	for (int i=2;1LL*i*i<=x;i++)
		if (!(x%i))
		{
			r=-r;x/=i;
			if (!(x%i)) return 0;
		}
	if (x!=1) r=-r;
	return r;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);
		printf("%d\n",mu(n));
	}
	return 0;
}