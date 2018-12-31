//Code By HeRaNO
#include <cstdio>
using namespace std;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int ans, a, n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		ans = mymax(a, ans);
	}
	printf("%d", ans);
	return 0;
}
