#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

int T,n,x[MAXN],y[MAXN];
long long ans;

inline void Solve()
{
	scanf("%d",&n);ans=0;
	for (int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
	sort(x+1,x+n+1);sort(y+1,y+n+1);
	for (int i=1;i<=n;i++) x[i]=x[i]-i+1;
	sort(x+1,x+n+1);
	for (int i=1;i<=n;i++) ans=ans+abs(x[i]-x[(n>>1)+1])+abs(y[i]-y[(n>>1)+1]);
	printf("%lld\n",ans);
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}