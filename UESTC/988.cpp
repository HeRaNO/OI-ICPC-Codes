#include <cmath>
#include <cstdio>
using namespace std;

int T,n,x,a,b,c,d;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);a=0;b=0;c=0;d=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if (x<10) ++a;
			else if (x<100) ++b;
			else if (x<1000) ++c;
			else ++d;
		}
		printf("%d %d %d %d\n",a,b,c,d);
	}
	return 0;
}