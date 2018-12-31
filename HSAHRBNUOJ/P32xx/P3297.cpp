#include <cstdio>
#include <cstring>
#define MAXL 110
using namespace std;

struct KSM
{
	long long m[2][2];
};

const long long MOD = 1000000007LL;
const long long MOD2 = MOD * 2LL + 2LL;
const long long MOD3 = MOD2 * 3LL;

KSM ans, base;
long long w;
int T, len;
char num[MAXL];

KSM multiply1(KSM a, KSM b)
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

KSM multiply(KSM a, KSM b)
{
	KSM ans;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			ans.m[i][j] = 0LL;
			for (int k = 0; k < 2; k++)
				ans.m[i][j] = (ans.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD2;
		}
	return ans;
}

long long quick_M1(long long k)
{
	if (k < 0) return 0LL;
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
		if (k & 1LL) ans = multiply1(ans, base);
		base = multiply1(base, base);
		k >>= 1LL;
	}
	return ans.m[0][1];
}

long long quick_M(long long k)
{
	if (k < 0) return 0LL;
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
	return ans.m[0][1];
}

long long getnum()
{
	long long res = 0;
	len = strlen(num);
	for (int i = 0; i < len; i++) res = (res * 10LL + num[i] - '0') % MOD3;
	return res;
}

int main()
{
	//freopen("na.in","r",stdin);freopen("na.out","w",stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", num);
		w = getnum();
		printf("%lld\n", quick_M1(quick_M(w - 1) - 1));
	}
	return 0;
}
