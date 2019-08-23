#include <bits/stdc++.h>
using namespace std;

int T,b,p,f,h,c;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int ans=0;
		scanf("%d %d %d",&b,&p,&f);
		scanf("%d %d",&h,&c);
		for (int x=0;x<=p;x++)
			for (int y=0;y<=f;y++)
				if ((x+y)*2<=b)
					ans=max(ans,x*h+y*c);
		printf("%d\n",ans);
	}
	return 0;
}