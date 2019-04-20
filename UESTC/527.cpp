#include <cstdio>
#include <algorithm>
using namespace std;

int T,n,a[1000000];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}