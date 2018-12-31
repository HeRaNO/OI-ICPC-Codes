#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

int n, a[MAXN][MAXN], mx[MAXN][MAXN], mn[MAXN][MAXN], ans;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int myabs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	memset(mn, 0x7f, sizeof mn);
	mn[0][1] = mn[0][0] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
		{
			mx[i][j] = mymax(mx[i - 1][j], mx[i - 1][j - 1]) + a[i][j];
			mn[i][j] = mymin(mn[i - 1][j], mn[i - 1][j - 1]) + a[i][j];
		}
	for (int i = 1; i <= n; i++) ans = mymax(ans, mymax(myabs(mx[n][i]), myabs(mn[n][i])));
	printf("%d\n", ans);
	return 0;
}