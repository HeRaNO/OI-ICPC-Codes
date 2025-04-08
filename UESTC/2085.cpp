#include <cstdio>
#define MAXN 300010
#define logA 30
using namespace std;

int a[MAXN][logA], n, x, p, cnt[logA], ans;
bool del[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		p = 0;
		while (x)
		{
			a[i][p] = x & 1;
			cnt[p++] += x & 1;
			x >>= 1;
		}
	}
	for (int i = 29; ~i; i--)
		if (cnt[i] >= 2)
		{
			ans |= (1 << i);
			for (int j = 1; j <= n; j++)
				if (!a[j][i] && !del[j])
				{
					del[j] = true;
					for (int k = i - 1; ~k; k--) cnt[k] -= a[j][k];
				}
		}
	printf("%d\n", ans);
	return 0;
}