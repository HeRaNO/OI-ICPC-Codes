//Code By HeRaNO
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	double x1, x2, y1, y2;
	scanf("%lf %lf", &x1, &y1);
	scanf("%lf %lf", &x2, &y2);
	printf("%.3lf", sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
	return 0;
}