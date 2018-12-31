//Code By HeRaNO
#include <cstdio>
using namespace std;

char str[41];
long long s[41][41], f[41][41];
int n, k;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &k);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		str[i] = getchar();
		s[i][i] = str[i] - '0';
	}
	for (int p = 1; p <= n; p++)
		for (int i = 1; i <= n && i + p <= n; i++)
		{
			if (i + p > n) break;
			s[i][i + p] = s[i][i + p - 1] * 10 + (str[i + p] - '0');
		}
	for (int i = 1; i <= n; i++)
		f[i][0] = s[1][i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= mymin(k, i - 1); j++)
			for (int k = j; k < i; k++)
				f[i][j] = mymax(f[i][j], f[k][j - 1] * s[k + 1][i]);
	printf("%d\n", f[n][k]);
	return 0;
}
