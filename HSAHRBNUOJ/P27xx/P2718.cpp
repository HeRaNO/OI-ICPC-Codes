#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 200010
using namespace std;

const double eps = 1e-11;
int n;
double a[MAXN];
double left, right, lmid, rmid;
double ans1, ans2;

double mymax(double a, double b)
{
	return a - b > eps ? a : b;
}
double mymin(double a, double b)
{
	return a - b < eps ? a : b;
}
double myabs(double a)
{
	return a < eps ? -a : a;
}

double solve(double x)
{
	double ansmax = INT_MIN, ansmin = INT_MAX;
	double tmp, dpmin = 0.0, dpmax = 0.0;
	for (int i = 1; i <= n; i++)
	{
		tmp = a[i] - x;
		dpmax = mymax(dpmax, 0.0) + tmp;
		dpmin = mymin(dpmin, 0.0) + tmp;
		ansmax = mymax(ansmax, dpmax);
		ansmin = mymin(ansmin, dpmin);
	}
	return mymax(-ansmin, ansmax);
}

int main()
{
	//freopen("weakness.in","r",stdin);freopen("weakness.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
	left = -1e10;
	right = 1e10;
	while (right - left > eps)
	{
		lmid = (left + right) / 2.0;
		rmid = (lmid + right) / 2.0;
		ans1 = solve(lmid);
		ans2 = solve(rmid);
		if (ans1 <= ans2) right = rmid;
		else left = lmid;
	}
	printf("%.6lf\n", mymin(solve(lmid), solve(rmid)));
	return 0;
}
