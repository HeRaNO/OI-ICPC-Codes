#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,M;
long long a[MAXN],b[MAXN],ans;

int main()
{
	while (scanf("%d %d %d",&n,&m,&M)==3)
	{
		ans=1;
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			++b[1];--b[a[i]+1];
		}
		for (int i=1;i<=m;i++) b[i]+=b[i-1];
		sort(a+1,a+n+1,greater<int>());
		sort(b+1,b+m+1,greater<int>());
		for (int i=2;i<=n;i++) (ans*=a[i])%=M;
		for (int i=2;i<=m;i++) (ans*=b[i])%=M;
		printf("%lld\n",ans);
		for (int i=1;i<=m+1;i++) b[i]=0;
	}
	return 0;
}