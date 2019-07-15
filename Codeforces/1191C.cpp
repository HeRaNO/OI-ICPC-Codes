#include <bits/stdc++.h>
#define MAXM 100010
using namespace std;

long long n,a[MAXM],k;
int m,cnt=1,del,ans;

int main()
{
	scanf("%lld %d %lld",&n,&m,&k);
	for (int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for (int i=1;i<m;i++)
	{
		if ((a[i]-del-1)/k==(a[i+1]-del-1)/k) ++cnt;
		else
		{
			del+=cnt;
			++ans;cnt=1;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}