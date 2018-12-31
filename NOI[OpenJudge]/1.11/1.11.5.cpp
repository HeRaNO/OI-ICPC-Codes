//Code By HeRaNO
#include <cmath>
#include <cstdio>
#define MAXN 10010
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-6;

int n, f, r;
double v[MAXN];
double left, right, middle;

bool check(double a)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += floor(v[i] / a);
	return cnt >= f + 1;
}

int main()
{
	scanf("%d %d", &n, &f);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &r);
		v[i] = PI * r * r;
		if (v[i] > right) right = v[i];
	}
	while (right - left > eps)
	{
		middle = (left + right) / 2.0;
		if (check(middle)) left = middle;
		else right = middle;
	}
	printf("%.3lf\n", left);
	return 0;
}
