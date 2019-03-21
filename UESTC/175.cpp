#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

long long d[MAXN],ans,x,y;
int n,T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%lld %lld",&x,&y);
			d[i]=x-y;
		}
		sort(d+1,d+n+1);
		for (int i=1;i<=n;i++) ans+=(i-1)*d[i]-(n-i)*d[i];
		printf("%lld\n",ans);
	}
	return 0;
}
