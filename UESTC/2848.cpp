#include <cstdio>
#include <vector>
#include <numeric>
#define MAXN 16

using ull = unsigned long long;

const long long INF = 1'000'000'000'000'000LL;

struct fac
{
	int dep;
	long long val;
	fac(){}
	fac(int _, long long __):
		dep(_), val(__){}
};

int n, k, a[MAXN];
std::vector<fac> v;

void dfs(int dep, int l, long long prd)
{
	if (dep) v.emplace_back(dep, prd);
	for (int i = l + 1; i <= n; i++)
	{
		ull nprd = (ull)prd / std::gcd(prd, a[i]) * a[i];
		if (nprd > INF) continue;
		dfs(dep + 1, i, nprd);
	}
	return ;
}

long long P(long long x)
{
	long long r = 0;
	for (fac f : v)
		r += (f.dep & 1 ? 1LL : -1LL) * x / f.val * f.dep;
	return r;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(0, 0, 1);
	long long l = 1, r = INF, ans;
	while (l <= r)
	{
		long long m = l + r >> 1;
		long long rt = P(m);
		if (rt >= k) ans = m, r = m - 1;
		else l = m + 1;
	}
	printf("%lld\n", ans);
	return 0;
}