#include <stdio.h>

inline void min(int &a, int b)
{
	if (a > b) a = b;
	return ;
}

int n, k, ans = ~(1 << 31), p[15];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		if ((9 * i * k) % 10 >= 5) p[i] = (9 * i * k) / 10 + 1;
		else p[i] = (9 * i * k) / 10;
	}
	for (int sta = 0; sta < (1 << (n - 1)); sta++)
	{
		int now = 0, x = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (sta & (1 << i))
			{
				now += p[x];
				x = 1;
			}
			else ++x;
		}
		if (x) now += p[x];
		min(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}