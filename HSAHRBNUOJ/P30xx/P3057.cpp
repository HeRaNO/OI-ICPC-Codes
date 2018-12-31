#include <cstdio>
using namespace std;
double r, h, pi = 3.14;
int main()
{
	scanf("%lf %lf", &r, &h);
	printf("C1=%.1lf\n", 2 * pi * r);
	printf("Sa=%.1lf\n", r * pi * r);
	printf("Sb=%.1lf\n", 4 * pi * r * r);
	printf("Va=%.1lf\n", 4 * pi * r * r * r / 3);
	printf("Vb=%.1lf\n", pi * r * r * h);
	return 0;
}