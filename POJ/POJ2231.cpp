#include <cstdio>
#include <algorithm>
#define MAXN 10010
using namespace std;

long long cow[MAXN];
int n;
long long ans;

int main()
{
	while (~scanf("%d", &n))
	{
		ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &cow[i]);
		sort(cow + 1, cow + n + 1);
		for (int i = 1; i < n; i++)
			ans = ans + (cow[i + 1] - cow[i]) * i * (n - i);
		printf("%lld\n", ans * 2);
	}
	return 0;
}
