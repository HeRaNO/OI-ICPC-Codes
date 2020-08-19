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
const int N = 6000050;
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
void solve1(int n, int lim)
{
	printf("126");
	for (int i = 1; i < n - 2; ++i)
		printf("51");
	printf("5");
	for (int i = 1; i <= n - 2; ++i)
		printf("46");
	printf("4");
	for (int i = 1; i <= n - 2; ++i)
		printf("35");
	printf("3");
	for (int i = 1; i <= n - 2; ++i)
		printf("24");
	printf("2");
	for (int i = 1; i <= n - 2; ++i)
		printf("13");
	printf("1");
	for (int i = 1; i <= n - 2; ++i)
		printf("62");
	if (n == lim)
		return;
	solve1(n + 2, lim);
}
int m;
void solve2(int n)
{
	for (int i = 1; i <= m; ++i)
		printf("35");
	printf("3");
	if (m == (::n)-1)
		m--;
	else
		m -= 2;
	for (int i = 1; i <= n - 2; ++i)
		printf("24");
	printf("2");
	for (int i = 1; i <= n - 2; ++i)
		printf("13");
	printf("1");
	if (n <= 2)
		return;
	for (int i = 1; i <= n - 2; ++i)
		printf("62");
	printf("6");
	for (int i = 1; i <= n - 2; ++i)
		printf("51");
	printf("5");
	for (int i = 1; i <= n - 4; ++i)
		printf("46");
	printf("4");
	solve2(n - 2);
}

inline void solve()
{
	scanf("%d", &n);
	if (n & 1)
	{
		solve1(3, n);
	}
	else
	{
		m = n - 1;
		printf("5");
		solve2(n);
	}
	putchar('\n');
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}