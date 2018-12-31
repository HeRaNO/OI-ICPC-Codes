//Code By HeRaNO
#include<stdio.h>
int x, y, n, ans, i;
int main()
{
	scanf("%d %d %d", &x, &y, &n);
	ans = x + y;
	for (i = 1; i <= n; i++)
		ans = ans * 3 - (x + y);
	printf("%d\n", ans);
	return 0;
}

