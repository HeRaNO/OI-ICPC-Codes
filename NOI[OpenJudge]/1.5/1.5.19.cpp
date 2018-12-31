//Code By HeRaNO
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	double n, a, b, r, t = 0;
	scanf("%lf", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lf %lf %lf", &a, &b, &r);
		t = t + 2 * sqrt(a * a + b * b) / 50 + 1.5 * r;
	}
	printf("%.0lf", ceil(t));
	return 0;
}