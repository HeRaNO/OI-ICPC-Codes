//Code By HeRaNO
#include <stdio.h>
int main()
{
	double a, jue;
	scanf("%lf", &a);
	if (a >= 0) printf("%0.2lf", a);
	else
	{
		jue = -a;
		printf("%0.2lf", jue);
	}
	return 0;
}