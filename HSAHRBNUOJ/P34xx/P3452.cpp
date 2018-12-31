#include <cstdio>
#include <cstring>
#define MAXN 100010
#define MOD 1000000007LL
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXN * 2];
int tree[MAXN * 32 * 2][2], dep[MAXN * 2 * 32], cnt[MAXN * 32 * 2];
int n, val, u, v, x, top, root;
int edge_num[MAXN], edgecnt;
int father[MAXN], tire_father[MAXN];
int seq[MAXN];
bool vis[MAXN];
long long res, ans[MAXN], coll[MAXN * 32];

inline int newnode(int d)
{
	dep[top] = d;
	return top++;
}

inline void add(int u, int v)
{
	e[edgecnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = edgecnt++;
	e[edgecnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = edgecnt++;
}

inline void add_tire(int x, int num)
{
	cnt[x]++;
	for (int i = 30; ~i; i--)
	{
		int t = (num >> i) & 1;
		if (tree[x][t] == -1) tree[x][t] = newnode(i);
		cnt[x = tree[x][t]]++;
	}
	return ;
}

inline int merge_tire(int u, int v)
{
	if (u == -1) return v;
	if (v == -1) return u;
	tree[u][0] = merge_tire(tree[u][0], tree[v][0]);
	tree[u][1] = merge_tire(tree[u][1], tree[v][1]);
	coll[u] = (coll[tree[u][0]] + coll[tree[u][1]] + (1LL << dep[u] - 1) % MOD * cnt[tree[u][0]] % MOD * cnt[tree[u][1]] % MOD) % MOD;
	cnt[u] += cnt[v];
	return u;
}

inline int getfather(int x)
{
	return x == father[x] || father[x] == 0 ? x : getfather(father[x]);
}
inline void combine(int u, int v)
{
	if (getfather(u) != getfather(v))
	{
		tire_father[getfather(v)] = merge_tire(tire_father[getfather(v)], tire_father[getfather(u)]);
		father[getfather(u)] = getfather(v);
	}
	return ;
}

inline long long query(int x)
{
	return coll[tire_father[getfather(x)]];
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	//freopen("birthday.in","r",stdin);freopen("birthday.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	memset(tree, -1, sizeof tree);
	read(n);
	top = n + 1;
	for (int i = 1; i <= n; i++) father[i] = tire_father[i] = i, dep[i] = 31;
	for (int i = 1; i <= n; i++)
	{
		read(x);
		add_tire(i, x);
	}
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++) read(seq[i]);
	for (int i = n; i; i--)
	{
		vis[seq[i]] = true;
		for (int j = edge_num[seq[i]]; ~j; j = e[j].nxt)
			if (vis[e[j].to])
			{
				res = (res + MOD - query(getfather(e[j].to))) % MOD;
				combine(e[j].to, seq[i]);
			}
		res = (res + query(getfather(seq[i]))) % MOD;
		ans[i] = res;
	}
	for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
	return 0;
}
