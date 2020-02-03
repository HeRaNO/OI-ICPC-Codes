#include <cstdio>
using namespace std;

long long n, m, k, x;

long long quick_mod(long long a, long long b, long long m)
{
	long long d, t;
	d = 1;
	t = a;
	while (b)
	{
		if (b % 2) d = (d * t) % m;
		b /= 2;
		t = (t * t) % m;
	}
	return d;
}

int main()
{
	scanf("%lld %lld %lld %lld", &n, &m, &k, &x);
	long long res = quick_mod(10, k, n);
	res = (res * m + x) % n;
	printf("%lld\n", res);
	return 0;
}
