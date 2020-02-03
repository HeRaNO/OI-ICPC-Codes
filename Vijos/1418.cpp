#include <cstdio>
#include <cstring>
using namespace std;

int p[1026], c[1026], e[1026];
int n, m, i, j, k;
int f[1026][1026];

int mymax(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	scanf("%d %d", &n, &m);
	memset(f, 0, sizeof(f));
	p[1] = 0;
	for (i = 2; i <= n; i++) scanf("%d", &p[i]);
	for (i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (i = 1; i <= n; i++) scanf("%d", &e[i]);
	for (i = n; i; i--)
	{
		f[i][c[i]] = mymax(f[i][c[i]], e[i]);
		int now = p[i];
		for (j = m; j >= 0; j--)
			for (k = 0; k <= j; k++)
				f[now][j] = mymax(f[now][j], f[now][j - k] + f[i][k]);
	}
	printf("%d", f[1][m]);
	return 0;
}