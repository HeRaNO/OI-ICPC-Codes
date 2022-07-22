#include <cstdio>

const int M = 1'000'003;

int main()
{
	int n;
	scanf("%d", &n);
	if (n >= M) return puts("0"), 0;
	int ans = 1;
	for (int i = 1; i <= n; i++)
		ans = 1LL * ans * i % M;
	printf("%d\n", ans);
	return 0;
}