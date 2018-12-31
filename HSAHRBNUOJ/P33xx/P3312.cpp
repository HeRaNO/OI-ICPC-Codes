#include <cstdio>
#define MAXN 1000010
using namespace std;

int n, m;
long long p, ans = 1LL;
int cnt[MAXN], v[MAXN], d[MAXN];

int main()
{
	scanf("%d %d %lld", &n, &m, &p);
	for (int i = m + 1; i <= n; i++) cnt[i] = 1;
	for (int i = 1; i <= n - m; i++) cnt[i] -= 1;
	for (int i = 2; i <= n; i++)
		if (!v[i])
		{
			for (int j = i + i; j <= n; j += i)
			{
				v[j] = i;
				d[j] = i;
			}
		}
	for (int i = n; i >= 2; i--)
		if (d[i])
		{
			cnt[d[i]] += cnt[i];
			cnt[i / d[i]] += cnt[i];
			cnt[i] = 0;
		}
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= cnt[i]; j++)
			ans = ans * i % p;
	printf("%lld\n", ans);
	return 0;
}
