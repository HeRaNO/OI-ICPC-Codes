#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

int main()
{
	int n; scanf("%d", &n);
	std::vector<int> a(n), b(n);
	std::vector<std::pair<int, int*>> tb(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
		tb[i] = {b[i], &b[i]};
	}
	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);
	std::sort(p.begin(), p.end(), [&](int x, int y){
		return a[x] < a[y];
	});
	std::sort(tb.begin(), tb.end());
	std::vector<int> ori_b;
	for (int i = 0; i < n; i++)
	{
		if (!i || tb[i].first != tb[i - 1].first)
			ori_b.push_back(tb[i].first);
		*tb[i].second = ori_b.size() - 1;
	}
	int M = ori_b.size();
	int trSiz = 1 << (32 - __builtin_clz(M)) + 1;
	std::vector<long long> sa(trSiz, 0), b_sa(trSiz), lazy(trSiz, 0);
	std::function<void(int, int, int)> build_tree =
	[&](int u, int l, int r)
	{
		if (l + 1 == r){ b_sa[u] = ori_b[l]; return ; }
		int m = l + r >> 1;
		build_tree(u << 1, l, m); build_tree(u << 1 | 1, m, r);
		b_sa[u] = std::min(b_sa[u << 1], b_sa[u << 1 | 1]);
		return ;
	};
	std::function<void(int, int, int, int, int)> modify_sa =
	[&](int u, int p, int v, int pl, int pr)
	{
		if (pl + 1 == pr){ sa[u] += v; return ; }
		int m = pl + pr >> 1;
		if (p < m) modify_sa(u << 1, p, v, pl, m);
		else modify_sa(u << 1 | 1, p, v, m, pr);
		sa[u] = sa[u << 1] + sa[u << 1 | 1];
		return ;
	};
	std::function<long long(int, int, int, int, int)> query_sum_a =
	[&](int u, int l, int r, int pl, int pr)
	{
		if (l == pl && r == pr) return sa[u];
		int m = pl + pr >> 1;
		if (r <= m) return query_sum_a(u << 1, l, r, pl, m);
		else if (m <= l) return query_sum_a(u << 1 | 1, l, r, m, pr);
		return query_sum_a(u << 1, l, m, pl, m) + query_sum_a(u << 1 | 1, m, r, m, pr);
	};
	std::function<void(int, long long)> add =
	[&](int u, long long v)
	{
		b_sa[u] += v; lazy[u] += v;
		return ;
	};
	std::function<void(int)> push_down =
	[&](int u)
	{
		if (lazy[u])
		{
			add(u << 1, lazy[u]); add(u << 1 | 1, lazy[u]);
			lazy[u] = 0;
		}
		return ;
	};
	std::function<void(int, int, int, int, int, int)> modify_b_sa =
	[&](int u, int l, int r, int v, int pl, int pr)
	{
		if (l == pl && r == pr)
		{
			add(u, v); return ;
		}
		int m = pl + pr >> 1; push_down(u);
		if (r <= m) modify_b_sa(u << 1, l, r, v, pl, m);
		else if (m <= l) modify_b_sa(u << 1 | 1, l, r, v, m, pr);
		else
		{
			modify_b_sa(u << 1, l, m, v, pl, m);
			modify_b_sa(u << 1 | 1, m, r, v, m, pr);
		}
		b_sa[u] = std::min(b_sa[u << 1], b_sa[u << 1 | 1]);
		return ;
	};
	std::function<long long(int, int, int, int, int)> query_min_b_sa =
	[&](int u, int l, int r, int pl, int pr)
	{
		if (l == pl && r == pr) return b_sa[u];
		int m = pl + pr >> 1; push_down(u);
		if (r <= m) return query_min_b_sa(u << 1, l, r, pl, m);
		else if (m <= l) return query_min_b_sa(u << 1 | 1, l, r, m, pr);
		return std::min(query_min_b_sa(u << 1, l, m, pl, m), query_min_b_sa(u << 1 | 1, m, r, m, pr));
	};
	build_tree(1, 0, M);
	int ans = 0;
	for (int i : p)
	{
		if (query_sum_a(1, 0, b[i] + 1, 0, M) + a[i] > ori_b[b[i]])
			continue;
		if (query_min_b_sa(1, b[i], M, 0, M) < a[i])
			continue;
		modify_sa(1, b[i], a[i], 0, M);
		modify_b_sa(1, b[i], M, -a[i], 0, M);
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}
