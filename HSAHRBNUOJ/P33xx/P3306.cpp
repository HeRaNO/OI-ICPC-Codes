#include <cstdio>
#include <climits>
#define MOD 1000000007LL
using namespace std;

struct KSM
{
	long long m[2][2];
};

long long k;
KSM ans, base;

KSM multiply(KSM a, KSM b)
{
	KSM ans;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			ans.m[i][j] = 0LL;
			for (int k = 0; k < 2; k++)
				ans.m[i][j] = (ans.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
		}
	return ans;
}

long long work(long long k)
{
	ans.m[0][0] = 1LL;
	ans.m[0][1] = 1LL;
	ans.m[1][0] = 1LL;
	ans.m[1][1] = 0LL;
	base.m[0][0] = 1LL;
	base.m[0][1] = 1LL;
	base.m[1][0] = 1LL;
	base.m[1][1] = 0LL;
	while (k)
	{
		if (k & 1LL) ans = multiply(ans, base);
		base = multiply(base, base);
		k >>= 1LL;
	}
	return ans.m[0][1] % MOD;
}

int main()
{
	//freopen("gcd.in","r",stdin);freopen("gcd.out","w",stdout);
	scanf("%lld", &k);
	if (!k) printf("0 1\n");
	else if (k == 1) printf("1 1\n");
	else printf("%lld %lld\n", work(k), work(k + 1));
	return 0;
}
