//Code By HeRaNO
#include <cstdio>
using namespace std;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int ans1, ans2 = 2147483647, a, n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		ans1 = mymax(a, ans1);
		ans2 = mymin(a, ans2);
	}
	printf("%d", ans1 - ans2);
	return 0;
}
