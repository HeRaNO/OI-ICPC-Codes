#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n;
long long a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int ans=0;
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for (int i=1,j=n;i<=j;)
		{
			if (a[i]==a[j]){++i;--j;}
			else if (a[i]>a[j])
			{
				a[j-1]+=a[j];j--;++ans;
			}
			else
			{
				a[i+1]+=a[i];i++;++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}