#include <stdio.h>

const int M = 10000;

int T, a, b, r;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &a, &b);
		r = 1;
		for (a %= M; b; (a *= a) %= M, b >>= 1) if (b & 1)(r *= a) %= M;
		printf("%04d\n", r);
	}
	return 0;
}