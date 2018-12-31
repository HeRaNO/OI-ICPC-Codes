#include <cstdio>
using namespace std;

int T;
double n, m;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf %lf", &n, &m);
		if (n < m) puts("0.000000");
		else printf("%.6lf\n", 1.0 - m / (n + 1));
	}
	return 0;
}
