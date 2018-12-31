#include <cstdio>
#define MAXN 20
using namespace std;

int w, h, l, ans, p, q;
int x[MAXN], y[MAXN];

int main()
{
	scanf("%d %d", &w, &h);
	scanf("%d", &l);
	for (int i = 0; i <= l; i++) scanf("%d %d", &x[i], &y[i]);
	if (l < 3)
	{
		printf("%d\n", l + 1);
		return 0;
	}
	for (int i = 3; i <= l; i++)
	{
		ans++;
		int k = i - 2;
		while (k)
		{
			p = (x[i - 1] - x[k - 1]) * (y[k] - y[k - 1]) - (y[i - 1] - y[k - 1]) * (x[k] - x[k - 1]);
			q = (x[k] - x[k - 1]) * (y[i] - y[k - 1]) - (y[k] - y[k - 1]) * (x[i] - x[k - 1]);
			if (p * q > 0) ans++;
			k--;
		}
	}
	printf("%d\n", ans + 3);
	return 0;
}
