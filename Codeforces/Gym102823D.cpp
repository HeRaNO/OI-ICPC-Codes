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
ll x, y;
int cx[2][70], cy[2][70];

inline void solve()
{
	memarray(cx, 0);
	memarray(cy, 0);
	scanf("%lld%lld", &x, &y);
	ll nx = x, ny = y;
	int jix = 0, jiy = 0, oux = 0, ouy = 0;
	int tot = 0;
	while (nx)
	{
		if (nx & 1)
		{
			cx[tot & 1][tot] = 1;
			(tot & 1) ? jix++ : oux++;
		}
		nx >>= 1;
		tot++;
	}
	tot = 0;
	while (ny)
	{
		if (ny & 1)
		{
			cy[tot & 1][tot] = 1;
			(tot & 1) ? jiy++ : ouy++;
		}
		tot++;
		ny >>= 1;
	}
	if (jiy != jix || ouy != oux)
		return puts("-1"), void();
	int ans = 0;
	int l = 0, r = 0;
	while (l < 64 && r < 64)
	{
		while (cx[0][l] == 0)
			l += 2;
		while (cy[0][r] == 0)
			r += 2;
		if (l >= 64 || r >= 64)
			break;
		ans += abs(r - l) / 2;
		l += 2, r += 2;
	}
	l = 1, r = 1;
	while (l < 64 && r < 64)
	{
		while (cx[1][l] == 0)
			l += 2;
		while (cy[1][r] == 0)
			r += 2;
		if (l >= 64 || r >= 64)
			break;
		ans += abs(r - l) / 2;
		l += 2, r += 2;
	}
	cout << ans << '\n';
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
	int kase = 0;
	while (Test--)
	{
		printf("Case %d: ", ++kase);
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}