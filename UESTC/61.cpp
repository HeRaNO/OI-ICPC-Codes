#include <cstdio>

int n, x, ans;
bool f;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		f = false;
		scanf("%d", &x);
		if (x == 1) continue;
		for (int j = 2; j * j <= x && !f; j++)
			if (!(x % j)) f = true;
		if (!f) ++ans;
	}
	printf("%d %d\n", ans, n);
	return 0;
}