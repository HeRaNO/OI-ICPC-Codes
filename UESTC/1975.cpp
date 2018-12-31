#include <stdio.h>
#include <string.h>

int p[200010], a[200010], T, n, pt, R, ans;

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}
inline int min(int a, int b)
{
	return a < b ? a : b;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		memset(p, 0, sizeof p);
		a[1] = -1;
		pt = 0;
		R = 0;
		ans = 0;
		read(n);
		for (int i = 1; i <= n; i++)
		{
			read(a[i << 1]);
			a[i << 1 | 1] = -1;
		}
		n = n << 1 | 1;
		for (int i = 1; i <= n; i++)
		{
			if (i < R) p[i] = min(p[(pt << 1) - i], R - i);
			else p[i] = 1;
			while (1 <= i - p[i] && i + p[i] <= n && a[i - p[i]] == a[i + p[i]]) ++p[i];
			if (i + p[i] > R)
			{
				pt = i;
				R = i + p[i];
			}
		}
		for (int i = 1; i <= n; i++) max(ans, p[i] - 1);
		printf("%d\n", ans);
	}
	return 0;
}