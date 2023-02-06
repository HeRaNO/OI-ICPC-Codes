#include <tuple>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;

const int Z = 100'000;

struct payload
{
	long long now, ans;
	payload(){}
	payload(long long _, long long __): now(_), ans(__){}
	payload operator + (const payload &a) const {
		return payload(max(now, a.now), max(ans, a.ans));
	}
	void update(const payload &a) {
		ans = max(ans, now + a.ans);
		now += a.now;
		return ;
	}
	bool empty() {
		return !now && !ans;
	}
};

payload tr[1 << 18], lazy[1 << 18];
int n, m, a[MAXN], las[MAXN + MAXN];
long long ans[MAXN];
vector<pair<int, int>> Q[MAXN];

void update(int u, const payload &v)
{
	tr[u].update(v); lazy[u].update(v);
	return ;
}

void pushDown(int u)
{
	if (lazy[u].empty()) return ;
	update(u << 1, lazy[u]); update(u << 1 | 1, lazy[u]);
	lazy[u] = payload(0, 0); return ;
}

void modify(int u, int l, int r, int v, int pl, int pr)
{
	if (pl == l && pr == r)
	{
		update(u, payload(v, v));
		return ;
	}
	pushDown(u); int m = pl + pr >> 1;
	if (r <= m) modify(u << 1, l, r, v, pl, m);
	else if (m <= l) modify(u << 1 | 1, l, r, v, m, pr);
	else
	{
		modify(u << 1, l, m, v, pl, m);
		modify(u << 1 | 1, m, r, v, m, pr);
	}
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
	return ;
}

long long query(int u, int l, int r, int pl, int pr)
{
	if (l == pl && r == pr) return tr[u].ans;
	pushDown(u); int m = pl + pr >> 1;
	if (r <= m) return query(u << 1, l, r, pl, m);
	else if (m <= l) return query(u << 1 | 1, l, r, m, pr);
	else return max(query(u << 1, l, m, pl, m), query(u << 1 | 1, m, r, m, pr));
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int l, r; scanf("%d %d", &l, &r);
		Q[r].push_back({l, i});
	}
	for (int i = 1; i <= n; i++)
	{
		modify(1, las[a[i] + Z] + 1, i + 1, a[i], 1, n + 1);
		las[a[i] + Z] = i;
		for (auto p : Q[i])
		{
			int l, q; tie(l, q) = p;
			ans[q] = query(1, l, i + 1, 1, n + 1);
		}
	}
	for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}