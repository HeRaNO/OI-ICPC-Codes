#include <bits/stdc++.h>
using namespace std;

int T,n,k,cnt;
long long ans;

inline int ceil(int x)
{
	if (x&1) return (x>>1)+1;
	return x>>1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&k);cnt=1;ans=0LL;
		while (n>1&&cnt<=k)
		{
			n=ceil(n);++cnt;
		}
		printf("%d\n",n);
	}
	return 0;
}