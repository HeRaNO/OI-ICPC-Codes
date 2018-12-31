#include <set>
#include <cstdio>
#define MAXN 11
#define MAXM 50
using namespace std;

int n, m, ans[MAXN], x;
multiset <int> a, y;
multiset <int> :: iterator it;

int main()
{
	scanf("%d", &n);
	m = n * (n - 1) >> 1;
	for (int i = 1; i <= m; i++) scanf("%d", &x), y.insert(x);
	x = *y.begin();
	x >>= 1;
	for (int mn = 0; mn <= x; mn++)
	{
		a = y;
		ans[1] = mn;
		bool fail = false;
		for (int i = 2; i <= n && !fail; i++)
		{
			ans[i] = *a.begin() - ans[1];
			a.erase(a.begin());
			for (int j = i - 1; j >= 2 && !fail; j--)
			{
				it = y.find(ans[i] + ans[j]);
				if (it != y.end())
				{
					it = a.find(ans[i] + ans[j]);
					if (it != a.end()) a.erase(it);
				}
				else fail = true;
			}
		}
		if (!fail)
		{
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
				{
					it = a.find(ans[i] + ans[j]);
					if (it != a.end()) a.erase(it);
				}
			if (a.empty())
			{
				for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
				return 0;
			}
		}
	}
	puts("Impossible");
	return 0;
}