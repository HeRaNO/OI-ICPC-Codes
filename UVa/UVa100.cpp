#include <bits/stdc++.h>
using namespace std;

inline int calc(unsigned x)
{
	int ans=1;
	for (;x!=1;x&1?++(x*=3):x>>=1) ++ans;
	return ans;
}

int main()
{
	int a,b;
	while (scanf("%d %d",&a,&b)==2)
	{
		int l=min(a,b),r=max(a,b);
		int mx=0;
		for (int i=l;i<=r;i++) mx=max(mx,calc(i));
		printf("%d %d %d\n",a,b,mx);
	}
	return 0;
}