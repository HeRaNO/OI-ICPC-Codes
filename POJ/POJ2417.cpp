#include <cmath>
#include <cstdio>
#include <cstring>
#define HMOD 1000007LL
using namespace std;

struct hash_link
{
	long long ori;
	long long val;
	int nxt;
};

hash_link e[HMOD << 2];
int edge_num[HMOD], cnt;
long long a, b, MOD;

inline void add(long long x, long long y)
{
	long long ori = x;
	x %= HMOD;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].ori == ori) return ;
	e[cnt] = (hash_link)
	{
		ori, y, edge_num[x]
	};
	edge_num[x] = cnt++;
	return ;
}

inline long long query(long long x)
{
	long long ori = x;
	x %= HMOD;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].ori == ori) return e[i].val;
	return -1LL;
}

void exgcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return ;
	}
	exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - (a / b) * y;
	return ;
}

long long exBSGS(long long a, long long b, long long MOD)
{
	memset(edge_num, -1, sizeof edge_num);
	cnt = 0;
	long long M = ceil(sqrt(MOD));
	long long t = 1LL, r = 1LL, x, y;
	for (long long i = 0; i < M; i++, t = t * a % MOD) add(t, i);
	for (long long i = 0; i <= M; i++, r = r * t % MOD)
	{
		exgcd(r, MOD, x, y);
		x = (x * b % MOD + MOD) % MOD;
		int res = query(x);
		if (res != -1) return i * M + res;
	}
	return -1LL;
}

int main()
{
	while (~scanf("%lld %lld %lld", &MOD, &a, &b))
	{
		long long ans = exBSGS(a, b, MOD);
		if (!~ans) puts("no solution");
		else printf("%lld\n", ans);
	}
	return 0;
}
