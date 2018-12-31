#include <cstdio>
#include <algorithm>
#define MAXN 50
using namespace std;

struct sss
{
	long long s, id;
} s[MAXN];

long long x1[MAXN], x2[MAXN], y11[MAXN], y2[MAXN];
int n, k;
long long x[MAXN * 2], y[MAXN * 2];
bool c[MAXN * 2][MAXN * 2];
long long sum, ans[MAXN];

bool cmp(sss a, sss b)
{
	return a.s > b.s;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld %lld %lld %lld", &x1[i], &y11[i], &x2[i], &y2[i]);
	for (int i = 1; i <= n; i++)
	{
		x[i] = x1[i];
		x[i + n] = x2[i];
		y[i] = y11[i];
		y[i + n] = y2[i];
	}
	sort(x + 1, x + 2 * n + 1);
	sort(y + 1, y + 2 * n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n * 2; j++)
			if (x1[i] == x[j])
			{
				x1[i] = j;
				break;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n * 2; j++)
			if (x2[i] == x[j])
			{
				x2[i] = j;
				break;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n * 2; j++)
			if (y11[i] == y[j])
			{
				y11[i] = j;
				break;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n * 2; j++)
			if (y2[i] == y[j])
			{
				y2[i] = j;
				break;
			}
	for (int p = n; p; p--)
	{
		sum = 0;
		for (int i = x1[p] + 1; i <= x2[p]; i++)
			for (int j = y11[p] + 1; j <= y2[p]; j++)
				if (!c[i][j])
				{
					c[i][j] = true;
					sum += (x[i] - x[i - 1]) * (y[j] - y[j - 1]);
				}
		s[p].s = sum;
		s[p].id = p;
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= k; i++) ans[i] = s[i].id - 1;
	sort(ans + 1, ans + k + 1);
	for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
	return 0;
}
