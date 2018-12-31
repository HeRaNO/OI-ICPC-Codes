#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 1010
#define MAXM 510
using namespace std;

int n, m, x, s[MAXN << 1], ans[MAXN];
bool a[MAXM];

inline void Output()
{
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
	exit(0);
}

void dfs(int x, int l, int r, int sl, int sr)
{
	if (l == r)
	{
		if (s[n << 1] - sl - sr < 1 || s[n << 1] - sl - sr > 500) return ;
		if (!a[s[n << 1] - sl - sr]) return ;
		ans[l] = s[n << 1] - sl - sr;
		Output();
	}
	if (s[x] - sl >= 1 && s[x] - sl <= 500)
	{
		if (a[s[x] - sl])
		{
			ans[l] = s[x] - sl;
			dfs(x + 1, l + 1, r, s[x], sr);
		}
	}
	if (s[x] - sr >= 1 && s[x] - sr <= 500)
	{
		if (a[s[x] - sr])
		{
			ans[r] = s[x] - sr;
			dfs(x + 1, l, r - 1, sl, s[x]);
		}
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= (n << 1); i++) read(s[i]);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(x);
		a[x] = true;
	}
	sort(s + 1, s + (n << 1) + 1);
	dfs(1, 1, n, 0, 0);
	puts("-1");
	return 0;
}