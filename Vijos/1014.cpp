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
	sort(a + 1, a + n + 1, cmp); //��x��������
	for (int i = 1; i <= n; i++) //��ֵ
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = INF;
			dis[i][j] = get_dis(a[i], a[j]);
		}
	dp[1][1] = 0.0; //��һ�����ڶ����˶���1���ǳ�ʼ״̬������Ϊ0
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int nxt = myminint(n, mymax(i, j) + 1); //nxt��Ϊ��һ��Ҫ����ĵ�
			//dp[i��֮ǰ][j��֮ǰ]�Ѿ�������ϣ����ڶԳ��ԣ��������λ��+1���ɣ���min����Խ��
			dp[nxt][j] = mymin(dp[nxt][j], dp[i][j] + dis[i][nxt]); //�õ�һ�����ߵ�nxt��
			dp[i][nxt] = mymin(dp[i][nxt], dp[i][j] + dis[j][nxt]); //�õڶ������ߵ�nxt��
		}
	printf("%.2lf", dp[n][n]);
	return 0;
}