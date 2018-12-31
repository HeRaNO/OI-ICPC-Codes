#include <cstdio>
#include <iostream>
using namespace std;

int n, m, x, cnt[110], ans;
bool cal[110];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		++cnt[x % m];
	}
	if (cnt[0]) ans += cnt[0] - 1;
	for (int i = 1; i < m; i++)
	{
		if (cal[i]) break;
		if (m == (i << 1) && cnt[i]) ans += cnt[i] - 1;
		else if (cnt[i] && cnt[m - i])
		{
			int a = min(cnt[i], cnt[m - i]);
			int b = max(cnt[i], cnt[m - i]);
			ans += (a << 1);
			if (a == b) --ans;
		}
		cal[i] = true;
		cal[m - i] = true;
	}
	printf("%d\n", ans);
	return 0;
}