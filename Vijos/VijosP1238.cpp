#include <cstdio>
#define MAXN 5000010
using namespace std;

long long t[MAXN];
long long l, r, p, ans, cnt, tt;
int n, m;

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d %d %lld", &n, &m, &p);
	p++;
	tt = mymin(m, p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %lld", &l, &r);
		t[l]++;
		t[r + 1]--;
	}
	for (int i = 0; i < MAXN; i++)
	{
		cnt += t[i];
		ans += mymin(cnt, tt);
	}
	printf("%lld\n", ans);
	return 0;
}