#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

int n, m;
long long s;
int v[MAXN], w[MAXN];
long long maxw;
long long qian[MAXN], num[MAXN];
int l[MAXN], r[MAXN];

long long myabs(long long a)
{
	return a < 0 ? -a : a;
}

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

long long check(long long cs)
{
	long long y = 0;
	for (int i = 1; i <= n; i++)
	{
		if (w[i] >= cs)
		{
			qian[i] = qian[i - 1] + v[i];
			num[i] = num[i - 1] + 1;
		}
		else
		{
			qian[i] = qian[i - 1];
			num[i] = num[i - 1];
		}
	}
	for (int i = 1; i <= m; i++)
		y += (qian[r[i]] - qian[l[i] - 1]) * (num[r[i]] - num[l[i] - 1]);
	return s - y;
}

long long binary()
{
	int left = -1, right = 1e5, middle;
	while (left + 1 != right)
	{
		middle = (left + right) >> 1;
		if (check(middle) <= 0) left = middle;
		else right = middle;
	}
	long long ans = mymin(mymin(myabs(check(left - 1)), check(left + 1)), mymin(myabs(check(left)), myabs(check(right))));
	ans = mymin(mymin(ans, myabs(check(right - 1))), mymin(myabs(check(right + 1)), myabs(check(left))));
	return ans;
}

int main()
{
	scanf("%d %d %lld", &n, &m, &s);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &w[i], &v[i]);
		maxw = mymax(maxw, w[i]);
	}
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &l[i], &r[i]);
	printf("%lld\n", binary());
	return 0;
}
