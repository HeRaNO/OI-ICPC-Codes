#include <bits/stdc++.h>
using namespace std;

int T;long long n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);long long x=n;printf("%d=",n);bool f=true;
		while (!(x&1))
		{
			if (f){printf("2");f=false;}
			else printf("*2");
			x>>=1;
		}
		for (long long i=3;i*i<=n&&x!=1;i+=2)
		{
			int cnt=0;
			while (!(x%i)) x/=i,++cnt;
			for (int j=1;j<=cnt;j++)
			{
				if (f){printf("%d",i);f=false;}
				else printf("*%d",i);
			}
		}
		if (x!=1)
		{
			if (f){printf("%d\n",x);f=false;}
			else printf("*%d\n",x);
		}
		else puts("");
	}
	return 0;
}
