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
#define Flush fflush(stdout)
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
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
vector<int> g1, g2;
int ans;
int du[N];
void dfs(int u, int fa)
{
	if (du[u] == 1)
	{
		if (g1.size() >= (ans + 1) / 2)
			g2.push_back(u);
		else
			g1.push_back(u);
		return;
	}
	for (auto v : e[u])
	{
		if (v != fa)
			dfs(v, u);
	}
}

void solve()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		du[x]++, du[y]++;
	}
	for (int i = 1; i <= n; ++i)
		if (du[i] == 1)
			ans++;
	printf("%d\n", (ans + 1) / 2);
	if (n == 2)
		return puts("1 2"), void();
	for (int i = 1; i <= n; ++i)
	{
		if (du[i] != 1)
		{
			dfs(i, 0);
			break;
		}
	}
	int i = 0, j = 0;
	for (; i < g1.size() && j < g2.size(); ++i, ++j)
	{
		printf("%d %d\n", g1[i], g2[j]);
	}
	if (i < g1.size())
		printf("%d %d\n", g1[i], g2[0]);
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