#include <cmath>
#include <cstdio>
#define MAXN 13
using namespace std;

struct ICBM
{
	double x, y;
};

ICBM missile[MAXN], target[MAXN];
int n;
double ans = 2147483647.0, dis[MAXN][MAXN];
int seq[MAXN];
bool better[MAXN][MAXN][MAXN][MAXN];
bool used[MAXN];

double mymin(double a, double b)
{
	return a < b ? a : b;
}
double sqr(double a)
{
	return a * a;
}
double get_dis(int a, int b)
{
	return sqrt(sqr(missile[a].x - target[b].x) + sqr(missile[a].y - target[b].y));
}

void dfs(int dep)
{
	if (dep == n + 1)
	{
		double res = 0.0;
		for (int i = 1; i <= n; i++) res += dis[i][seq[i]];
		ans = mymin(ans, res);
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (dep > 1)
		{
			bool flag = false;
			for (int j = 1; j < dep && !flag; j++)
				if (better[j][seq[j]][dep - 1][seq[dep - 1]]) flag = true;
			if (flag) continue;
		}
		if (!used[i])
		{
			used[i] = true;
			seq[dep] = i;
			dfs(dep + 1);
			used[i] = false;
		}
	}
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lf %lf", &missile[i].x, &missile[i].y);
	for (int i = 1; i <= n; i++) scanf("%lf %lf", &target[i].x, &target[i].y);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = get_dis(i, j);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int s = 1; s <= n; s++)
				for (int t = 1; t <= n; t++)
					better[i][j][s][t] = (dis[i][j] + dis[s][t] > dis[i][t] + dis[s][j]);
	dfs(1);
	printf("%.3lf\n", ans);
	return 0;
}
