//Code By HeRaNO
#include <cstdio>
using namespace std;
double a;
int n;
int main()
{
	scanf("%lf %d", &a, &n);
	for (int i = 1; i <= n; i++)
		a *= 1.001;
	printf("%.4lf", a);
	return 0;
}
