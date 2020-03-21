#include <bits/stdc++.h>
#define N 3500000
using namespace std;

typedef long long ll;

const ll inf = INT_MAX;
struct edge { int u, v; ll w, w0; } es[N];
int ls[N], rs[N];int dis[N]; ll tag[N];

void update(int x, ll t) {
	es[x].w += t;
	tag[x] += t;
}

void push_down(int x) {
	if (ls[x]) update(ls[x], tag[x]);
	if (rs[x]) update(rs[x], tag[x]);
	tag[x] = 0;
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (es[x].w > es[y].w) swap(x, y);
	push_down(x);
	rs[x] = merge(rs[x], y);
	if (dis[ls[x]] < dis[rs[x]]) swap(ls[x], rs[x]);
	dis[x] = dis[rs[x]] + 1; return x;
}
const int MAXM=3000;
int top[MAXM], fa[MAXM], prv[MAXM], ine[MAXM], nc;
vector<int> ch[N];

int gn(int cnt) {
	while (cnt--) {
		int x = ++nc;
		top[x] = fa[x] = prv[x] = ine[x] = 0;
		ch[x].clear();
	}
	return nc;
}

int f[MAXM];
int find(int x) { return f[x] ? f[x] = find(f[x]) : x; }

void contract(int n, int m) {
	nc = 0; gn(n);
	for (int i = 1; i <= n; ++i) es[++m] = { i % n + 1, i, 2 * inf, -1 };
	fill_n(ls + 1, m, 0); fill_n(rs + 1, m, 0);
	fill_n(dis + 1, m, 1); fill_n(tag + 1, m, 0);
	for (int i = 1; i <= m; ++i)
		top[es[i].v] = merge(top[es[i].v], i);

	int x = 1;
	while (top[x]) {
		int i = top[x], y = find(es[i].u);
		if (y == x) top[x] = merge(ls[i], rs[i]);
		else {
			ine[x] = i; prv[x] = y;
			if (!ine[es[i].u]) x = y;
			else {
				int z = gn(1);
				while (!fa[x]) {
					fa[x] = z; ch[z].push_back(x);
					f[find(x)] = z;
					if (top[x]) update(top[x], -es[ine[x]].w);
					top[z] = merge(top[z], top[x]);
					x = prv[x];
				}
				x = z;
			}
		}
	}
}

int fa2[MAXM], ine2[MAXM];
void dismantle(vector<int>& s, int x) {
	while (fa2[x]) {
		for (int y : ch[fa2[x]]) {
			if (y == x) continue;
			fa2[y] = 0;
			if (!ch[y].empty())
				s.push_back(y);
		}
		x = fa2[x];
	}
}

vector<int> expand(int n, int r) {
	copy_n(fa + 1, nc, fa2 + 1);
	copy_n(ine + 1, nc, ine2 + 1);
	vector<int> s, res;
	dismantle(s, r);
	while (!s.empty()) {
		int x = s.back(), i = ine2[x];
		s.pop_back();
		ine2[es[i].v] = i;
		dismantle(s, es[i].v);
	}
	for (int i = 1; i <= n; ++i)
		if (i != r) res.push_back(ine2[i]);
	return res;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
//    #ifndef ONLINE_JUDGE
//    ifstream cin("1.in");
//    #endif // ONLINE_JUDGE

	int n, m=0, r;
	r=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int xi;ll si;scanf("%d%lld",&xi,&si);xi++;
		es[++m]={xi,i+1,si,si};
		for(int j=1;j<=n+1;++j)
		{
			ll cost;
			scanf("%lld",&cost);
			es[++m]={j,i+1,cost,cost};
		}
	}

	contract(n+1, m);

	vector<int> res = expand(n+1, r);
	ll ans = 0; bool fail = 0;
	for (int i : res) {
		if (i > m) {
			fail = 1;
			break;
		}
		ans += es[i].w0;
	}

	if (!fail) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}
