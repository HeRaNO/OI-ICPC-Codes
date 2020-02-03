#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 30010
using namespace std;

const double ORO = 0.6180339887498949;
double a[MAXN];
double ansa, ansb;
int n;

void binary(double t, int x)
{
	int left = x, right = n + 1, middle;
	while (right - left > 1)
	{
		middle = (left + right) >> 1;
		if (a[middle] >= t) right = middle;
		else left = middle;
	}
	if (right <= n && fabs(a[x] / a[right] - ORO) < fabs(ansa / ansb - ORO))
	{
		ansa = a[x];
		ansb = a[right];
	}
	if (left >= x + 1 && fabs(a[x] / a[left] - ORO) < fabs(ansa / ansb - ORO))
	{
		ansa = a[x];
		ansb = a[left];
	}
	return ;
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
		sort(a + 1, a + n + 1);
		ansa = a[1];
		ansb = a[2];
		for (int i = 1; i <= n; i++) binary(a[i] / ORO, i);
		printf("%d\n%d\n", (int)ansa, (int)ansb);
	}
	return 0;
}
