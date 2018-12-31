#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

int n, a[MAXN], l = 1, ans, cnt, m;
pair <int, int *> b[MAXN];
bool f[MAXN];

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i].first = a[i];
		b[i].second = &a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first) ++m;
		*b[i].second = m;
	}
	for (int r = 1; r <= n; r++)
	{
		if (!f[a[r]]) max(ans, ++cnt);
		else
		{
			while (a[l] != a[r]) f[a[l++]] = false;
			cnt = r - l;
		}
		f[a[r]] = true;
	}
	printf("%d\n", ans);
	return 0;
}