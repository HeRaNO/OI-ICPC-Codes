#include <cstdio>
using namespace std;

int T;
long long n, u, d;
long long ans = ~(1LL << 63);

inline long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%lld %d", &n, &T);
	while (T--)
	{
		scanf("%lld %lld", &u, &d);
		ans = mymin(ans, (u * n) % (u + d));
	}
	printf("%lld\n", ans);
	return 0;
}
