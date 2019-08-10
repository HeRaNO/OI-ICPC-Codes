#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int T,n;
char s[MAXN];

long long f(long long a,long long b){return a+b!=0;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int x=0,y=0;
		int mnx=0,mxx=0;
		int mny=0,mxy=0;
		int mxl=0,mxr=0,mxu=0,mxd=0;
		scanf("%s",s);n=strlen(s);
		for (int i=0;i<n;i++)
		{
			if (s[i]=='W') ++y;
			if (s[i]=='S') --y;
			if (s[i]=='A') --x;
			if (s[i]=='D') ++x;
			mxx=max(mxx,x);mnx=min(mnx,x);
			mxy=max(mxy,y);mny=min(mny,y);
			mxu=max(mxu,y-mny);mxd=max(mxd,mxy-y);
			mxl=max(mxl,mxx-x);mxr=max(mxr,x-mnx);
		}
		long long a=max(mxl,mxr);
		long long b=max(f(mxl,mxr),a-(mxl!=mxr));
		long long c=max(mxu,mxd);
		long long d=max(f(mxu,mxd),c-(mxu!=mxd));
		++a;++b;++c;++d;
		printf("%lld\n",min(a*d,b*c));
	}
	return 0;
}