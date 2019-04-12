#include <cstdio>
using namespace std;

int T,h,m,sh,sm,res;

inline int abs(int x){return x<0?-x:x;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d:%d",&h,&m);
		if (h>=12) h-=12;
		sh=h*60+m;sm=m*12;
		res=abs(sh-sm);if (res>360) res=720-res;
		if (res&1) printf("%d/2\n",res);
		else printf("%d\n",res>>1);
	}
	return 0;
}
