#include <cstdio>
#define MOD 7777777LL
using namespace std;

struct KSM
{
	long long m[12][12];
};

KSM ans, base;
int n, k;

KSM mutiply(KSM a, KSM b)
{
	KSM res;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
		{
			res.m[i][j] = 0;
			for (int l = 0; l < k; l++)
				res.m[i][j] = (res.m[i][j] + a.m[i][l] * b.m[l][j]) % MOD;
		}
	return res;
}

long long work(int t)
{
	for (int i = 0; i < k; i++) ans.m[i][0] = base.m[i][0] = 1LL;
	for (int i = 0; i < k; i++) ans.m[i][i + 1] = base.m[i][i + 1] = 1LL;
	while (t)
	{
		if (t & 1) ans = mutiply(ans, base);
		base = mutiply(base, base);
		t >>= 1;
	}
	return ans.m[0][1] % MOD;
}

int main()
{
	//freopen("fyfy.in","r",stdin);freopen("fyfy.out","w",stdout);
	scanf("%d %d", &k, &n);
	if (k == 1)
	{
		puts("1");
		return 0;
	}
	printf("%lld\n", work(n));
	return 0;
}
