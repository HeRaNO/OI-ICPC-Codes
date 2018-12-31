#include <cstdio>
#define MAXN 2048
using namespace std;

double p[MAXN][MAXN];
int all, sta;
double win[MAXN][MAXN];

void dfs(int dep, int left, int right)
{
	if (right - left > 2)
	{
		dfs(dep * 2 + 1, left, (left + right) / 2);
		dfs(dep * 2 + 2, (right + left) / 2 + 1, right);
	}
	for (int i = left; i <= (right + left) / 2; i++)
		for (int j = (right + left) / 2 + 1; j <= right; j++)
		{
			p[dep][i] += p[dep * 2 + 1][i] * p[dep * 2 + 2][j] * win[i][j];
			p[dep][j] += p[dep * 2 + 1][i] * p[dep * 2 + 2][j] * win[j][i];
		}
}

int main()
{
	int n;
	scanf("%d", &n);
	all = 1 << n;
	for (int i = 1; i <= all; i++)
		for (int j = 1; j <= all; j++)
		{
			scanf("%lf", &win[i][j]);
			win[i][j] /= 100.0;
		}
	sta = all - 1;
	for (int i = 1; i <= all; i++) p[sta + i - 1][i] = 1;
	dfs(0, 1, all);
	double f = 0.0;
	int res;
	for (int i = 1; i <= all; i++)
		if (p[0][i] > f)
		{
			res = i;
			f = p[0][i];
		}
	printf("%d\n", res);
	return 0;
}
