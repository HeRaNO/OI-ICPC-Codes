#include <bits/stdc++.h>
using namespace std;

long long n,f[41];

int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=40;i++) f[i]=3*f[i-1]+1;
	for (int i=1;i<=40;i++) if (n<=f[i]) return printf("%d\n",i),0;
	return 0;
}