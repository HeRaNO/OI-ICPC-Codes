#include <cstdio>
#include <climits>
#include <cstring>
#define MAXN 310
using namespace std;

int a[MAXN][MAXN], row[MAXN];
int n, ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int get_sum()
{
	int res = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (res + row[i] > 0) res += row[i];
		else res = 0;
		ans = mymax(ans, res);
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0) a[i][j] = -1000000;
		}
	for (int i = 1; i <= n; i++)
	{
		memset(row, 0, sizeof(row));
		for (int j = i; j <= n; j++)
		{
			for (int k = 1; k <= n; k++) row[k] += a[j][k];
			int res = get_sum();
			ans = mymax(res, ans);
		}
	}
	printf("%d\n", mymax(0, ans - 10));
	return 0;
}
