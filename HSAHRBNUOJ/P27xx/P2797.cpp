#include <set>
#include <cstdio>
using namespace std;

int n, x;
set <int> a;
long long dp[3][1000], ans;

bool check(int x)
{
	int t = 1;
	while (t * 10 <= x) t *= 10;
	while (x)
	{
		for (int i = x; i; i /= 10)
			if (a.find(i) != a.end()) return false;
		x %= t;
		t /= 10;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		a.insert(x);
	}
	for (int i = 1000; i <= 1999; i++)
		if (check(i)) dp[0][i % 10]++;
	for (int i = 0; i <= 9999; i++)
		if (check(i)) dp[1][i % 1000] += dp[0][i / 1000];
	for (int i = 0; i <= 9999; i++)
		if (check(i)) dp[2][i % 100] += dp[1][i / 10];
	for (int i = 0; i <= 99999; i++)
		if (check(i)) ans += dp[2][i / 1000];
	printf("%lld\n", ans);
	return 0;
}
