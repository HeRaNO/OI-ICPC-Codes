//Code By HeRaNO
#include<cstdio>
using namespace std;
int main()
{
	int x, y, n;
	scanf("%d %d %d", &n, &x, &y);
	if (y % x != 0 && y / x + 1 <= n)
		printf("%d", n - y / x - 1);
	else if (y % x == 0 && y / x <= n)
		printf("%d", n - y / x);
	if (y / x > n)  printf("0");
	return 0;
}