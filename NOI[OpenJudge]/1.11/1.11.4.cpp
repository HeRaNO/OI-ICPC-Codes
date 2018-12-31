//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 10020
using namespace std;

long long n, k, ans;
long long left = 1, right, middle;
double x;
long long a[MAXN];

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

long long check(long long len)
{
	long long cnt = 0;
	for (int i = 1; i <= n; i++) cnt += a[i] / len;
	return cnt;
}

int main()
{
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &x);
		a[i] = (long long)(x * 100);
		right = mymax(right, a[i]);
	}
	sort(a + 1, a + n + 1);
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (check(middle) < k) right = middle - 1;
		else
		{
			ans = middle;
			left = middle + 1;
		}
	}
	printf("%.2lf\n", ans / 100.0);
	return 0;
}
