#include <cstdio>
int k, n, ans;
int main()
{
	scanf("%d %d", &k, &n);
	for (int b = 1; n; b *= k, n >>= 1) if (n & 1) ans += b;
	printf("%d\n", ans);
	return 0;
}