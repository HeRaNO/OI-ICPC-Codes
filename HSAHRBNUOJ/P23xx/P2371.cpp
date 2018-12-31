#include <cmath>
#include <cstdio>
using namespace std;

int m, n, pt, g;
double besta = ~(1 << 31);
int mm, nn, tm, tn = 1;
double R, x, y;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int main()
{
	scanf("%d %d", &m, &n);
	scanf("%lf", &R);
	while (tm <= m && tn <= n)
	{
		x = (double)tm / (double)tn;
		if (fabs(x - R) == besta)
		{
			g = gcd(tm, tn);
			if (mm != tm / g && nn != tn / g)
			{
				puts("TOO MANY");
				return 0;
			}
		}
		if (fabs(x - R) < besta)
		{
			besta = fabs(x - R);
			g = gcd(tm, tn);
			mm = tm / g;
			nn = tn / g;
		}
		if (x > R) tn++;
		else tm++;
	}
	printf("%d/%d\n", mm, nn);
	return 0;
}
