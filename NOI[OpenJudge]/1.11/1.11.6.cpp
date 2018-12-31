//Code By HeRaNO
#include <cstdio>
#define MAXN 100100
using namespace std;

int a[MAXN];
int left, right, middle;
int n, m;

bool check(int best)
{
	int cnt = 1, money = 0;
	for (int i = 1; i <= n; i++)
	{
		if (money + a[i] <= best) money += a[i];
		else
		{
			cnt++;
			money = a[i];
		}
	}
	return cnt <= m;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		right += a[i];
		left = mymax(left, a[i]);
	}
	while (left < right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) right = middle;
		else left = middle + 1;
	}
	printf("%d\n", right);
	return 0;
}
