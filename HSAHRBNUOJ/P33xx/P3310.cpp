#include <cstdio>
#define MAXN 100010
using namespace std;

int n, m;
long long a[MAXN], b[MAXN];

inline long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

bool check(long long limit)
{
	for (int i = 1, j = 1; i <= n; i++)
	{
		if (a[i] - b[j] > limit) return false;
		long long reach;
		if (b[j] < a[i])
		{
			long long rest = limit - a[i] + b[j];
			reach = mymax(b[j] + rest, a[i] + rest / 2LL);
			reach = mymax(reach, a[i]);
		}
		else reach = a[i] + limit;
		while (j <= m && b[j] <= reach) j++;
		if (j > m) return true;
	}
	return false;
}

long long binary()
{
	long long left = 0, right = 1LL << 60, middle;
	while (left < right)
	{
		middle = (left + right) >> 1LL;
		if (check(middle)) right = middle;
		else left = middle + 1;
	}
	return left;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	printf("%lld\n", binary());
	return 0;
}
