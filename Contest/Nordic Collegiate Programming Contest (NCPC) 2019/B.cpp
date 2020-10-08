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
int per[5];
struct point
{
	ll x, y;
	int id;
} p[N];
map<pair<ll, ll>, bool> vis;
ll ans, nowx, nowy;

void solve1()
{
	ans = min(ans, max(nowx, p[2].x + p[3].x) * (nowy + max(p[2].y, p[3].y)));
	ans = min(ans, nowx * (p[2].y + p[3].y + nowy));
	ans = min(ans, max(nowx, p[2].x + p[3].y) * (nowy + max(p[2].y, p[3].x)));
	ans = min(ans, max(nowx, p[2].y + p[3].x) * (nowy + max(p[2].x, p[3].y)));
	ans = min(ans, max(nowx, p[2].y + p[3].y) * (nowy + max(p[2].x, p[3].x)));
}
void solve2()
{
	ans = min(ans, (nowx + p[2].x + p[3].x) * max(nowy, max(p[2].y, p[3].y)));
	ans = min(ans, (nowx + p[2].x + p[3].y) * max(nowy, max(p[2].y, p[3].x)));
	ans = min(ans, (nowx + p[2].y + p[3].x) * max(nowy, max(p[2].x, p[3].y)));
	ans = min(ans, (nowx + p[2].y + p[3].y) * max(nowy, max(p[2].x, p[3].x)));
	if (p[2].y >= nowy)
		ans = min(ans, (nowx + p[2].x) * (p[2].y + min(p[3].y, p[3].x)));
	if (p[3].y >= nowy)
		ans = min(ans, (nowx + p[3].x) * (p[3].y + min(p[2].x, p[2].y)));
	if (p[2].x >= nowy)
		ans = min(ans, (nowx + p[2].y) * (p[2].x + min(p[3].x, p[3].y)));
	if (p[3].x >= nowy)
		ans = min(ans, (nowx + p[3].y) * (p[3].x + min(p[2].x, p[2].y)));
	ans = min(ans, (nowx + max(p[2].x, p[3].x)) * max(nowy, p[2].y + p[3].y));
	ans = min(ans, (nowx + max(p[2].x, p[3].y)) * max(nowy, p[2].y + p[3].x));
	ans = min(ans, (nowx + max(p[2].y, p[3].x)) * max(nowy, p[2].x + p[3].y));
	ans = min(ans, (nowx + max(p[2].y, p[3].y)) * max(nowy, p[2].x + p[3].x));
}
void solve3()
{
	ans = min(ans, (nowx + p[2].x) * max(nowy + min(p[3].x, p[3].y), p[2].y));
	ans = min(ans, (nowx + p[2].y) * max(nowy + min(p[3].x, p[3].y), p[2].x));
	ans = min(ans, (nowx + p[3].x) * max(nowy + min(p[2].x, p[2].y), p[3].y));
	ans = min(ans, (nowx + p[3].y) * max(nowy + min(p[2].x, p[2].y), p[3].x));
}

inline void solve()
{
	ans = llinf;
	int mxid = 0, mx = 0;
	for (int i = 1; i <= 3; ++i)
	{
		scanf("%lld%lld", &p[i].x, &p[i].y), p[i].id = i;
		if (mx < p[i].x || mx < p[i].y)
			mx = max(p[i].x, p[i].y), mxid = i;
	}
	if (p[mxid].x <= p[mxid].y)
		nowx = p[mxid].y, nowy = p[mxid].x;
	else
		nowx = p[mxid].x, nowy = p[mxid].y;
	for (int i = 1; i <= 3; ++i)
		if (p[i].x < p[i].y)
			swap(p[i].x, p[i].y);
	swap(p[mxid], p[1]);
	solve1();
	solve2();
	solve3();
	printf("%lld\n", ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
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
