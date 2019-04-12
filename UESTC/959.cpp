#include <bits/stdc++.h>
using namespace std;

int n;long long a[40];

int main()
{
	scanf("%d",&n);a[1]=1LL;
	for (int i=2;i<=n;i++) a[i]=(a[i-1]+1LL)*3LL;
	for (int i=n;i;i--) printf("%lld%c",a[i],i==1?'\n':' ');
	return 0;
}
