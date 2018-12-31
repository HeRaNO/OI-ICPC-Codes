#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, ans = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (b >= a + 1 && c >= a + 2) ans = max(ans, a + a + 1 + a + 2);
	if (a >= b - 1 && c >= b + 1) ans = max(ans, b - 1 + b + b + 1);
	if (a >= c - 2 && b >= c - 1) ans = max(ans, c - 2 + c - 1 + c);
	printf("%d\n", ans);
	return 0;
}