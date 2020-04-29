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
const int N = 500050;
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
int n, m;
struct island
{
	ll l, r;
	bool operator<(const island &X) const
	{
		return l < X.l;
	}
} a[N];
struct bridge
{
	ll len;
	int id;
	bool operator<(const bridge &X) const
	{
		return len < X.len;
	}
} b[N];
struct Tmp
{
	ll L, R;
	int id;
	friend bool operator<(const Tmp &X, const Tmp &Y)
	{
		return X.R > Y.R;
	}
} p[N];
bool cmp(const Tmp &X, const Tmp &Y)
{
	return X.L < Y.L || (X.L == Y.L && X.R < Y.R);
}
int ans[N];
priority_queue<Tmp> q;

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &a[i].l, &a[i].r);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%lld", &b[i].len);
		b[i].id = i;
	}
	sort(b + 1, b + m + 1);
	for (int i = 1; i < n; ++i)
		p[i] = {a[i + 1].l - a[i].r, a[i + 1].r - a[i].l, i};
	sort(p + 1, p + n, cmp);
	int las = 1;
	int cnt = 0;
	for (int i = 1; i <= m; ++i)
	{
		if (cnt == n - 1)
			break;
		while (las < n && p[las].L <= b[i].len && p[las].R >= b[i].len)
			q.push(p[las++]);
		if (q.empty())
			continue;
		Tmp u = q.top();
		q.pop();
		if (b[i].len <= u.R)
			++cnt, ans[u.id] = b[i].id;
		else
			return puts("No"), void();
	}
	if (cnt != n - 1)
		return puts("No"), void();
	puts("Yes");
	for (int i = 1; i < n; ++i)
		printf("%d ", ans[i]);
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