//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 100100
using namespace std;

int a[MAXN];
int n, m;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++)
	{
		if (2 * a[i] > m) break;
		int res = m - a[i];
		if (binary_search(a + i + 1, a + n + 1, res))
		{
			if (a[i] > res) swap(a[i], res);
			printf("%d %d\n", a[i], res);
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
