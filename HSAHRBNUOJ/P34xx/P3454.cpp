#include <cstdio>
#define MAXN 100010
using namespace std;

int n, k;
int a[MAXN], b[MAXN], ans[MAXN], s[MAXN];

int main()
{
	//freopen("hearthstone.in","r",stdin);freopen("hearthstone.out","w",stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		if ((i - 1) % (k + 1)) a[i] = a[i - (i - 1) / (k + 1) - 1] + 1, b[i] = b[i - (i - 1) / (k + 1) - 1];
		else a[i] = 0, b[i] = (i - 1) / (k + 1);
	}
	for (int i = n, j = 1; i; j++, i -= (i - 1) / (k + 1) + 1) s[j] = (i - 1) / (k + 1) + 1 + s[j - 1];
	for (int i = 1; i <= n; i++) ans[s[a[i]] + b[i]] = i;
	for (int i = 0; i < n - 1; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[n - 1]);
	return 0;
}
