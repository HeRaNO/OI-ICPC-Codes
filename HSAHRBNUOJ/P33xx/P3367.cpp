#include <map>
#include <queue>
#include <cstdio>
#define MAXN 100010
#define MAXM 1030
#define MOD 1000000007LL
using namespace std;

int n, k;
int a, ten[11];
long long fac[MAXN];
long long inv[MAXN], invfac[MAXN];
long long p[MAXM], cnt, u, unlucky;
long long amt[MAXM], ans, s, t;
long long dp[MAXM][MAXM];
queue <long long> q;
map <long long, int> m;
map <long long, int> :: iterator it;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void Lucky()
{
	q.push(0);
	while (true)
	{
		u = q.front();
		if (u > 1e9) break;
		if (u) p[cnt++] = u;
		q.pop();
		q.push(u * 10 + 4);
		q.push(u * 10 + 7);
	}
	for (int i = 0; i < cnt; i++) m[p[i]] = i;
	return ;
}

long long C(long long n, long long m)
{
	long long res = fac[n];
	res = res * invfac[m] % MOD;
	res = res * invfac[n - m] % MOD;
	return res;
}

int main()
{
	//freopen("lucky.in","r",stdin);freopen("lucky.out","w",stdout);
	ten[0] = 1;
	for (int i = 1; i <= 10; i++) ten[i] = ten[i - 1] * 10;
	Lucky();
	scanf("%d %d", &n, &k);
	unlucky = n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		it = m.find(a);
		if (it != m.end())
		{
			amt[it->second]++;
			unlucky--;
		}
	}
	dp[0][0] = 1LL;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
			dp[i + 1][j + 1] += (dp[i + 1][j + 1] + (dp[i][j] * amt[i] % MOD)) % MOD;
			dp[i + 1][j + 1] %= MOD;
		}
	}
	inv[1] = 1LL;
	for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1LL;
	for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
	invfac[0] = 1LL;
	for (int i = 1; i <= n; i++) invfac[i] = (invfac[i - 1] * inv[i]) % MOD;
	s = mymax(0, k - cnt);
	t = mymin(k, unlucky);
	for (int i = s; i <= t; i++)
		ans = (ans + dp[cnt][k - i] * C(unlucky, i) % MOD) % MOD;
	printf("%lld\n", ans);
	return 0;
}
