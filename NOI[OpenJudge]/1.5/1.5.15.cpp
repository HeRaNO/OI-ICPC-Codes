//Code By HeRaNO
#include <cstdio>
using namespace std;
double a, r;
int n;
int main()
{
	scanf("%lf %lf %d", &r, &a, &n);
	r /= 100;
	for (int i = 1; i <= n; i++)
		a = (a * (1.0 + r));
	n = a;
	printf("%d", n);
	return 0;
}
