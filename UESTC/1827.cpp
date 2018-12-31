#include <stdio.h>

int main()
{
	int n, p, q, ans = 0;
	scanf("%d %d %d", &n, &p, &q);
	ans += (n >> 1);
	n -= ((n >> 1) << 1);
	if (n)
	{
		if (!p && !q) ++ans;
		else if ((!p && q) || (p && !q))
		{
			q += p;
			--q;
			if (q % 4) ans += (q >> 2) + 2;
			else ans += (q >> 2) + 1;
		}
		else
		{
			--p;
			--q;
			p += q;
			if (p % 4) ans += (p >> 2) + 2;
			else ans += (p >> 2) + 1;
		}
	}
	else
	{
		if ((p + q) % 4) ans += (p + q) / 4 + 1;
		else ans += (p + q) / 4;
	}
	printf("%d\n", ans);
	return 0;
}