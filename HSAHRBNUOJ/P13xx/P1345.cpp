#include <cstdio>
#include <cstring>
#define MAXN 65536
using namespace std;

int a[MAXN], tmp[MAXN];
int x, MAX, ans;
int n, m;
int cnt[MAXN];

void dp(int k)
{
	int a, tot = cnt[k];
	for (int i = 2; i <= n; i++)
	{
		a = tmp[i - 1] ^ MAX;
		tmp[i] ^= a;
		tmp[i] ^= (a << 1)&MAX;
		tmp[i] ^= a >> 1;
		tmp[i + 1] ^= a;
		tot += cnt[a];
	}
	if (tmp[n] == MAX)
		if (ans > tot) ans = tot;
}

int solve(int k)
{
	int sum = 0;
	while (k)
	{
		if (k & 1) sum++;
		k >>= 1;
	}
	return sum;
}

int main()
{
	scanf("%d %d", &n, &m);
	MAX = (1 << m) - 1;
	ans = 2147483647;
	for (int i = 0; i <= MAX; i++) cnt[i] = solve(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &x);
			a[i] = (a[i] << 1) | x;
		}
	for (int i = 0; i <= (1 << m); i++)
	{
		memcpy(tmp, a, sizeof(a));
		tmp[1] ^= i;
		tmp[1] ^= (i << 1)&MAX;
		tmp[1] ^= i >> 1;
		tmp[2] ^= i;
		dp(i);
	}
	if (ans == 2147483647) printf("no solution\n");
	else printf("%d\n", ans);
	return 0;
}
