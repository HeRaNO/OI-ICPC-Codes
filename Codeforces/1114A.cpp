#include <cstdio>
using namespace std;

int x,y,z,a,b,c;

int main()
{
	scanf("%d %d %d",&x,&y,&z);
	scanf("%d %d %d",&a,&b,&c);
	if (x>a) return puts("NO"),0;
	a-=x;
	if (y>a+b) return puts("NO"),0;
	if (a+b+c>=y+z) puts("YES");
	else puts("NO");
	return 0;
}
