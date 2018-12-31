#include <cstdio>
#include <cstring>
using namespace std;

int a, b, c;
int p1, p2, p3;
int n;
int t[11];
int f[11][101][101];//前i条生产线生产饮料数
int d[11][101][101];//drink 第i条生产线生产饮料数
int tot;
int preans;
int maxa, maxb, maxc;
int group;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int Getmin(int ga, int gb, int gc)
{
	int minn = 0x7fffffff;
	if (ga < minn) minn = ga;
	if (gb < minn) minn = gb;
	if (gc < minn) minn = gc;
	return minn;
}

void Presolve(int pa, int pb, int pc, int pp1, int pp2, int pp3)
{
	for (int i = 1; i <= n; i++)
		if (t[i] >= 5 * (pa * pp1 + pb * pp2 + pc * pp3))
		{
			for (int j = 1; j <= 3; j++)
			{
				t[i] -= pa * pp1 + pb * pp2 + pc * pp3;
				tot -= pa * pp1 + pb * pp2 + pc * pp3;
				preans++;
			}
		}
}

int main()
{
	memset(f, -1, sizeof(f));
	memset(d, 0, sizeof(d));
	f[0][0][0] = 0;
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d %d %d", &p1, &p2, &p3);
	scanf("%d", &n);
	int m = 0;
	group = a * p1 + b * p2 + c * p3; //一套套餐所用时间
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
		tot += t[i];
		m += t[i] / group;
	}
	if (m != 0 && m >= Getmin(100 / a, 100 / b, 100 / c))
	{
		printf("%d", Getmin(100 / a, 100 / b, 100 / c));
		return 0;
	}
	if (!m)
	{
		if ((tot / group) >= Getmin(100 / a, 100 / b, 100 / c))
		{
			printf("%d", Getmin(100 / a, 100 / b, 100 / c));
			return 0;
		}
	}
	Presolve(a, b, c, p1, p2, p3);
	maxa = (tot / (a * p1 + b * p2 + c * p3)) * a;
	maxb = (tot / (a * p1 + b * p2 + c * p3)) * b;
	maxc = (tot / (a * p1 + b * p2 + c * p3)) * c;
	for (int i = 1; i <= n; i++) //生产线
		for (int j = 0; j <= maxa; j++) //humburger
			for (int k = 0; k <= maxb; k++) //chips
			{
				if (f[i - 1][j][k] <= maxc)
				{
					for (int je = 0; je <= j; je++)
						for (int ke = 0; ke <= k; ke++)
							if (f[i - 1][j - je][k - ke] != -1)
							{
								d[i][je][ke] = (t[i] - (j - je) * p1 - (k - ke) * p2) / p3;
								f[i][j][k] = mymax(f[i][j][k], f[i - 1][j - je][k - ke] + d[i][je][ke]);
							}
				}
				else f[i][j][k] = f[i - 1][j][k];
			}
	int ans = 0;
	for (int j = 1; j <= maxa; j++)
		for (int k = 1; k <= maxb; k++)
			ans = mymax(ans, Getmin(j / a, k / b, f[n][j][k] / c));
	printf("%d\n", ans + preans);
	return 0;
}
