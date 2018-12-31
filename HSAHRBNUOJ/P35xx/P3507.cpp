#include <cstdio>
using namespace std;

long long left, right, middle;
long long n, ans = ~(1LL << 63), res;
long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int check(long long k, int r)
{
	long long cnt = 1, t = 1;
	for (int i = 1; i <= r; i++)
	{
		t *= k;
		cnt += t;
		if (cnt > n) break;
	}
	if (cnt > n) return 0;
	if (cnt == n) return 1;
	return -1;
}

long long binary(int r)
{
	left = -1;
	right = 1LL << 62;
	while (left <= right)
	{
		middle = (left + right) >> 1LL;
		int res = check(middle, r);
		if (!res) right = middle - 1;
		else if (res == 1) return middle;
		else left = middle + 1;
	}
	return -1;
}

int main()
{
	scanf("%lld", &n);
	for (int r = 1; r <= 40; r++)
	{
		res = binary(r);
		if (res != -1)ans = mymin(ans, res * r);
	}
	printf("%lld\n", ans);
	return 0;
}
