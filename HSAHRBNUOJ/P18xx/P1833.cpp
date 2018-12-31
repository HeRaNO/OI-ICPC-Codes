#include <cmath>
#include <cstdio>
#include <cstring>
#define MAXN 60
using namespace std;

double a[MAXN][MAXN], dis[MAXN][MAXN][MAXN];
int n, m, T, u, v, w;
double ans;

inline double mymin(double a, double b)
{
	return a < b ? a : b;
}

int main()
{
	//freopen("data.in","r",stdin);freopen("data.out","w",stdout);
	memset(dis, 0x7f, sizeof dis);
	memset(a, 0x7f, sizeof a);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		a[u][v] = dis[1][u][v] = mymin(dis[1][u][v], w);
	}
	for (int p = 2; p <= n; p++)
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dis[p][i][j] = mymin(dis[p][i][j], dis[p - 1][i][k] + a[k][j]);
	scanf("%d", &T);
	while (T--)
	{
		ans = 1e10;
		scanf("%d %d", &u, &v);
		for (int i = 1; i <= n; i++) ans = mymin(ans, dis[i][u][v] / (double)i);
		if (ans != 1e10) printf("%.3lf\n", round(ans * 1000) / 1000);
		else puts("OMG!");
	}
	return 0;
}
