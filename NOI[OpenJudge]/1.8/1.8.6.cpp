//Code By HeRaNO
#include <cstdio>
#define MAXN 110
using namespace std;

int a[MAXN][MAXN];
int a1[MAXN][MAXN];
int n, m;
double ans;
double same = 0.0;

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a1[i][j]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] == a1[i][j]) same = same + 1.0;
	double k = n * m;
	ans = same / k * 100.0;
	printf("%.2lf", ans);
	return 0;
}
