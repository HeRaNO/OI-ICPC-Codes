//Code By HeRaNO
#include <cstdio>
using namespace std;
int main()
{
	double x;
	double bike, walk;
	scanf("%lf", &x);
	bike = x / 3.0 + 50.0;
	walk = x / 1.2;
	if (bike > walk) printf("Walk");
	else if (bike == walk) printf("All");
	else printf("Bike");
	return 0;
}