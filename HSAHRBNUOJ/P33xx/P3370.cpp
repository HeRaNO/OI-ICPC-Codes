#include <cstdio>
#include <algorithm>
#define MAXN 10010
using namespace std;

int n, T;
int a[MAXN];
long long ans, t, M;

int main()
{
	//freopen("find.in","r",stdin);freopen("find.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &M);
		ans = 0LL;
		for (int i = 1; a[i] <= M / 2 && i + 1 <= n; i++)
		{
			t = upper_bound(a + i + 1, a + n + 1, M - a[i]) - a;
			ans += t - i - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
