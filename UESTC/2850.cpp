#include <cstdio>
#include <algorithm>
#define MAXN 100005

int n, mx[MAXN], mn[MAXN];
char a[MAXN];

int main()
{
	scanf("%d", &n);
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++)
	{
		mx[i] = mx[i - 1] + (a[i] == '1' ? 1 : -1);
		mn[i] = mn[i - 1] + (a[i] == '1' ? 1 : -1);
		if (i >= 3)
		{
			mx[i] = std::max(mx[i], mx[i - 3]);
			mn[i] = std::min(mn[i], mn[i - 3]);
		}
	}
	printf("%d\n", std::max(mx[n], -mn[n]));
	return 0;
}