#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 205
#define LL_MAX 9223372036854775807
using namespace std;

int n, m, ans, top;
long long a[MAXN][MAXN];
long long sta[MAXN], sum[MAXN], f[MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int binary(long long val)
{
	int left = 1, right = top, middle, res = -1;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (sta[middle] < val) res = middle, right = middle - 1;
		else left = middle + 1;
	}
	return res;
}

void work(int x, int y)
{
	top = 0;
	for (int i = 1; i <= n; i++)
		sum[i] += a[i][y];
	sta[top] = LL_MAX;
	long long tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		tmp += sum[i];
		if (tmp > 0) ans = mymax(ans, i * (y - x + 1));
		else
		{
			int t = binary(tmp);
			if (t != -1) ans = mymax(ans, (i - f[t]) * (y - x + 1));
		}
		if (tmp < sta[top])
		{
			sta[++top] = tmp;
			f[top] = i;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%lld", &a[i][j]);
	for (int i = 1; i <= m; i++)
	{
		memset(sum, 0, sizeof(sum));
		for (int j = i; j <= m; j++)
			work(i, j);
	}
	printf("%d\n", ans);
	return 0;
}
