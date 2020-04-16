#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
#define lowbit(x) x & -x
#define pb push_back
#define ls (id << 1)
#define rs (id << 1 | 1)
#define Rint register int
#define UNI(x) sort(ALL(x)), x.resize(unique(ALL(x)) - x.begin())
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
const int MAXN = 4e5 + 10, MAXM = 4e6 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const ll llINF = LLONG_MAX;
const int MOD = 1004535809, mod = 998244353;
const int inv2 = 5e8 + 4;
const int Lim = 1 << 20;

struct ACautomaton
{
	struct Node
	{
		int fail, son[26];
	} t[MAXN];
	int cnt;
	void insert_Trie(char *s)
	{
		int u = 0, n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			if (!t[u].son[s[i] - 'a'])
			{
				t[u].son[s[i] - 'a'] = ++cnt;
				t[cnt].fail = 0;
			}
			u = t[u].son[s[i] - 'a'];
		}
	}
	void init()
	{
		for (int i = 0; i <= cnt; i++)
			memset(t[i].son, 0, sizeof(t[i].son));
	}
	queue<int> q;
	void getfail()
	{
		for (int i = 0; i < 26; i++)
			if (t[0].son[i])
				q.push(t[0].son[i]);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = 0; i < 26; i++)
			{
				if (t[u].son[i])
				{
					t[t[u].son[i]].fail = t[t[u].fail].son[i];
					q.push(t[u].son[i]);
				}
				else
					t[u].son[i] = t[t[u].fail].son[i];
			}
		}
	}
} G;

vector<int> g[MAXN];
int sz[MAXN], dfn[MAXN], tot;

void dfs(int u)
{
	sz[u] = 1;
	dfn[u] = ++tot;
	for (auto j : g[u])
	{
		dfs(j);
		sz[u] += sz[j];
	}
}

char s[MAXN];
vector<string> v;
int w[MAXN];

//If you want to write it right, you'd better not modify ANY CHARACTER in this code.

struct mxinfo
{
	int m, s, t;
	mxinfo() {}
	mxinfo(int _, int __, int ___) : m(_), s(__), t(___) {}
	mxinfo operator+(const mxinfo &a) const
	{
		mxinfo res;
		if (m > a.m)
		{
			res.m = m;
			res.t = t;
			res.s = max(s, a.m);
		}
		else if (m < a.m)
		{
			res.m = a.m;
			res.t = a.t;
			res.s = max(a.s, m);
		}
		else
		{
			res.m = a.m;
			res.t = t + a.t;
			res.s = max(s, a.s);
		}
		return res;
	}
};

struct mninfo
{
	int m, s, t;
	mninfo() {}
	mninfo(int _, int __, int ___) : m(_), s(__), t(___) {}
	mninfo operator+(const mninfo &a) const
	{
		mninfo res;
		if (m < a.m)
		{
			res.m = m;
			res.t = t;
			res.s = min(s, a.m);
		}
		else if (m > a.m)
		{
			res.m = a.m;
			res.t = a.t;
			res.s = min(a.s, m);
		}
		else
		{
			res.m = a.m;
			res.t = t + a.t;
			res.s = min(s, a.s);
		}
		return res;
	}
};

struct SegmentTreeBeats
{
	int p, r, m;
	long long x, lazy;
	mxinfo mx;
	mninfo mn;
};

SegmentTreeBeats tree[1 << 20];
int n, m, o, l, r, x, a[MAXN];

inline void PushUp(int u)
{
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
	tree[u].mn = tree[u << 1].mn + tree[u << 1 | 1].mn;
	tree[u].mx = tree[u << 1].mx + tree[u << 1 | 1].mx;
	return;
}

inline void addmax(int u, int v)
{
	tree[u].x += 1LL * tree[u].mn.t * (v - tree[u].mn.m);
	tree[u].mn.m = v;
	tree[u].mx.m = max(tree[u].mx.m, v);
	if (tree[u].mx.m == tree[u].mn.m)
	{
		tree[u].x = 1LL * (tree[u].r - tree[u].p) * v;
		tree[u].mn = mninfo(tree[u].mn.m, ~(1 << 31), tree[u].r - tree[u].p);
		tree[u].mx = mxinfo(tree[u].mx.m, 1 << 31, tree[u].r - tree[u].p);
	}
	else
		tree[u].mx.s = max(tree[u].mx.s, v);
	return;
}

inline void addmin(int u, int v)
{
	tree[u].x -= 1LL * tree[u].mx.t * (tree[u].mx.m - v);
	tree[u].mx.m = v;
	tree[u].mn.m = min(tree[u].mn.m, v);
	if (tree[u].mx.m == tree[u].mn.m)
	{
		tree[u].x = 1LL * (tree[u].r - tree[u].p) * v;
		tree[u].mn = mninfo(tree[u].mn.m, ~(1 << 31), tree[u].r - tree[u].p);
		tree[u].mx = mxinfo(tree[u].mx.m, 1 << 31, tree[u].r - tree[u].p);
	}
	else
		tree[u].mn.s = min(tree[u].mn.s, v);
	return;
}

inline void Lazy(int u, long long v)
{
	tree[u].lazy += v;
	tree[u].x += (tree[u].r - tree[u].p) * v;
	tree[u].mx.m += v;
	if (tree[u].mx.s != 1 << 31)
		tree[u].mx.s += v;
	tree[u].mn.m += v;
	if (tree[u].mn.s != ~(1 << 31))
		tree[u].mn.s += v;
	return;
}

