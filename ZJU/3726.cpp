#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
typedef long long ll;

ll s[MAXN],p[MAXN],c[MAXN];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld%lld",&s[i],&p[i]);
		for(int i=1;i<=n;i++) c[i]=s[i]*p[i];
		for(int i=n-1;i>=1;i--) c[i]=min(c[i],c[i+1]);
		for(int i=1;i<=m;i++)
		{
			ll tempq;
			scanf("%lld",&tempq);
			int tt=lower_bound(s+1,s+1+n,tempq)-s;
			if(tt==n+1) printf("%lld\n",tempq*p[n]);
			else printf("%lld\n",min(c[tt],tempq*p[tt-1]));
		}
	}
	return 0;
}