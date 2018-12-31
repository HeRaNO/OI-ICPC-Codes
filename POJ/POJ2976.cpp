#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
using namespace std;

const double eps = 1e-7;
int n, k;
double a[MAXN], b[MAXN];
double left, right, middle, ans;
double sum[MAXN];

bool check(double kk)
{
	kk /= 100.0;
	double get = 0.0;
	for (int i = 0; i < n; i++)
		sum[i] = a[i] - kk * b[i];
	sort(sum, sum + n);
	for (int i = k; i < n; i++) get += sum[i];
	if (get > 0.0) return true;
	return false;
}

int main()
{
	while (scanf("%d %d", &n, &k) == 2)
	{
		if (n == 0 && k == 0) break;
		left = 0.0;
		right = 102.0;
		ans = 0.0;
		for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
		for (int i = 0; i < n; i++) scanf("%lf", &b[i]);
		while (right - left > eps)
		{
			middle = (left + right) / 2.0;
			if (check(middle)) left = middle, ans = middle;
			else right = middle;
		}
		printf("%.0lf\n", ans);
	}
	return 0;
}
