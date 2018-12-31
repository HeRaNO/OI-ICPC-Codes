//Code By HeRaNO
#include <cstdio>
using namespace std;

int a[21];
int f[21];
int d[21];
int n, maxq, ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	f[n] = 1;
	for (int i = n - 1; i; i--)
	{
		maxq = 0;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j] && f[j] > maxq)
				maxq = f[j];
		}
		f[i] = maxq + 1;
	}
	for (int i = 1; i <= n; i++)
		ans = mymax(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
