#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;

char a[MAXN], b[MAXN];
long long ans, n, m, la, lb, g, cnt[26];

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	scanf("%lld %lld", &n, &m);
	scanf("%s", a);
	scanf("%s", b);
	la = strlen(a);
	lb = strlen(b);
	g = gcd(la, lb);
	for (int i = 0; i < g; i++)
	{
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < la / g; j++) cnt[a[j * g + i] - 'a']++;
		for (int j = 0; j < lb / g; j++) ans += cnt[b[j * g + i] - 'a'];
	}
	ans = ans * (n * g / lb);
	printf("%lld\n", ans);
	return 0;
}
