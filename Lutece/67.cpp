#include <cstdio>
using namespace std;

double p, k, a, r = 1.0, b, m, f;
int n;

int main()
{
	scanf("%lf %lf %lf %d", &p, &k, &a, &n);
	b = 1 - p;
	k /= 100.0;
	a /= 100.0;
	for (int i = 0; i < n; i++)
	{
		f = p * r;
		m += f * (k + i * a) * p + f * (1 - p);
		r *= b;
	}
	m += r * (k + n * a) * p + r * (1 - p);
	printf("%.3lf\n", m / (p * k + 1 - p));
	return 0;
}