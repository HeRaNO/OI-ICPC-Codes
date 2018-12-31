#include <cstdio>

int main()
{
	int n, L = 0;
	scanf("%d", &n);
	for (int x = n; x; x >>= 1) ++L;
	printf("%d\n", (1 << L) - 1);
	printf("%d", (1 << L) - 1 - n);
	for (int i = 0; i < n; i++)
		if (i != (1 << L) - 1 - n)
			printf(" %d", i);
	printf(" %d\n", n);
	return 0;
}
