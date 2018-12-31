#include <cstdio>
#define MAXN 405
using namespace std;

int n, ans = ~(1 << 31);
int f[MAXN][MAXN], s[MAXN], a[MAXN];

inline void min(int &a, int b)
{
	if (a > b) a = b;
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
	for (int i = 1; i <= (n << 1); i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= (n << 1); i++)
		for (int j = i + 1; j <= (n << 1); j++)
			f[i][j] = 50000000;
	for (int l = 2; l <= n; l++)
		for (int i = 1; i <= (n << 1) - l + 1; i++)
			for (int j = i + l - 1, k = i; k < j; k++)
				min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
	for (int i = 1; i <= n; i++) min(ans, f[i][i + n - 1]);
	printf("%d\n", ans);
	return 0;
}
