#include <cstdio>
#include <algorithm>
#define MAXN 25
using namespace std;

int T,n,m,a[MAXN];

int main()
{
	scanf("%d %d",&n,&T);
	for (int i=0;i<n;i++) a[i]=i;
	while (T--)
	{
		scanf("%d",&m);m%=n;
		if (!m) m=0;
		else m=n-m;
		bool f=true;
		for (int i=m,cnt=1;cnt<=n;cnt++,i=(i+1)%n)
		{
			if (f){printf("%d",a[i]+1);f=false;}
			else printf(" %d",a[i]+1);
		}
		puts("");
	}
	return 0;
}
