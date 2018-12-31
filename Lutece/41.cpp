#include <cstdio>

long long d, a, b, k, t, x, y, z;

int main()
{
	scanf("%lld %lld %lld %lld %lld", &d, &k, &a, &b, &t);
	if ((b - a)*k <= t) printf("%lld\n", (a - b)*k + b * d);
	else
	{
		x = (d / k) * t + a * d;
		y = (d / k) * k;
		z = (d / k - 1) * t + (a - b) * y + b * d;
		printf("%lld\n", x < z ? x : z);
	}
	return 0;
}
