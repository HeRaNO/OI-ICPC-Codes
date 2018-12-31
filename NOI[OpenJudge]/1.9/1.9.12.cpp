//Code By HeRaNO
#include <cstdio>
#define MAXN 1010
using namespace std;

int a[MAXN];
int n, ans, cnt;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])
		{
			ans = mymax(ans, cnt);
			cnt = 1;
		}
		else cnt++;
	}
	ans = mymax(ans, cnt);
	printf("%d\n", ans);
	return 0;
}
