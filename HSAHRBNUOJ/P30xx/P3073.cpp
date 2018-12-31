#include <stdio.h>
int main()
{
	int x[32], cnt = 0, n, i;
	scanf("%d", &n);
	if (!n)
	{
		puts("0");
		return 0;
	}
	for (; n; x[++cnt] = n & 1, n >>= 1);
	for (i = cnt; i; i--) putchar(x[i] + '0');
	putchar('\n');
	return 0;
}