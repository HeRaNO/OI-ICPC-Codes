#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,x,cas;
double p,f[MAXN],ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %lf %d",&n,&p,&x);
		for (int i=1;i<=n;i++) f[i]=(f[i-1]+1)/(1-p);
		ans=f[n]+x;
		for (int i=2;i<=n;i++) ans=min(ans,i*x+(n%i)*f[n/i+1]+(i-n%i)*f[n/i]);
		printf("Case #%d: %lf\n",++cas,ans);
	}
	return 0;
}