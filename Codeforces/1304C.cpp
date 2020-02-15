#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,m,T,t[MAXN],lo[MAXN],hi[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			scanf("%d %d %d",&t[i],&lo[i],&hi[i]);
		bool f=true;int now=0;
		int l=m,r=m,ll=m,lr=m;
		for (int i=1;i<=n&&f;++i)
		{
			l=(ll+t[i]-t[i-1]);r=(lr-(t[i]-t[i-1]));
			if(max(r,lo[i])<=min(l,hi[i]))
			{
				ll=min(l,hi[i]);
				lr=max(r,lo[i]);
			}
			else f=false;
		}
		puts(f?"YES":"NO");
	}
	return 0;
}