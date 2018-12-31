//Code By HeRaNO
#include <cstdio>
using namespace std;

int a[40010], n, len, x;

int main()
{
	scanf("%d", &n);
	a[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		x = 0;
		for (int j = 1; j <= 40000; j++)
			if (a[j] || x)
			{
				a[j] = a[j] * i + x;
				x = a[j] / 10;
				a[j] %= 10;
			}
	}
	len = 40000;
	while (!a[len] && len > 0) len--;
	for (int i = len; i; i--)
		printf("%d", a[i]);
	return 0;
}
