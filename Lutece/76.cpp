#include <bits/stdc++.h>
using namespace std;

int n, m, x, mx;
bool f;

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (i != n) mx = max(mx, x);
		if (m <= x)
		{
			if (f || m + mx <= x) return puts("NO"), 0;
			else
			{
				f = true;
				m += mx;
			}
		}
		m -= x;
		m += 6;
	}
	puts("YES");
	return 0;
}
