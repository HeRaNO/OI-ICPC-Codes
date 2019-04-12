#include <bits/stdc++.h>
using namespace std;

int T,n;
unsigned long long f[45];

int main()
{
	f[0]=f[1]=1LU;
	for (int i=2;i<=41;i++) f[i]=f[i-1]+f[i-2];
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		printf("%llu %llu\n",f[n],f[n+1]);
	}
	return 0;
}
