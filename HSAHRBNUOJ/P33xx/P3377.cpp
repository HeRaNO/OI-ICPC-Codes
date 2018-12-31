#include <stdio.h>
int n, x;
int main()
{
	scanf("%d %d", &n, &x);
	printf("%d %d\n", (n - x) / 2, (n + x) / 2);
	return 0;
}
