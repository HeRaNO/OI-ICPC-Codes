#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n,pt;
long long x,y,k,mx,mxx,mxy,ans;
char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %lld",&n,&k);x=0;y=0;mxx=0;mxy=0;mx=-1;ans=0;
		scanf("%s",s);
		for (int i=0;i<n;i++)
		{
			if (s[i]=='U') ++y;
			if (s[i]=='D') --y;
			if (s[i]=='L') --x;
			if (s[i]=='R') ++x;
			ans=max(ans,abs(x)+abs(y));
		}
		x=(k-1)*x;y=(k-1)*y;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='U') ++y;
			if (s[i]=='D') --y;
			if (s[i]=='L') --x;
			if (s[i]=='R') ++x;
			ans=max(ans,abs(x)+abs(y));
		}
		printf("%lld\n",ans);
	}
	return 0;
}