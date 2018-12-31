//Code By HeRaNO
#include <cstdio>
using namespace std;
int d[10001];
int a, b, zhengshu, c, i, pos;
int main()
{
	scanf("%d %d %d", &a, &b, &pos);
	zhengshu = a / b;
	c = a % b;
	for (i = 1; i <= 10000; i++)
	{
		c = c * 10;
		d[i] = c / b;
		c = c % b;
	}
	printf("%d\n", d[pos]);
	return 0;
}
