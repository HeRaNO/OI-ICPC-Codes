#include <cstdio>
#define MAXN 100010
using namespace std;

int a[MAXN], b[MAXN];
int n, cnt, ans, flag;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		if (b[i] != b[i - 1]) a[++cnt] = b[i];
	for (int i = 2; i < cnt; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans++;
	}
	printf("%d\n", ans + 2);
	return 0;
}
