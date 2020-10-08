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
int n;
ll x[N];
ll ans = 0;
ll suml[N], sumr[N];

inline void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &x[i]);
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; ++i)
		if (x[i] > 0)
			sumr[i] = sumr[i - 1] + x[i];
	for (int i = n; i; --i)
		if (x[i] < 0)
			suml[i] = suml[i + 1] + x[i];
	for (int i = 1; i <= n; ++i)
		ans += abs(x[i]);
	for (int i = 1; i <= n; ++i)
	{
		ll tmp = 0;
		if (x[i] <= 0)
		{
			tmp += sumr[n];
			int mid = (i / 2) + (i & 1);
			ll pos = x[mid];
			tmp += abs(suml[i + 1]);
			tmp += abs(suml[mid] - suml[1] - pos * (1 - mid));
			tmp += abs(suml[i + 1] - suml[mid] - pos * (mid - i - 1));
			ans = min(ans, tmp);
		}
	}
	for (int i = n; i; --i)
	{
		ll tmp = 0;
		if (x[i] > 0)
		{
			tmp += abs(suml[1]);
			int j = n - i;
			int mid = j / 2 + (j & 1) + i;
			ll pos = x[mid];
			tmp += abs(sumr[i - 1]);
			tmp += abs(sumr[n] - sumr[mid] - pos * (n - mid));
			tmp += abs(pos * (mid - i + 1) - (sumr[mid] - sumr[i - 1]));
			ans = min(ans, tmp);
		}
	}
	printf("%lld\n", ans);
}

int main()
{
  //  freopen("g.in", "r", stdin);
 //  freopen("my.out", "w", stdout);
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
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