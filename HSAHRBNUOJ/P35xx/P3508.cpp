#include <stdio.h>
int n, b;
int main()
{
	scanf("%d %d", &n, &b);
	if (n == 1)
	{
		puts("1");
		return 0;
	}
	if (n - b > b - 1) printf("%d\n", b + 1);
	else printf("%d\n", b - 1);
	return 0;
}
