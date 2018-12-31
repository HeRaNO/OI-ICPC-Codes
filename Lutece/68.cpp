#include <cstdio>
#include <iostream>
using namespace std;

int n, v, L, h, a;
double t, mx, mn = 1e18;

int main()
{
	scanf("%d %d %d", &n, &L, &v);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &h, &a);
		t = (double)(L - h) / (v + a);
		mx = max(mx, t);
		mn = min(mn, t);
	}
	printf("%.2lf %.2lf\n", mn, mx);
	return 0;
}