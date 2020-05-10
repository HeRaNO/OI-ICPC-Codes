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
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int k, n, m;
vector<int> e[N], g[N];
bool vis[N];
int dep[N], in[N];
int father[N];
int root;
int mxdep;
int rt1, rt2;
void dfs_tree(int u)
{
	vis[u] = 1;
	for (auto &v : e[u])
	{
		if (vis[v])
			continue;
		g[u].push_back(v);
		g[v].push_back(u);
		in[u]++, in[v]++;
		dfs_tree(v);
	}
}
void dfs(int u, int fa)
{
	if (dep[u] > mxdep)
		mxdep = dep[u], root = u;
	for (auto &v : g[u])
	{
		if (v == fa)
			continue;
		dep[v] = dep[u] + 1;
		father[v] = u;
		dfs(v, u);
	}
}
int pre_PATH[N];
void dfs_PATH(int u, int fa)
{
	for (auto &v : g[u])
	{
		if (v == fa)
			continue;
		dfs_PATH(v, u);
		pre_PATH[v] = u;
	}
}
int pre_huan[N];
int cnt_huan;
void dfs_cycle(int u, int goal)
{
	cnt_huan++;
	if (goal == u)
		return;
	for (auto &v : g[u])
	{
		if (dep[v] > dep[u])
			continue;
		pre_huan[v] = u;
		dfs_cycle(v, goal);
	}
}

bool solvePATH()
{
	dfs_tree(1);
	dfs(1, 0);
	rt1 = root;
	mxdep = 0;
	memarray(dep, 0);
	dfs(root, 0);
	rt2 = root;
	if ((ll)mxdep * k > n)
	{
		puts("PATH");
		printf("%d\n", mxdep + 1);
		dfs_PATH(rt2, 0);
		for (int i = rt1; i; i = pre_PATH[i])
			printf("%d ", i);
		return true;
	}
	return false;
}

void solveCYCLE()
{
	puts("CYCLES");
	for (int i = 0; i <= n; ++i)
		g[i].clear();
	memarray(dep, 0);
	memarray(vis, 0);
	memarray(in, 0);
	dfs_tree(1);
	dfs(1, 0);
	int tot_huan = 0;
	for (int u = 2; u <= n; ++u)
	{
		if (in[u] != 1)
			continue;
		int tot = 0;
		int f1 = 0, f2 = 0;
		bool flag = false;
		for (auto &v : e[u])
		{
			if (v == father[u])
				continue;
			tot++;
			cnt_huan = 0;
			if (!f1)
				f1 = v;
			else
				f2 = v;
			if (tot > 2)
				break;
			if (dep[u] - dep[v] + 1 > 3)
			{
				if ((dep[u] - dep[v] + 1) % 3 == 0)
					continue;
				flag = true;
				cnt_huan = 0;
				dfs_cycle(u, v);
				printf("%d\n", cnt_huan);
				printf("%d ", u);
				for (int i = v; i != u; i = pre_huan[i])
					printf("%d ", i);
				puts("");
				tot_huan++;
				if (tot_huan == k)
					return;
				break;
			}
		}
		if (flag == false)
		{
			if (dep[f1] < dep[f2])
				swap(f1, f2);
			dfs_cycle(f1, f2);
			printf("%d\n", cnt_huan + 1);
			printf("%d ", u);
			for (int i = f2; i != f1; i = pre_huan[i])
				printf("%d ", i);
			printf("%d\n", f1);
			tot_huan++;
		}
		if (tot_huan == k)
			return;
	}
}

void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	if (solvePATH())
		return;
	solveCYCLE();
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