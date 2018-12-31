#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if ((((n << 2) - m) & 1) && ((m - (n << 1)) & 1)) puts("NO");
	else printf("%d %d\n", ((n << 2) - m) >> 1, (m - (n << 1)) >> 1);
	return 0;
}