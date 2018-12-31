#include <cstdio>
#define MAXN 100010
using namespace std;

int n, m;
int a[MAXN];
int left, right, middle;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

bool check(int limit)
{
	int cnt = 1, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sum + a[i] <= limit) sum += a[i];
		else
		{
			cnt++;
			sum = a[i];
		}
	}
	return cnt <= m;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		left = mymax(left, a[i]);
		right += a[i];
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
