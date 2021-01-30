#include <bits/stdc++.h>
using namespace std;

unordered_map <long long, long long> mp;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long res = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return res;
}

inline long long inv(long long a, long long m)
{
	long long x, y;
	exgcd(a, m, x, y);
	return (x + m) % m;
}

long long exBSGS(long long a, long long b, long long M)
{
	if (b == 1) return 0;
	long long w = 1; int c = 0;
	for (long long d; (d = __gcd(a, M)) != 1;)
	{
		if (b % d) return -1;
		b /= d; M /= d; ++c; w = w * (a / d) % M;
		if (w == b) return c;
	}
	b = b * inv(w, M) % M; mp.clear();
	long long t = 1LL, r = b, x, y, B = ceil(sqrt(M));
	for (long long i = 0; i < B; i++, t = t * a % M) if (!mp.count(t)) mp.insert({t, i});
	t = inv(t, M);
	for (long long i = 0; i < B; i++, b = b * t % M) if (mp.count(b)) return i * B + mp[b] + c;
	return -1LL;
}

int main(int argc, char const *argv[])
{
	int a,b,c;
	while (scanf("%d %d %d",&a,&c,&b)==3)
	{
		if (b>=c)
		{
			puts("Orz,I can’t find D!");
			continue;
		}
		long long res=exBSGS(a,b,c);
		if (res==-1) puts("Orz,I can’t find D!");
		else printf("%lld\n",res);
	}
	return 0;
}