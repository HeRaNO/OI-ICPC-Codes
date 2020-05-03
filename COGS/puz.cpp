#include <cstdio>
using namespace std;

long long f[100];
long long k;

int main()
{
	freopen("puz.in","r",stdin);freopen("puz.out","w",stdout);
	scanf("%lld",&k);
	f[1]=f[2]=1LL;
	for (int i=3;i<=90;i++) f[i]=f[i-1]+f[i-2];
	for (int i=1;;i++)
	{
		if (f[i]>=k)
		{
			if (f[i]==k) printf("%lld %lld\n",f[i],f[i-1]);
			else printf("%lld %lld\n",f[i-1],f[i-2]);
			return 0;
		}
	}
}