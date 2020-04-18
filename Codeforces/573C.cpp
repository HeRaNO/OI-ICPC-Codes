#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
using namespace std;
const int N = 100050;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}

int n;
vector<int> e[N];
int d[N];
int vis[N];
void pa(int u, int fa)
{
	if (e[u].size() < 3)
	{
		vis[u] = 1;
		for (auto v : e[u])
		{
			if (v == fa)
				continue;
			pa(v, u);
		}
	}
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	for (int i = 1; i <= n; ++i)
		if (e[i].size() == 1)
			pa(i, 0);
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			for (auto v : e[i])
				if (vis[v])
					d[i]++;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			int tot = 0;
			for (auto v : e[i])
			{
				if (vis[v])
					continue;
				if (e[v].size() > min(d[v] + 1, 3))
					tot++;
			}
			if (tot >= 3)
				return puts("No"), void();
		}
	}
	puts("Yes");
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}