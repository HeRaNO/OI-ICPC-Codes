//Code By HeRaNO
#include <cstdio>
using namespace std;
int a[110000], b[110000];
int x, la, n, lb, x1;
int main()
{
	scanf("%d", &n);
	a[1] = 1;
	la = 1;
	for (int i = 1; i <= n; i++)
	{
		x = 0;
		for (int j = 1; j <= la; j++)
		{
			a[j] = a[j] * i + x;
			x = a[j] / 10;
			a[j] = a[j] % 10;
		}
		while (x > 0)
		{
			la++;
			a[la] = x % 10;
			x = x / 10;
		}
		lb = la;
		x1 = 0;
		for (int k = 1; k <= lb; k++)
		{
			b[k] = b[k] + a[k] + x1;
			x1 = b[k] / 10;
			b[k] = b[k] % 10;
		}
	}
	for (int k = la; k; k--)
		printf("%d", b[k]);
	return 0;
}
