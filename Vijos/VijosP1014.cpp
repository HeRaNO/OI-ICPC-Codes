#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 1010
#define INF 1e50
using namespace std;

struct point
{
	double x;
	double y;
};

double get_dis(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(point a, point b)
{
	return a.x < b.x;
}

point a[MAXN];
double dp[MAXN][MAXN];
double dis[MAXN][MAXN];
int n;

double mymin(double a, double b)
{
	return a - b < 0 ? a : b;
}

int myminint(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf %lf", &a[i].x, &a[i].y);
	sort(a + 1, a + n + 1, cmp); //按x升序排序
	for (int i = 1; i <= n; i++) //初值
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = INF;
			dis[i][j] = get_dis(a[i], a[j]);
		}
	dp[1][1] = 0.0; //第一个，第二个人都在1点是初始状态，距离为0
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int nxt = myminint(n, mymax(i, j) + 1); //nxt点为下一个要考察的点
			//dp[i及之前][j及之前]已经处理完毕，由于对称性，考察最大位置+1即可，加min防治越界
			dp[nxt][j] = mymin(dp[nxt][j], dp[i][j] + dis[i][nxt]); //让第一个人走到nxt点
			dp[i][nxt] = mymin(dp[i][nxt], dp[i][j] + dis[j][nxt]); //让第二个人走到nxt点
		}
	printf("%.2lf", dp[n][n]);
	return 0;
}