inline void PushDown(int u)
{
	if (tree[u].lazy)
	{
		Lazy(u << 1, tree[u].lazy);
		Lazy(u << 1 | 1, tree[u].lazy);
		tree[u].lazy = 0LL;
	}
	if (tree[u << 1].mx.s < tree[u].mx.m && tree[u].mx.m < tree[u << 1].mx.m)
		addmin(u << 1, tree[u].mx.m);
	if (tree[u << 1].mn.m < tree[u].mn.m && tree[u].mn.m < tree[u << 1].mn.s)
		addmax(u << 1, tree[u].mn.m);
	if (tree[u << 1 | 1].mx.s < tree[u].mx.m && tree[u].mx.m < tree[u << 1 | 1].mx.m)
		addmin(u << 1 | 1, tree[u].mx.m);
	if (tree[u << 1 | 1].mn.m < tree[u].mn.m && tree[u].mn.m < tree[u << 1 | 1].mn.s)
		addmax(u << 1 | 1, tree[u].mn.m);
	return;
}

void BuildTree(int u)
{
	tree[u].lazy = 0;
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].x = 0;
		tree[u].mn = mninfo(0, ~(1 << 31), 1);
		tree[u].mx = mxinfo(0, 1 << 31, 1);
		return;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	BuildTree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	BuildTree(u << 1 | 1);
	PushUp(u);
	return;
}

inline void add(int u, int l, int r, int v)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		Lazy(u, v);
		return;
	}
	PushDown(u);
	if (r <= tree[u].m)
		add(u << 1, l, r, v);
	else if (tree[u].m <= l)
		add(u << 1 | 1, l, r, v);
	else
	{
		add(u << 1, l, tree[u].m, v);
		add(u << 1 | 1, tree[u].m, r, v);
	}
	PushUp(u);
	return;
}

inline void changemin(int u, int l, int r, int v)
{
	if (v >= tree[u].mx.m)
		return;
	if (tree[u].p == l && tree[u].r == r && v > tree[u].mx.s)
	{
		addmin(u, v);
		return;
	}
	if (tree[u].p + 1 == tree[u].r)
		return;
	PushDown(u);
	if (r <= tree[u].m)
		changemin(u << 1, l, r, v);
	else if (tree[u].m <= l)
		changemin(u << 1 | 1, l, r, v);
	else
	{
		changemin(u << 1, l, tree[u].m, v);
		changemin(u << 1 | 1, tree[u].m, r, v);
	}
	PushUp(u);
	return;
}

inline void changemax(int u, int l, int r, int v)
{
	if (v <= tree[u].mn.m)
		return;
	if (tree[u].p == l && tree[u].r == r && v < tree[u].mn.s)
	{
		addmax(u, v);
		return;
	}
	if (tree[u].p + 1 == tree[u].r)
		return;
	PushDown(u);
	if (r <= tree[u].m)
		changemax(u << 1, l, r, v);
	else if (tree[u].m <= l)
		changemax(u << 1 | 1, l, r, v);
	else
	{
		changemax(u << 1, l, tree[u].m, v);
		changemax(u << 1 | 1, tree[u].m, r, v);
	}
	PushUp(u);
	return;
}

inline long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r)
		return tree[u].x;
	PushDown(u);
	if (r <= tree[u].m)
		return query(u << 1, l, r);
	else if (tree[u].m <= l)
		return query(u << 1 | 1, l, r);
	else
		return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
}

inline int qmin(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r)
		return tree[u].mn.m;
	PushDown(u);
	if (r <= tree[u].m)
		return qmin(u << 1, l, r);
	else if (tree[u].m <= l)
		return qmin(u << 1 | 1, l, r);
	else
		return min(qmin(u << 1, l, tree[u].m), qmin(u << 1 | 1, tree[u].m, r));
}

inline int qmax(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r)
		return tree[u].mx.m;
	PushDown(u);
	if (r <= tree[u].m)
		return qmax(u << 1, l, r);
	else if (tree[u].m <= l)
		return qmax(u << 1 | 1, l, r);
	else
		return max(qmax(u << 1, l, tree[u].m), qmax(u << 1 | 1, tree[u].m, r));
}

void solve()
{
	memset(tr, 0, sizeof(tr));
	v.resize(0);
	G.cnt = tot = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%d", s, &w[i]);
		G.insert_Trie(s);
		string tmp(s);
		v.pb(tmp);
	}
	G.getfail();
	for (int i = 0; i <= G.cnt; i++)
		g[i].resize(0);
	for (int i = 1; i <= G.cnt; i++)
		g[G.t[i].fail].pb(i);
	dfs(0);
	int ans = -INF;
	tree[1].p = 1;
	tree[1].r = tot + 1;
	BuildTree(1);
	for (int i = 0; i < n; i++)
	{
		int u = 0, tmp = -INF;
		auto &j = v[i];
		for (auto k : j)
		{
			u = G.t[u].son[k - 'a'];
			int sum = query(1, dfn[u], dfn[u] + 1) + w[i + 1];
			tmp = max(tmp, sum);
		}
		ans = max(ans, tmp);
		changemax(1, dfn[u], dfn[u] + sz[u], tmp);
	}
	G.init();
	printf("%d\n", max(0, ans));
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
