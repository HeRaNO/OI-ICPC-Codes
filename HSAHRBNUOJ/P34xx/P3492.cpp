#include <cstdio>
#define MAXN 100010
#define INT_MAX 2147483647
using namespace std;

int d[MAXN], h[MAXN];
int n, m, ans, t, x, tt;
int left, right, middle;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int myabs(int a)
{
	return a < 0 ? -a : a;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &d[i], &h[i]);
		if (i == 1) ans = d[i] + h[i] - 1;
		else
		{
			t = d[i] - d[i - 1];
			x = h[i] - h[i - 1];
			x = myabs(x);
			tt = 0;
			if (x > t)
			{
				puts("IMPOSSIBLE");
				return 0;
			}
			left = 0;
			right = INT_MAX;
			ans = mymax(ans, mymax(h[i], h[i - 1]));
			while (left <= right)
			{
				middle = (left + right) >> 1;
				if (middle + myabs(middle - x) <= t)
				{
					tt = middle;
					left = middle + 1;
				}
				else right = middle - 1;
			}
			ans = mymax(ans, mymin(h[i], h[i - 1]) + tt);
		}
		if (i == m) ans = mymax(ans, h[i] - d[i] + n);
	}
	printf("%d\n", ans);
	return 0;
}
