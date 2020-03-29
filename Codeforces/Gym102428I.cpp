#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
using namespace std;
const int N = 2050;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
vector<int> e[N], g[N];
int f[N];
int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }
int n, L, cnt;
ll dp[N];
int in[N];
bool vis[N];
bool vis2[N];
queue<int> q;

void topsort()
{
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : g[u])
		{
			dp[v] += dp[u];
			dp[v] %= mod;
			in[v]--;
			if (in[v] == 0 && vis[v] == 0)
			{
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}
void dfs(int u)
{
	if (vis[u])
		return;
	if (u > L)
	{
		vis2[u] = 1;
		return;
	}
	vis[u] = 1;
	for (auto v : e[u])
	{
		if (!vis[v])
			dfs(v);
	}
}

void solve()
{
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 1; i <= L; ++i)
	{
		int k;
		scanf("%d", &k);
		while (k--)
		{
			int x;
			scanf("%d", &x);
			e[i].push_back(x);
			g[x].push_back(i);
			in[i]++;
		}
	}
	for (int i = L + 1; i <= n; ++i)
		dp[i] = 1, q.push(i), vis[i] = 1;
	topsort();
	mem(vis, 0, n, bool);
	dfs(1);
	for (int i = L + 1; i <= n; ++i)
		cnt += vis2[i];
	printf("%lld %d\n", dp[1], cnt);
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