//Code By HeRaNO
#include<stdio.h>
#include<math.h>
int main()
{
	double m = 0.0, M, x;
	int n;
	scanf("%lf %d %lf", &M, &n, &x);
	while (x >= 0)
	{
		n = m / n + n;
		x = x - ceil(M / n);
		m = M;
		if (m > M)break;
	}
	printf("%d", n);
	return 0;
}