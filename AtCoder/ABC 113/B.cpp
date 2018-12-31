#include <cstdio>
#include <cmath>
#define MAXN 1010
using namespace std;

int n, t, a, ans;
double h[MAXN], be = 1000000000000.0;

int main()
{
	scanf("%d", &n);
	scanf("%d", &t);
	scanf("%d", &a);
	for (int i = 1; i <= n; i++) scanf("%lf", &h[i]);
	for (int i = 1; i <= n; i++)
	{
		double tmp = t - h[i] * 0.006;
		if (fabs(tmp - a) < be)
		{
			be = fabs(tmp - a);
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}