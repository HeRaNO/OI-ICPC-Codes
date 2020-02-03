#include <cstdio>
using namespace std;
int main()
{
	int n, x, tmp, i, t;
	long long ans = 0;
	scanf("%d %d", &n, &x);
	for (i = 1; i <= n; i++)
	{
		if (i == x)
		{
			ans++;
			continue;
		}
		t = i;
		while (t != 0)
		{
			tmp = t % 10;
			if (tmp == x) ans++;
			t /= 10;
		}
	}
	printf("%lld", ans);
	return 0;
}