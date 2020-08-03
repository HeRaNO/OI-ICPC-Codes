#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-7;
const long double s2 = sqrt(2);
const long double G = 6.67430*1e-11;

int a, b, d, t0;

inline long double f(long double x)
{
	long double p = 3 * d * sqrt(d) * asin(sqrt(x / d)) / (2 * x * sqrt(x)) - 3 * sqrt(d * (d - x)) / (2 * x);
	p = p * 2 * x * sqrt(1 - x / d);
	long double q = 3 * (sqrt(1. / d - 1. / x));
	return (p / q * sqrt(G));
}

inline long double g()
{
	return sqrt(2 * a * b * (1. / a + 1. / b)) * t0;
}

inline void Solve()
{
	scanf("%d %d %d %d", &a, &b, &d, &t0);
	long double l = eps, r = d - eps;
	for (int i = 1; i <= 100; i++)
	{
		long double mid = (l + r) / 2.0;
		if (f(mid) < g())
			l = mid;
		else
			r = mid;
	}
	cout << setprecision(12) << d - (l + r) / 2.0 << '\n';
	return;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		Solve();
	// system("pause");
	return 0;
}