#include <bits/stdc++.h>
using namespace std;

int T,l,r,cnt,ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&l,&r);ans=0;
		while (l<r)
		{
			if (3*l<=r){ans+=l;l=3*l+1;}
			else{ans+=(r-l)>>1;break;}
		}
		printf("Case #%d: %d\n",++cnt,ans);
	}
	return 0;
}
