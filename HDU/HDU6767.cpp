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
const int N = 1005;
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

struct link
{
	int to, rev, flow;
	long long val;
	link() {}
	link(int _to, int _rev, int _flow, long long _val) : to(_to), rev(_rev), flow(_flow), val(_val) {}
};

const int MAXN=N;
struct Mincost
{
	vector<link> g[MAXN];
	vector<link> e[MAXN];
	int n, m, u, v, S, T, flow, ptr[MAXN];
	long long dis[MAXN], ans;
	bool vis[MAXN];
	queue<int> q;
	inline void clear()
	{
		memarray(vis, 0);
		memarray(dis, 0);
		memarray(ptr, 0);
		while (!q.empty())
			q.pop();
		S = T = n = 0;
		flow = ans = 0;
		for (int i = 0; i < N; ++i)
			g[i].clear();
	}
	inline void add(int u, int v, long long c, int f)
	{
		g[u].push_back(link(v, g[v].size(), f, c));
		g[v].push_back(link(u, int(g[u].size()) - 1, 0, -c));
	}
	inline bool SPFA()
	{
		memset(dis, 0x3f, sizeof dis);
		memset(vis, false, sizeof vis);
		q.push(S);
		dis[S] = 0;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			vis[u] = false;
			for (auto &e : g[u])
				if (e.flow && dis[e.to] > dis[u] + e.val)
				{
					dis[e.to] = dis[u] + e.val;
					if (!vis[e.to])
					{
						vis[e.to] = true;
						q.push(e.to);
					}
				}
		}
		return dis[T] != 0x3f3f3f3f3f3f3f3fLL;
	}

	inline int Dinic(int x, int flow)
	{
		int left = flow;
		if (x == T)
			return flow;
		vis[x] = true;
		for (int &i = ptr[x]; i < int(g[x].size()) && left && flow; i++)
		{
			link &e = g[x][i];
			if (dis[e.to] == dis[x] + e.val && e.flow && !vis[e.to])
			{
				int t = Dinic(e.to, min(e.flow, left));
				e.flow -= t;
				g[e.to][e.rev].flow += t;
				left -= t;
			}
		}
		if (!left)
			vis[x] = false;
		return flow - left;
	}
	ll mincost()
	{
		ans = 0;
		while (SPFA())
		{
			memset(ptr, 0, sizeof ptr);
			int d = Dinic(S, ~(1 << 31));
			flow += d;
			ans += d * dis[T];
		}
		return ans;
	}
} G;

int n, m;
ll a[55], b[55], c[55];
int id[N],val[N];
inline ll f(int i, ll j)
{
	return a[i] * j * j + b[i] * j + c[i];
}
int idnode[55];
vector<int> idright;
set<int> st;

void solve()
{
	G.clear();
	idright.clear();
	st.clear();
	G.S = ++G.n, G.T = ++G.n;
	int yuandian = ++G.n;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	for (int i = 1; i <= n; ++i)
		idnode[i] = ++G.n;
	int idcnt=0;
	for (int i = 1; i <= n; ++i)
	{
		int pos = -b[i] / (2 * a[i]);
		int l = pos, r = pos + 1;
		l=max(l,1);r=max(r,1);
		l=min(l,m);r=min(r,m);
		while (st.count(l) && l > 1)
			l--;
		while (st.count(r) && r < m)
			r++;
		if (!st.count(l))
			{id[++idcnt] = ++G.n;st.insert(l);val[idcnt]=l;}
		if (!st.count(r))
			{id[++idcnt] = ++G.n;st.insert(r);val[idcnt]=r;}
		while (st.count(l) && l > 1)
			l--;
		while (st.count(r) && r < m)
			r++;
		if (!st.count(l))
			{id[++idcnt] = ++G.n;st.insert(l);val[idcnt]=l;}
		if (!st.count(r))
			{id[++idcnt] = ++G.n;st.insert(r);val[idcnt]=r;}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=idcnt;j++)
		G.add(idnode[i],id[j],f(i,val[j]),1);
	for(int i=1;i<=n;i++)G.add(yuandian,idnode[i],0,1);
	for(int i=1;i<=idcnt;i++)
	G.add(id[i],G.T,0,1);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		G.add(G.S, yuandian, 0, 1);
		ans+=G.mincost();
		printf("%lld%c",ans,i==n?'\n':' ');
	}
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}