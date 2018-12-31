#include <cstdio>
#define MAXN 1000

int ans[MAXN];
int cnt;

int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		if (i % 3 == 0 && ((i % 10 == 5) || (i / 10) % 10 == 5 || (i / 100) % 10 == 5))
			ans[++cnt] = i;
	if (!cnt) return 0;
	for (int i = 1; i < cnt; i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[cnt]);
	return 0;
}
