#include <cstdio>
using namespace std;

long long n,b;int c;
long long cnt[1000010],p[1000010];

int main()
{
	scanf("%I64d %I64d",&n,&b);
	for (long long i=2,x=b;i*i<=x;i++)
		if (!(b%i))
		{
			p[++c]=i;
			while (!(b%i)) ++cnt[c],b/=i;
		}
	if (b>1)
	{
		p[++c]=b;cnt[c]=1;
	}
	long long ans=~(1LL<<63);
	for (int i=1;i<=c;i++)
	{
		long long t=0,l=n;
		while (l) t+=l/=p[i];
		t/=cnt[i];
		if (t<ans) ans=t;
	}
	printf("%I64d\n",ans);
	return 0;
}
