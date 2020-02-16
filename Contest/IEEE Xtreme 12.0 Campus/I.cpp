#include <cstdio>
#define MAXN 30
using namespace std;

int T,m;
long long ans,a[MAXN],n;

inline long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}

void dfs(int x,int cnt,long long lcm)
{
	if (lcm>n) return ;
	if (x>m)
	{
		if (cnt&1) ans+=n/lcm*(1LL<<(cnt-1));
		else ans-=n/lcm*(1LL<<(cnt-1));
		return ;
	}
	dfs(x+1,cnt,lcm);
	long long t=lcm/gcd(lcm,a[x])*a[x];
	if (t<=n) dfs(x+1,cnt+1,t);
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %d",&n,&m);ans=0;
		for (int i=1;i<=m;i++) scanf("%lld",&a[i]);
		for (int i=1;i<=m;i++) dfs(i+1,1,a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}