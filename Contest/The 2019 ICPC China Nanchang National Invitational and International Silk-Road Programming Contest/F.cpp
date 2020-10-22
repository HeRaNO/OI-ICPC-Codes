#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, a[N], m, kase;

struct Segtrees
{
	struct segtree
	{
		int l, r;
		int sum;
	} t[N << 2];
	inline void pushup(int id) { t[id].sum = (t[ls].sum ^ t[rs].sum); }
	void build(int l, int r, int id, int type)
	{
		t[id].l = l, t[id].r = r, t[id].sum = 0;
		if (l == r)
		{
			if ((l & 1) == type)
				t[id].sum = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, ls, type);
		build(mid + 1, r, rs, type);
		pushup(id);
	}
	void change(int id, int pos, int val)
	{
		int l = t[id].l, r = t[id].r;
		if (l == r)
		{
			t[id].sum = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid)
			change(ls, pos, val);
		else
			change(rs, pos, val);
		pushup(id);
	}
	int query(int id, int L, int R)
	{
		int l = t[id].l, r = t[id].r;
		if (L <= l && R >= r)
			return t[id].sum;
		int mid = (l + r) >> 1;
		if (R <= mid)
			return query(ls, L, R);
		else if (L > mid)
			return query(rs, L, R);
		else
			return (query(ls, L, mid) ^ query(rs, mid + 1, R));
	}
} tree[2];

inline void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < 2; ++i)
		tree[i].build(1, n, 1, i);
	while (m--)
	{
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 0)
		{
			int pos = l, val = r;
			if ((pos & 1) == 0)
				tree[0].change(1, pos, val);
			else
				tree[1].change(1, pos, val);
		}
		else
		{
			if (((r - l + 1) & 1) == 0)
			{
				putchar('0');
				putchar('\n');
				continue;
			}
			int ans = 0;
			if ((l & 1) == 0)
				ans = tree[0].query(1, l, r);
			else
				ans = tree[1].query(1, l, r);
			printf("%d\n", ans);
		}
	}
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
	{
		printf("Case #%d: ", ++kase);
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}