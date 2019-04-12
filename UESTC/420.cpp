#include <cstdio>

const int M=10007;

int T,n,f[100010];

int main()
{
	f[0]=1;f[1]=2;
	for (int i=2;i<=100000;i++) f[i]=(f[i-1]+f[i-2])%M;
	while (~scanf("%d",&n)) printf("%d\n",f[n]);
	return 0;
}
