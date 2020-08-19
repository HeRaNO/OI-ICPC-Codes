#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int ax,ay,bx,by,cx,cy;
		scanf("%d %d",&ax,&ay);
		scanf("%d %d",&bx,&by);
		scanf("%d %d",&cx,&cy);
		long long x=1LL*ax*by-1LL*bx*ay;
		long long y=1LL*bx*cy-1LL*cx*by;
		long long z=1LL*cx*ay-1LL*cy*ax;
		int cnt=(x>0)+(y>0)+(z>0);
		puts(cnt<2?"Clockwise":"Counterclockwise");
	}
	return 0;
}