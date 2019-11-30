#include <bits/stdc++.h>
using namespace std;

const int Z1=10100;
const int Z2=100;

int n,a,b,x,vx,vy;
int cnt[Z1<<1|1],s[Z1<<1|1][Z2<<1|1];
long long ans;

int main()
{
	scanf("%d %d %d",&n,&a,&b);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&vx,&vy);
		ans+=cnt[a*vx-vy+Z1]-s[a*vx-vy+Z1][vx+Z2];
		++cnt[a*vx-vy+Z1];
		++s[a*vx-vy+Z1][vx+Z2];
	}
	printf("%lld\n",ans<<1);
	return 0;
}