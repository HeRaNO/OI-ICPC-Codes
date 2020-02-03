#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 110
using namespace std;

int n;
double a[MAXN][MAXN];

inline void Gauss_Elimination()
{
	for (int i = 1; i <= n; i++)
	{
		int now = i;
		for (int j = i + 1; j <= n; j++)
			if (fabs(a[now][i]) < fabs(a[j][i])) now = j;
		swap(a[now], a[i]);
		double t = a[i][i];
		for (int j = 1; j <= n + 1; j++) a[i][j] /= t;
		for (int j = 1; j <= n; j++)
			if (j != i)
			{
				t = a[j][i];
				for (int k = 1; k <= n + 1; k++)
					a[j][k] -= t * a[i][k];
			}
	}
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			scanf("%lf", &a[i][j]);
	Gauss_Elimination();
	for (int i = 1; i < n; i++) printf("%d ", (int)round(a[i][n + 1]));
	printf("%d\n", (int)round(a[n][n + 1]));
	return 0;
}
