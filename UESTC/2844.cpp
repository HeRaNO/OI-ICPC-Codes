#include <cstdio>

int main()
{
	unsigned long long l, r;
	scanf("%llu %llu", &l, &r);
	if (l == r) return printf("%llu\n", l), 0;
	printf("%llu\n", l | ((1LL << (64 - __builtin_clzll(l ^ r))) - 1));
	return 0;
}