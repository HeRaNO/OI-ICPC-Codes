#include <bits/stdc++.h>
using namespace std;

int T,n,cnt;
int x,y,l,r,a,b;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d %d",&x,&y,&l,&r,&n);cnt=0;
		int p=max(0,l-r),q=l+r;p*=p;q*=q;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			if ((x-a)*(x-a)+(y-b)*(y-b)<p) continue;
			if ((x-a)*(x-a)+(y-b)*(y-b)<=q) ++cnt;
		}
		if (cnt==n) puts("Oh yeah!");
		else if (cnt) printf("%d\n",cnt);
		else puts("Mom,I cannot touch it...555");
	}
	return 0;
}
