#include<cstdio>
#include<cstring>
using namespace std;

int f[15][15];

int main()
{
	int n, k;
	f[0][0] = 1;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			f[i][j] = j * f[i - 1][j] + f[i - 1][j - 1];
	for (int i = 1; i <= k; i++) f[n][k] *= i;
	printf("%d\n", f[n][k]);
	return 0;
}
