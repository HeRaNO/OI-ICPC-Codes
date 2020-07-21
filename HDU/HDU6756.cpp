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
const int N = 100002;
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
int n, m;
vector<int> e[N], ee[N];
int du[N], a[N];
bitset<1002> mex;
int ID[N], tot;
int T, Q;
struct segtree
{
	int sum, val;
} t[101][N << 2];
inline void pushup(int id, int p)
{
	t[p][id].val = t[p][ls].val + t[p][rs].val;
	// t[p][id].val = (t[p][id].sum > 0);
}
void build(int l, int r, int id, int p)
{
	// t[p][id].l = l, t[p][id].r = r;
	t[p][id].sum = t[p][id].val = 0;
	if (l == r)
	{
		// t[p][id].sum = t[p][id].val = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls, p);
	build(mid + 1, r, rs, p);
	pushup(id, p);
}
void change(int l, int r, int id, int pos, int v, int p)
{
	if (l == pos && r == pos)
	{
		t[p][id].sum += v;
		t[p][id].val = (t[p][id].sum > 0);
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid)
		change(l, mid, ls, pos, v, p);
	else
		change(mid + 1, r, rs, pos, v, p);
	pushup(id, p);
}
int query(int l, int r, int id, int p)
{
	if (l == r)
		return l;
	int lsum = t[p][ls].val;
	int mid = (l + r) >> 1;
	if (lsum == (mid + 1 - l))
		return query(mid + 1, r, rs, p);
	else
		return query(l, mid, ls, p);
}

void solve()
{
	tot = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		e[i].resize(0), ee[i].resize(0);
	mem(du, 0, n, int);
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		du[x]++, du[y]++;
	}
	T = 1000;
	for (int i = 1; i <= n; ++i)
	{
		if (du[i] >= T)
		{
			++tot;
			ID[i] = tot;
			build(1, e[i].size() + 2, 1, tot);
			for (auto v : e[i])
			{
				if (a[v] + 1 <= e[i].size() + 2)
					change(1, e[i].size() + 2, 1, a[v] + 1, 1, tot);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (auto v : e[i])
		{
			if (du[v] >= T)
				ee[i].push_back(v);
		}
	}
	scanf("%d", &Q);
	while (Q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int u, val;
			scanf("%d%d", &u, &val);
			for (auto v : ee[u])
			{
				if (a[u] + 1 <= e[v].size() + 2)
					change(1, e[v].size() + 2, 1, a[u] + 1, -1, ID[v]);
				if (val + 1 <= e[v].size() + 2)
					change(1, e[v].size() + 2, 1, val + 1, 1, ID[v]);
			}
			a[u] = val;
		}
		else if (op == 2)
		{
			int u;
			scanf("%d", &u);
			if (du[u] < T)
			{
				mex.reset();
				for (auto v : e[u])
					if (a[v] < du[u])
						mex[a[v]] = 1;
				for (int i = 0; i <= du[u] + 2; ++i)
					if (mex[i] == 0)
					{
						printf("%d\n", i);
						break;
					}
			}
			else
			{
				int ans = query(1, e[u].size() + 2, 1, ID[u]);
				printf("%d\n", ans - 1);
			}
		}
	}
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}