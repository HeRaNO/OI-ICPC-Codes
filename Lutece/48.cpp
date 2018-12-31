#include <cstdio>
#define MAXN 310
using namespace std;

int n;
double ans, a[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &a[i]);
		a[i] /= 100.0;
		a[i] = a[i] + (1.0 - a[i]) * a[i];
	}
	for (int i = 1; i <= n; i++) ans += a[i];
	printf("%.3lf\n", ans);
	return 0;
}
