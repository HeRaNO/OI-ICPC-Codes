#include <cstdio>
#define MAXN 100010
#define logK 41
using namespace std;

int n, T, a[MAXN], mx, mn;
long double f[logK], k;

inline int read()
{
	int x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	T = read();
	while (T--)
	{
		mx = mn = a[1];
		f[0] = read();
		f[1] = read();
		k = read();
		if (f[0] == 0 && f[1] == 0)
		{
			printf("%d %d\n", mx, mn);
			continue;
		}
		for (int i = 2; i <= 40; i++) f[i] = k * f[i - 1] + f[i - 2];
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > 40)
			{
				if (f[40] > 0) mx = a[n];
				else mn = a[n];
				break;
			}
			if (f[mx] < f[a[i]]) mx = a[i];
			if (f[mn] > f[a[i]]) mn = a[i];
		}
		printf("%d %d\n", mx, mn);
	}
	return 0;
}