#include <cstdio>
#include <climits>
using namespace std;

int n;
int ans = INT_MAX;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int work(int x, int y)
{
	int cnt = 0;
	while ((x != 1) || (y != 1))
	{
		if (x > y) x -= y;
		else y -= x;
		if (!x || !y) return INT_MAX;
		cnt++;
	}
	return cnt;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		ans = mymin(ans, work(n, i));
	printf("%d\n", ans);
	return 0;
}
