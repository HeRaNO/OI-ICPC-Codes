#include <cstdio>
#define T 9
using namespace std;

const long long prime[T] = {0, 2, 3, 5, 7, 11, 13, 17, 19};
long long n;
long long sum, ans;
long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

void dfs(int dep, int k, int M, long long now)
{
	if (dep == T || !M)
	{
		if (k == sum)
			ans = mymin(now, ans);
		else if (k > sum)
		{
			sum = k;
			ans = now;
		}
		return ;
	}
	int i = 0;
	while (true)
	{
		dfs(dep + 1, k * (i + 1), i, now);
		if (now * prime[dep] <= n) now *= prime[dep];
		else return ;
		i++;
		if (i > M) return ;
	}
}

int main()
{
	scanf("%lld", &n);
	dfs(1, 1, 100, 1LL);
	printf("%d\n", ans);
	return 0;
}
