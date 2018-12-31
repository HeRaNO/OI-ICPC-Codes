#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct point
{
	long long p, w;
	bool operator < (const point &a)const
	{
		return p < a.p;
	}
};

point x[MAXN], y[MAXN];
long long w[MAXN], sx, sy, sum, ans, ax, ay;
int n;

inline long long myabs(long long a)
{
	return a > 0 ? a : -a;
}

inline int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return x;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		w[i] = read();
		sum += w[i];
		x[i].w = y[i].w = w[i];
	}
	sum >>= 1LL;
	for (int i = 1; i <= n; i++) x[i].p = read(), y[i].p = read();
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (!ax)
		{
			sx += x[i].w;
			if (sx >= sum) ax = x[i].p;
		}
		if (!ay)
		{
			sy += y[i].w;
			if (sy >= sum) ay = y[i].p;
		}
		if (ax && ay) break;
	}
	for (int i = 1; i <= n; i++)
		ans += x[i].w * myabs(x[i].p - ax) + y[i].w * myabs(y[i].p - ay);
	printf("%lld\n", ans);
	return 0;
}