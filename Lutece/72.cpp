#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n * (k - 1); i++) putchar('1');
	putchar('\n');
	return 0;
}
