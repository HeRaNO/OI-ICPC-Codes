//Code By HeRaNO
#include <cmath>
#include <cstdio>
using namespace std;

double a, b, c;
double real, complexx;
double delta;
double axis;

int main()
{
	scanf("%lf %lf %lf", &a, &b, &c);
	axis = -b / (2 * a);
	if (axis == -0.0) axis = 0.0;
	delta = b * b - 4 * a * c;
	if (delta == 0.0) printf("x1=x2=%.5lf", axis);
	else if (delta > 0.0)
	{
		printf("x1=%.5lf;", (-b + sqrt(delta)) / (2 * a));
		printf("x2=%.5lf", (-b - sqrt(delta)) / (2 * a));
	}
	else
	{
		delta = 4 * a * c - b * b;
		printf("x1=%.5lf+%.5lfi;", axis, (sqrt(delta)) / (2 * a));
		printf("x2=%.5lf-%.5lfi", axis, (sqrt(delta)) / (2 * a));
	}
	return 0;
}
