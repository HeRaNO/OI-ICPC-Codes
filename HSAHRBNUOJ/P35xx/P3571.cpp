#include <cstdio>
#define MOD 10000LL
using namespace std;

long long n, ans, p1, p2, p3;

inline long long KSM(int a, int b)
{
	long long res = 1LL, d = a;
	while (b)
	{
		if (b & 1) res = (res * d) % MOD;
		d = (d * d) % MOD;
		b >>= 1;
	}
	return res;
}

inline long long get_digit_len()
{
	long long a = 1, b = 10, cnt = 1;
	long long res = 0;
	while (b <= n)
	{
		res = (res + (b - a) % MOD * cnt) % MOD;
		cnt++;
		a = b;
		b *= 10;
	}
	b /= 10;
	res = (res + (n + 1 - b) * cnt) % MOD;
	return res;
}

int main()
{
	scanf("%lld", &n);
	p1 = KSM(2, n - 1);
	p2 = (2 * p1) % MOD;
	p3 = get_digit_len();
	n %= MOD;
	printf("%lld\n", ((3 * n - 4) % MOD + p2 + p1 * p3 % MOD + p1 * n + p3) % MOD);
	return 0;
}
