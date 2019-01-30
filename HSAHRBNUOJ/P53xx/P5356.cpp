#include <cstdio>
using namespace std;

int a,b,x,y;

int main()
{
	scanf("%d %d",&a,&b);
	if (a%9) return puts("NO"),0;
	x=b-a/9;if (x&1) return puts("NO"),0;x>>=1;
	y=b-x;
	if (x<0||y<0||x>9||y>9) return puts("NO"),0;
	if (x<y) printf("%d%d\n",x,y);
	else printf("%d%d\n",y,x);
	return 0;
}