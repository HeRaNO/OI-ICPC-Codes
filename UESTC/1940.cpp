#include <cstdio>
#define MAXN 205
using namespace std;

int n, f[MAXN][MAXN], a[MAXN];

inline void min(int &a, int b)
{
	if (a > b) a = b;
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n + 2; i++) read(a[i]);
	for (int i = 1; i <= n + 2; i++)
		for (int j = i + 2; j <= n + 2; j++)
			f[i][j] = 500000000;
	for (int i = n; i; i--)
		for (int j = i + 2; j <= n + 2; j++)
			for (int k = i + 1; k <= j - 1; k++)
				min(f[i][j], f[i][k] + f[k][j] + a[i]*a[j]*a[k]);
	printf("%d\n", f[1][n + 2]);
	return 0;
}
