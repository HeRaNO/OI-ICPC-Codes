//Code By HeRaNO
#include <cstdio>
using namespace std;
double a, r, n;
int year = 1;
int main()
{
	scanf("%lf %lf", &n, &r);
	r /= 100.0;
	a = 200.0;
	while (true)
	{
		if (year > 20) break;
		if (n * double(year) >= a)
		{
			printf("%d\n", year);
			return 0;
		}
		year++;
		a = a + a * r;
	}
	printf("Impossible\n");
	return 0;
}
