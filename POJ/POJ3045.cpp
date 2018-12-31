#include <cstdio>
#include <climits>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct acrobats
{
	long long w;
	long long s;
};

acrobats a[MAXN];
int n;
long long tot;
long long ans = -INT_MAX;

bool cmp(acrobats a, acrobats b)
{
	return a.w + a.s < b.w + b.s;
}

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%lld %lld", &a[i].w, &a[i].s), tot += a[i].w;
		ans = -INT_MAX;
		sort(a + 1, a + n + 1, cmp);
		for (int i = n; i; i--)
		{
			tot -= a[i].w;
			ans = mymax(ans, tot - a[i].s);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
