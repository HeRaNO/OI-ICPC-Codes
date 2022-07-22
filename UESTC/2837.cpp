#include <cstdio>
#include <vector>
#include <algorithm>

struct UnionSet
{
	std::vector<int> f;
	UnionSet(){}
	UnionSet(int n)
	{
		f.reserve(n);
		for (int i = 0; i < n; i++)
			f.emplace_back(i);
	}
	int getf(int x){ return x == f[x] ? x : f[x] = getf(f[x]); }
	void Union(int u, int v)
	{
		u = getf(u); v = getf(v);
		if (u != v) f[v] = u;
	}
};

struct event
{
	int op, v, nxt_v;
	event(){}
	event(int _op, int _v):
		op(_op), v(_v), nxt_v(_v + 1){}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<event> ev(m);
	std::vector<std::pair<int, int*>> a;
	for (int i = 0; i < m; i++)
	{
		int o, v;
		scanf("%d %d", &o, &v);
		ev[i] = event(o, v);
		a.push_back({ev[i].v, &ev[i].v});
		a.push_back({ev[i].nxt_v, &ev[i].nxt_v});
	}
	std::sort(a.begin(), a.end());
	std::vector<int> ori;
	for (int i = 0; i < a.size(); i++)
	{
		if (!i || a[i].first != a[i - 1].first) ori.push_back(a[i].first);
		*a[i].second = ori.size() - 1;
	}
	UnionSet S(ori.size());
	for (event e : ev)
	{
		if (e.op == 1)
			S.Union(e.nxt_v, e.v);
		else
		{
			int x = S.getf(e.v);
			printf("%d\n", ori[x] > n ? -1 : ori[x]);
		}
	}
	return 0;
}