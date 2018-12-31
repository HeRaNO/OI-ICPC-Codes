#include <cmath>
#include <cstdio>
#define MAXN 100010
#define MOD 100007LL
using namespace std;

const double pi = acos(-1.0);

char opt[3];
double a, b, c, d, e, f;
double l, alpha;
int n, T;
long long m[MAXN];

int main()
{
	m[2] = 1;
	for (int i = 3; i <= 100000; i++) m[i] = (i - 1) * (m[i - 2] + m[i - 1]) % MOD;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", opt);
		if (opt[0] == 'a')
		{
			scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e);
			printf("%.3lf\n", (a * c * e) / (b * d));
		}
		else if (opt[0] == 'b')
		{
			scanf("%lf%lf", &l, &alpha);
			alpha = alpha / 180 * pi;
			printf("%.3lf %.3lf\n", l * sin(alpha / 2), l * l * sin(alpha) / 8);
		}
		else
		{
			scanf("%d", &n);
			printf("%lld\n", m[n]);
		}
	}
	return 0;
}