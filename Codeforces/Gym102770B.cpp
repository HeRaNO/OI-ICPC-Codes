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
const int N = 1000050;
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
const int SIZ = 100000000 + 3;
char buf1[SIZ];
char *p1 = buf1, *p2 = buf1;
inline char readchar()
{
	if (p1 == p2)
		p1 = buf1, p2 = buf1 + fread(buf1, 1, SIZ, stdin);
	return p1 == p2 ? EOF : *p1++;
}
inline int read()
{
	int ret, c;
	while ((c = readchar()) > '9' || c < '0')
		;
	ret = c - '0';
	while ((c = readchar()) >= '0' && c <= '9')
		ret = ret * 10 + c - '0';
	return ret;
}
int n, C, a[N];
struct segtree
{
	int l, r;
	pii mx;
} t[N << 2];
inline void pushup(int id)
{
	// t[id].mx = max(t[ls].mx, t[rs].mx);
	t[id].mx = max(t[ls].mx, t[rs].mx);
	if (t[ls].mx.first == t[rs].mx.first)
		t[id].mx.second = t[ls].mx.second;
}
void build(int l, int r, int id)
{
	t[id].l = l, t[id].r = r;
	t[id].mx = {0, l};
	if (l == r)
	{
		t[id].mx = {C, l};
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	pushup(id);
}
void change(int pos, int val, int id)
{
	int l = t[id].l, r = t[id].r;
	if (l == r)
	{
		t[id].mx.first = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid)
		change(pos, val, ls);
	else
		change(pos, val, rs);
	pushup(id);
}
pii query(int val, int id)
{
	int l = t[id].l, r = t[id].r;
	if (l == r)
		return t[id].mx;
	pii lmax = t[ls].mx;
	if (lmax.first < val)
		return query(val, rs);
	return query(val, ls);
}
int ans1, ans2;
inline void solve1()
{
	for (int i = 1; i <= n; ++i)
	{
		pii u = query(a[i], 1);
		change(u.second, u.first - a[i], 1);
	}
	ans1 = query(C, 1).second - 1;
}
inline void solve2()
{
	ans2 = 0;
	multiset<int> s;
	// for (int i = 1; i <= n + 1; ++i)
	//     s.insert(C);
	for (int i = 1; i <= n; ++i)
	{
		auto now = s.lower_bound(a[i]);
		if (now == s.end())
		{
			s.insert(C - a[i]);
			continue;
		}
		int num = (*now);
		s.erase(now);
		s.insert(num - a[i]);
	}
	ans2 = s.size();
}

inline void solve()
{
	// scanf("%d", &n);
	n = read(), C = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	// cout << "!";
	build(1, n + 1, 1);
	solve1();
	// cout << "!";
	// clock_t nowtime = clock();
	// cout << (nowtime - TIME__START) / 1000 << endl;
	// printf("\n\nTime used: %.6lf(s)\n", ((double)nowtime - TIME__START) / 1000);
	solve2();
	// clock_t nowtime2 = clock();
	// printf("\n\nTime used: %.6lf(s)\n", ((double)nowtime2 - nowtime) / 1000);
	printf("%d %d\n", ans1, ans2);
}

int main()
{
	// freopen("B.in", "r", stdin);
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	Test = read();
	while (Test--)
	{
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}