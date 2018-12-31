//Code By HeRaNO
#include <cstdio>
#define MAXN 310
using namespace std;

double myabs(double a)
{
	return a < 0.0 ? -a : a;
}

double a[MAXN];
int n;
double maxx, minx = 999999999.0;
double sum, best, ave;
bool maxflag = true, minflag = true;

double mymax(double a, double b)
{
	return a > b ? a : b;
}

double mymin(double a, double b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &a[i]);
		maxx = mymax(maxx, a[i]);
		minx = mymin(minx, a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == maxx && maxflag)
		{
			maxflag = false;
			continue;
		}
		if (a[i] == minx && minflag)
		{
			minflag = false;
			continue;
		}
		sum += a[i];
	}
	ave = sum / double(n - 2);
	maxflag = minflag = true;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == maxx && maxflag)
		{
			maxflag = false;
			continue;
		}
		if (a[i] == minx && minflag)
		{
			minflag = false;
			continue;
		}
		best = mymax(best, myabs(ave - a[i]));
	}
	printf("%.2lf %.2lf\n", ave, best);
	return 0;
}
