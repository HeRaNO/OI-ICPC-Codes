#include <cmath>
#include <cstdio>
using namespace std;

int x,y;

int main()
{
	scanf("%d %d",&x,&y);
	if (fabs(y*log(x)-x*log(y))<1e-6) return puts("="),0;
	if (y*log(x)>x*log(y)) puts(">");
	else puts("<");
	return 0;
}