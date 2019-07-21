#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,M,a[MAXN],l,r,ans;

inline bool check(int x)
{
	int p=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<=p) ++p;
		else if (x){--x;++p;}
	}
	return p>=M;
}

int main()
{
	scanf("%d %d",&n,&M);l=0;r=n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	while (l<=r)
	{
		int m=l+r>>1;
		if (check(m)){ans=m;r=m-1;}
		else l=m+1;
	}
	printf("%d\n",ans);
	return 0;
}