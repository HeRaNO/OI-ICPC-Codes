#include <cstdio>
#include <algorithm>
#define MAXN 10010
using namespace std;

struct work
{
	int start;
	int last;
};

int dp[MAXN];
work a[MAXN];
int n, k;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

bool cmp(work a, work b)
{
	return a.start < b.start;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d %d", &a[i].start, &a[i].last);
	sort(a + 1, a + k + 1, cmp);
	for (int i = n; i; i--)
	{
		if (a[k].start != i) dp[i] = dp[i + 1] + 1;
		else
		{
			while (a[k].start == i)
			{
				dp[i] = mymax(dp[i], dp[i + a[k].last]);
				k--;
			}
		}
	}
	printf("%d\n", dp[1]);
	return 0;
}
