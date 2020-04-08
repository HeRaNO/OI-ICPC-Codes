#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
using namespace std;
const int N = 200050;
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
int n, q;
int a[N];
struct segtree
{
	int lazy, st;
	int num[40];
	inline void Init()
	{
		memarray(num, 0);
		lazy = 0;
		st = 0;
	}
	bool insert(int x)
	{
		for (int i = 29; i >= 0; i--)
			if ((x >> i) & 1)
			{
				if (!num[i])
				{
					num[i] = x;
					return 1;
				}
				x ^= num[i];
			}
		return 0;
	}
	inline int query()
	{
		int ret = 0;
		for (int i = 29; i >= 0; --i)
			if (num[i])
				ret++;
		return ret;
	}
} t[N << 2], ans;
inline segtree merge(const segtree &x, const segtree &y)
{
	segtree ret;
	ret.Init();
	for (int i = 0; i <= 29; ++i)
	{
		ret.insert(x.num[i]);
		ret.insert(y.num[i]);
	}
	ret.insert(x.st ^ y.st);
	ret.st = y.st;
	return ret;
}
inline void pushup(int id) { t[id] = merge(t[ls], t[rs]); }
inline void pushdown(int id)
{
	if (t[id].lazy)
	{
		t[ls].lazy ^= t[id].lazy;
		t[rs].lazy ^= t[id].lazy;
		t[ls].st ^= t[id].lazy;
		t[rs].st ^= t[id].lazy;
		t[id].lazy = 0;
	}
}
void build(int l, int r, int id)
{
	t[id].Init();
	if (l == r)
	{
		t[id].st = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	pushup(id);
}
void change(int l, int r, int id, int L, int R, int val)
{
	if (L <= l && R >= r)
	{
		t[id].st ^= val;
		t[id].lazy ^= val;
		return;
	}
	pushdown(id);
	int mid = (l + r) >> 1;
	if (R <= mid)
		change(l, mid, ls, L, R, val);
	else if (L > mid)
		change(mid + 1, r, rs, L, R, val);
	else
	{
		change(l, mid, ls, L, mid, val);
		change(mid + 1, r, rs, mid + 1, R, val);
	}
	pushup(id);
}
void query(int l, int r, int L, int R, int id)
{
	if (L <= l && R >= r)
	{
		ans = merge(ans, t[id]);
		return;
	}
	pushdown(id);
	int mid = (l + r) >> 1;
	if (R <= mid)
		query(l, mid, L, R, ls);
	else if (L > mid)
		query(mid + 1, r, L, R, rs);
	else
	{
		query(l, mid, L, mid, ls);
		query(mid + 1, r, mid + 1, R, rs);
	}
}

void solve()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	build(1, n, 1);
	while (q--)
	{
		int op, l, r, k;
		scanf("%d%d%d", &op, &l, &r);
		ans.Init();
		if (op == 1)
		{
			scanf("%d", &k);
			change(1, n, 1, l, r, k);
		}
		else
		{
			query(1, n, l, r, 1);
			printf("%lld\n", 1ll << ans.query());
		}
	}
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