#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, d, l, r, ans1, ans2;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ans1 = 0;
		ans2 = 0;
		scanf("%d %d %d %d %d %d %d %d", &n, &m, &l, &r, &a, &b, &c, &d);
		if (a == c)
		{
			printf("%d\n", abs(d - b));
			continue;
		}
		if (1 <= b && b <= l)
			ans1 = abs(c - a) + abs(d - b);
		else ans1 = b - l + abs(c - a) + abs(d - l);
		if (r <= b && b <= m)
			ans2 = abs(c - a) + abs(d - b);
		else ans2 = r - b + abs(c - a) + abs(d - r);
		printf("%lld\n", min(ans1, ans2));
	}
	return 0;
}
