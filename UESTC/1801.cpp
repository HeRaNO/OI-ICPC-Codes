#include <cstdio>

int main()
{
	int h, m, ans = 0;
	scanf("%d:%d", &h, &m);
	while (1)
	{
		if ((h % 10 == m / 10) && (h / 10 == m % 10))
		{
			printf("%d\n", ans);
			return 0;
		}
		++m;
		++ans;
		if (m == 60)
		{
			m = 0;
			++h;
		}
		if (h == 24) h = 0;
	}
	return 0;
}