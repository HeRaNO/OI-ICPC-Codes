//Code By HeRaNO
#include <cstdio>
using namespace std;
int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	if (x >= -1 && x <= 1 && y >= -1 && y <= 1) printf("yes");
	else printf("no");
	return 0;
}