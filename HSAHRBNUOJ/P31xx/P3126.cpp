#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct prefix
{
	int len;
	long long sum;
};

int n;
long long a[MAXN];
long long sum[MAXN];
long long ans = ~(1LL << 63), ans1;
prefix p[MAXN];

bool cmp(prefix a, prefix b)
{
	return a.sum < b.sum;
}

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

long long myabs(long long a)
{
	return a < 0LL ? -a : a;
}

int main()
{
	//freopen("min.in","r",stdin);freopen("min.out","w",stdout);
	scanf("%d", &n);
	p[0] = (prefix)
	{
		0, 0
	};
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) p[i] = (prefix)
	{
		i, p[i - 1].sum + a[i]
	};
	sort(p, p + n + 1, cmp);
	for (int i = 0; i < n; i++)
		if (p[i + 1].sum - p[i].sum < myabs(ans))
		{
			if (p[i + 1].len < p[i].len) ans = p[i].sum - p[i + 1].sum;
			else ans = p[i + 1].sum - p[i].sum;
			ans1 = myabs(p[i].len - p[i + 1].len);
		}
		else if (p[i + 1].sum - p[i].sum == myabs(ans))
			ans1 = mymax(ans1, myabs(p[i].len - p[i + 1].len));
	printf("%lld\n%lld\n", ans, ans1);
	return 0;
}
