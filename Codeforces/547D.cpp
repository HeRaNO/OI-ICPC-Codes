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
int n;
int x[N], y[N];
int in[N], out[N];
// vector<int> e[N];
int top;
int ans[N];
bool vis[N];
bool odd_du[N];
int Ans[N];
pair<int, int> id[N];
int cnt;
struct edge
{
	int u, v, nxt, ID, id2;
	bool f;
} e[N << 1];
int head[N], ecnt = 1;
inline void ad(int u, int v)
{
	e[++ecnt].v = v;
	e[ecnt].nxt = head[u], head[u] = ecnt;
}
void dfs(int u)
{
	for (int &i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		int nowid = (i >> 1);
		if (!vis[nowid])
		{
			vis[nowid] = 1;
			if (nowid <= n)
				Ans[nowid] = (i & 1);
			dfs(v);
		}
	}
}

void solve()
{
	memarray(head, -1);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &x[i], &y[i]), y[i] += 200000;
	for (int i = 1; i <= n; ++i)
	{
		ad(x[i], y[i]);
		ad(y[i], x[i]);
		in[x[i]]++;
		in[y[i]]++;
	}
	for (int i = 1; i <= 400000; ++i)
		if (in[i] & 1)
			ad(0, i), ad(i, 0);
	for (int i = 1; i <= 400000; ++i)
		dfs(i);
	for (int i = 1; i <= n; ++i)
		printf("%c", (Ans[i] & 1) ? 'r' : 'b');
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