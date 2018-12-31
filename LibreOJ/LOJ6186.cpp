#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
typedef pair<int, int> pii;
#define x first
#define y second

const int N = 1e5 + 10;
int E[N], R[N];

namespace seg
{
	int mx[N << 2], d[N << 2];
	LL s[N << 2];
	int a, b, c;

#define lc (x << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)
#define lcq lc, l, mid
#define rcq rc, mid + 1, r

	void build(int x, int l, int r)
	{
		if (l == r) mx[x] = R[l], s[x] = E[l];
		else build(lcq), build(rcq), mx[x] = max(mx[lc], mx[rc]), s[x] = s[lc] + s[rc];
	}
	void push(int x, int l, int r)
	{
		if (d[x])
		{
			s[x] += 1LL * (r - l + 1) * d[x];
			if (l < r) d[lc] += d[x], d[rc] += d[x];
			d[x] = 0;
		}
	}
	LL sum(int x, int l, int r)
	{
		push(x, l, r);
		if (a <= l && r <= b) return s[x];
		else return (a <= mid ? sum(lcq) : 0) + (b > mid ? sum(rcq) : 0);
	}
	void modi(int x, int l, int r)
	{
		if (l == r) mx[x] = c;
		else (a <= mid ? modi(lcq) : modi(rcq)), mx[x] = max(mx[lc], mx[rc]);
	}
	void set(int x, int l, int r)
	{
		push(x, l, r);
		if (l == r) s[x] = c;
		else (a <= mid ? set(lcq) : push(lcq)), (a > mid ? set(rcq) : push(rcq)), s[x] = s[lc] + s[rc];
	}
	int qry(int x, int l, int r)
	{
		push(x, l, r);
		if (l == r) return s[x];
		else return (a <= mid ? qry(lcq) : qry(rcq));
	}
	int fL(int x, int l, int r)
	{
		if (a <= l && r <= b)
		{
			if (l == r) return mx[x] >= c ? l : 0;
			else return (mx[rc] >= c ? fL(rcq) : fL(lcq));
		}
		else
		{
			if (b > mid)
			{
				int t = fL(rcq);
				if (t) return t;
			}
			if (a <= mid) return fL(lcq);
			return 0;
		}
	}
	int fR(int x, int l, int r)
	{
		if (a <= l && r <= b)
		{
			if (l == r) return mx[x] >= c ? l : 0;
			else return (mx[lc] >= c ? fR(lcq) : fR(rcq));
		}
		else
		{
			if (a <= mid)
			{
				int t = fR(lcq);
				if (t) return t;
			}
			if (b >  mid) return fR(rcq);
			return 0;
		}
	}
	void add(int x, int l, int r)
	{
		if (a <= l && r <= b) d[x] += c, push(x, l, r);
		else
		{
			push(x, l, r);
			if (a <= mid) add(lcq);
			else push(lcq);
			if (b >  mid) add(rcq);
			else push(rcq);
			s[x] = s[lc] + s[rc];
		}
	}
}

int n, k;
set<int> s;
void init()
{
	static pii a[N];
	rep(i, 1, n) a[i] = mp(R[i], i);
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	rep(i, 1, n)
	{
		int x = a[i].y;
		sit it = s.insert(x).x;
		int t1 = 0, t2 = 0;
		if (it != s.begin()) it--, t1 = *it, it++;
		it++;
		if (it != s.end()) t2 = *it;
		if (!t1 && !t2) E[x] = 0;
		else if (t1 && (!t2 || R[t1] < R[t2])) E[x] = R[t1] == R[x] ? E[t1] : E[t1] + 1;
		else E[x] = R[t2] == R[x] ? E[t2] : E[t2] + 1;
	}
}

inline int Q(int x)
{
	seg::a = x;
	return seg::qry(1, 1, n);
}

int cal(int x)
{
	seg::a = 1, seg::b = x - 1, seg::c = R[x];
	int t1 = seg::a <= seg::b ? seg::fL(1, 1, n) : 0;
	seg::a = x + 1, seg::b = n, seg::c = R[x];
	int t2 = seg::a <= seg::b ? seg::fR(1, 1, n) : 0;
	if (!t1 && !t2) return 0;
	else if (t1 && (!t2 || R[t1] < R[t2])) return R[t1] == R[x] ? Q(t1) : Q(t1) + 1;
	else return R[t2] == R[x] ? Q(t2) : Q(t2) + 1;
}

void add(int x, int f)
{
	seg::a = 1, seg::b = x - 1, seg::c = R[x];
	int t1 = seg::a <= seg::b ? seg::fL(1, 1, n) : 0;
	if (!t1 || R[t1] > R[x])
	{
		seg::a = t1 + 1, seg::b = x - 1, seg::c = f;
		if (seg::a <= seg::b) seg::add(1, 1, n);
	}
	seg::a = x + 1, seg::b = n, seg::c = R[x];
	int t2 = seg::a <= seg::b ? seg::fR(1, 1, n) : 0;
	if (!t2) t2 = n + 1;
	if (t2 == n + 1 || R[t2] > R[x])
	{
		seg::a = x + 1, seg::b = t2 - 1, seg::c = f;
		if (seg::a <= seg::b) seg::add(1, 1, n);
	}
}

void read(int &x)
{
	char c = getchar();
	x = 0;
	while (c < '0' || c > '9') c = getchar();;
	while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
}


int main()
{
	scanf("%d%d", &n, &k);
	rep(i, 1, n) read(R[i]);
	init();
	seg::build(1, 1, n);
	int op;
	while (scanf("%d", &op) == 1)
	{
		if (op == 1)
		{
			int x;
			read(x);
			if (R[x] == R[x + 1]) continue;
			add(x, -1), add(x + 1, -1);
			seg::a = x, seg::c = R[x + 1];
			seg::modi(1, 1, n);
			seg::a = x + 1, seg::c = R[x];
			seg::modi(1, 1, n);
			swap(R[x], R[x + 1]);
			add(x, 1), add(x + 1, 1);
			int t1 = x, t2 = x + 1;
			if (R[t1] < R[t2]) swap(t1, t2);
			seg::c = cal(t1);
			seg::a = t1;
			seg::set(1, 1, n);
			seg::c = cal(t2);
			seg::a = t2;
			seg::set(1, 1, n);
		}
		else
		{
			int x, y;
			read(x), read(y);
			seg::a = x, seg::b = y;
			LL ans = seg::sum(1, 1, n);
			printf("%lld\n", ans * k + 1LL * (n - 1) * (y - x + 1));
		}
	}
	return 0;
}
