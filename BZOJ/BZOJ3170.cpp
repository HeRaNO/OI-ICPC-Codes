#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct point
{
	long long x;
	long long y;
};

long long x[MAXN], y[MAXN];
point p[MAXN];
int n;
long long sum_x[MAXN], sum_y[MAXN];
int pos;
long long ans = 9223372036854775807;

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		x[i] = p[i].x = a + b;
		y[i] = p[i].y = a - b;
	}
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum_x[i] = sum_x[i - 1] + x[i];
		sum_y[i] = sum_y[i - 1] + y[i];
	}
	for (int i = 1; i <= n; i++)
	{
		long long tmp = 0;
		pos = lower_bound(x + 1, x + n + 1, p[i].x) - x;
		tmp += (p[i].x * pos - sum_x[pos]) + ((sum_x[n] - sum_x[pos]) - p[i].x * (n - pos));
		pos = lower_bound(y + 1, y + n + 1, p[i].y) - y;
		tmp += (p[i].y * pos - sum_y[pos]) + ((sum_y[n] - sum_y[pos]) - p[i].y * (n - pos));
		ans = mymin(ans, tmp);
	}
	printf("%lld", ans / 2);
	return 0;
}