#include <cstdio>
#define MAXN 200010
using namespace std;

const double eps = 1e-9;
const double LIMIT = 1e7;

struct post
{
	double x;
	double y;
	double s;
};

post a[MAXN];
double left, right, middle, ans;
int n;

bool check(double v)
{
	double time = 0.0;
	for (int i = 1; i <= n; i++)
	{
		time = time + a[i].s / v;
		if (time < a[i].x) time = a[i].x;
		if (time > a[i].y) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf %lf %lf", &a[i].x, &a[i].y, &a[i].s);
	left = eps, right = LIMIT;
	while (right - left > eps)
	{
		middle = (left + right) / 2.0;
		if (check(middle)) right = middle;
		else left = middle;
	}
	printf("%.2lf\n", left);
	return 0;
}