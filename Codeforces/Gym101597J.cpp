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
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n;
struct point
{
	ll x, y;
} a[N];
bool cmp1(const point &X, const point &Y) { return X.y > Y.y; }
bool cmp2(const point &X, const point &Y) { return X.x < Y.x; }
bool cmp3(const point &X, const point &Y) { return X.x > Y.x; }
ll Left = llinf, Right = -llinf, Up;
ll ans1, ans2, ans3;

inline void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		x++, y++;
		Left = min(Left, x);
		Right = max(Right, x);
		Up = max(Up, y);
		a[i].x = x;
		a[i].y = y;
	}
	ans1 = (Up + 1) * 2 + (Right - Left + 3);
	ans2 = Up * 2 + (Right - Left + 3);
	sort(a + 1, a + n + 1, cmp1);
	ans3 = (Right - Left + 1) * (Up);
	ll Left2 = llinf, Right2 = -llinf;
	for (int i = 1; i <= n; ++i)
		if (a[i].y == Up)
			Left2 = min(Left2, a[i].x), Right2 = max(Right2, a[i].x);
	int nowUp = Up;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i].x >= Left2)
			continue;
		ans3 -= (Left2 - Left) * (nowUp - a[i].y);
		Left2 = a[i].x;
		nowUp = a[i].y;
	}
	nowUp = Up;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i].x <= Right2)
			continue;
		ans3 -= (Right - Right2) * (nowUp - a[i].y);
		Right2 = a[i].x;
		nowUp = a[i].y;
	}
	printf("%lld %lld %lld\n", ans1, ans2, ans3);
}
/*
5
-10 1
-9 3
-7 4
-5 3
-4 1
21 19 25
*/

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}