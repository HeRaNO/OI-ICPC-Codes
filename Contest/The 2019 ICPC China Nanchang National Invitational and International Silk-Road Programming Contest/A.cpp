#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, m, k, ans[260];
map<string, int> name;
int a[35][35];
pair<int, int> pc[5];
typedef pair<int, int> P;
const int maxn = 40, maxm = 2050;
struct edge
{
	int to, nxt, w;
} e[maxm << 1];

int head[maxm],tot;
int dp[maxn][260], vis[maxn];
int key[maxn];
queue<int> q;

inline void add(int u, int v, int w)
{
	e[++tot] = edge{v, head[u], w};
	head[u] = tot;
}

void dijkstra(int s)
{
	// memset(vis, 0, sizeof(vis));
	while (!q.empty())
	{
		int item = q.front();
		q.pop();
		vis[item] = 0;
		for (int i = head[item]; i; i = e[i].nxt)
		{
			int v = e[i].to;
			if (dp[v][s] > dp[item][s] + e[i].w)
			{
				dp[v][s] = dp[item][s] + e[i].w;
				if (!vis[v])
					q.push(v), vis[v] = 1;
			}
		}
	}
}

void work(int nowst)
{
	memset(dp, inf, sizeof(dp));
	memarray(ans, inf);
	// scanf("%d %d %d", &n, &m, &k);
	k = 0;
	memarray(key, 0);
	// for (int i = 1; i <= m; i++)
	// {
	//     // scanf("%d %d %d", &u, &v, &w);
	//     add(u, v, w);
	//     tree[tot] = v;
	//     add(v, u, w);
	//     tree[tot] = u;
	// }
	for (int i = 0; i < 4; ++i)
	{
		key[++k] = pc[i].first, key[++k] = pc[i].second;
	}
	for (int i = 1; i <= k; i++)
		dp[key[i]][1 << (i - 1)] = 0;
	for (int s = 1; s < (1 << k); s++)
	{
		memarray(vis, 0);
		for (int i = 1; i <= n; i++)
		{
			for (int subs = s & (s - 1); subs; subs = s & (subs - 1))
				dp[i][s] = min(dp[i][s], dp[i][subs] + dp[i][s ^ subs]);
			if (dp[i][s] != inf)
				q.push(i), vis[i] = 1;
		}
		dijkstra(s);
		bool f = 1;
		for (int j = 0; j < 8; j++)
		{
			if (((1 << j) & s) && !((1 << (j ^ 1)) & s))
				f = 0;
		}
		if (f)
		{
			for (int i = 1; i <= n; ++i)
			{
				ans[s] = min(ans[s], dp[i][s]);
				//cout << i<<" "<<s<<" "<<dp[i][s] << endl;
			}
			//cout << s<<" "<<ans[s] << endl;
		}
	}
	// ans[nowst] = dp[key[1]][(1 << k) - 1];
}

inline void solve()
{
	memarray(a, inf);
	scanf("%d%d", &n, &m);
	int nodetot = 0;
	for (int i = 1; i <= n; ++i)
	{
		string nowname;
		cin >> nowname;
		if (!name.count(nowname))
			name.insert(mp(nowname, ++nodetot));
	}
	n = nodetot;
	for (int i = 1; i <= m; ++i)
	{
		string x, y;
		int cost;
		cin >> x >> y >> cost;
		assert(cost > 0);
		if (x == y)
			continue;
		int nx = name[x], ny = name[y];
		a[nx][ny] = a[ny][nx] = min(a[nx][ny], cost);
	}
	for (int i = 0; i < 4; ++i)
	{
		string x, y;
		cin >> x >> y;
		int nx = name[x], ny = name[y];
		pc[i] = mp(nx, ny);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (a[i][j] < inf)
			{
				add(i, j, a[i][j]);
				add(j, i, a[i][j]);
			}
	work(15);
	int finalans = inf;
	for (int S = 0; S < st(8); S++)
	{
		for (int s = S; s; s = (s - 1) & S)
		{
			ans[S] = min(ans[S], ans[s] + ans[S ^ s]);
		}
	}
	finalans = ans[st(8) - 1];
	printf("%d\n", finalans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
	{
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}