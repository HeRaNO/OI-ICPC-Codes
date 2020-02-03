#include <cmath>
#include <cstdio>
#include <cstring>
#define MAXN 20
using namespace std;

const double eps = 1e-7;

struct Point
{
	double x, y;
	__attribute__((__optimize__("-O2"))) Point() {}
	__attribute__((__optimize__("-O2"))) Point(double x, double y): x(x), y(y) {}
};

Point p[MAXN], res;
int n, m, T;
int dp[1 << MAXN];
int status[MAXN][MAXN];
double A, B, a, b;

__attribute__((__optimize__("-O2"))) inline double sqr(double x)
{
	return x * x;
}
__attribute__((__optimize__("-O2"))) inline bool equal(double a, double b)
{
	return fabs(a - b) < eps;
}
__attribute__((__optimize__("-O2"))) inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
__attribute__((__optimize__("-O2"))) inline Point Solve(double a, double b, double c, double d, double e, double f)
{
	return Point((c * e - b * f) / (a * e - b * d), (a * f - c * d) / (a * e - b * d));
}

__attribute__((__optimize__("-O2"))) inline void MathProblem()
{
	memset(status, 0, sizeof status);
	for (int i = 1; i <= n; i++)
	{
		status[i][i] = 1 << i - 1;
		for (int j = i + 1; j <= n; j++)
		{
			if (p[i].x == p[j].x && p[i].y != p[j].y) continue;
			res = Solve(p[i].x * p[i].x, p[i].x, p[i].y, p[j].x * p[j].x, p[j].x, p[j].y);
			A = res.x;
			B = res.y;
			if (equal(A, 0.0) || A >= 0.0) continue;
			status[i][j] = (1 << i - 1) | (1 << j - 1);
			for (int k = 1; k <= n; k++)
				if (k != i && k != j)
				{
					if (p[i].x == p[k].x && p[i].y != p[k].y) continue;
					res = Solve(p[i].x * p[i].x, p[i].x, p[i].y, p[k].x * p[k].x, p[k].x, p[k].y);
					a = res.x;
					b = res.y;
					if (equal(A, a) && equal(B, b)) status[i][j] |= (1 << k - 1);
				}
			status[j][i] = status[i][j];
		}
	}
	return ;
}

__attribute__((__optimize__("-O2"))) inline int Dynamic_Programming()
{
	memset(dp, 0x7f, sizeof dp);
	dp[0] = 0;
	for (int i = 0; i < (1 << n) - 1; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dp[i | status[j][k]] = mymin(dp[i | status[j][k]], dp[i] + 1);
	return dp[(1 << n) - 1];
}

__attribute__((__optimize__("-O2"))) int main()
{
	//freopen("angrybirds.in","r",stdin);freopen("angrybirds.out","w",stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
		MathProblem();
		printf("%d\n", Dynamic_Programming());
	}
	return 0;
}
