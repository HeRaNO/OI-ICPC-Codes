//Code By HeRaNO
#include<cstdio>
using namespace std;
int n, a, b, h, ans;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		if (a >= 90 && a <= 140 && b >= 60 && b <= 90) h++;
		else h = 0;
		if (ans < h) ans = h;
	}
	printf("%d", ans);
	return 0;
}