//Code By HeRaNO
#include <cstdio>
using namespace std;

int n, p = 1, q = 2, z = 1;
double ans = 0.0;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		ans = ans + double(q) / double(p);
		p = q;
		q += z;
		z = p;
	}
	printf("%.4lf", ans);
	return 0;
}
