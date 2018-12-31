#include <cstdio>
using namespace std;

int gcd(int m, int n)
{
	return m % n == 0 ? n : gcd(n, m % n);
}

int a, b, l, i, j;
double c, k, minl;
int besti, bestj;

int main()
{
	//freopen("ratio.in","r",stdin);freopen("ratio.out","w",stdout);
	scanf("%d %d %d", &a, &b, &l);
	c = (double)a / (double)b;
	minl = 99999999999.00;
	for (i = 1; i <= l; i++)
		for (j = 1; j <= l; j++)
		{
			k = (double)i / (double)j;
			if (gcd(i, j) == 1 && k >= c && k < minl)
			{
				minl = k;
				besti = i;
				bestj = j;
			}
		}
	printf("%d %d\n", besti, bestj);
	return 0;
}
