#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
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

void solve()
{
	ll x, y;
	cin >> x >> y;
	if (__gcd(x, y) != 1)
	{
		puts("Impossible");
		return;
	}
	int flag = 0;
	if (x < y)
		swap(x, y), flag = 1;
	while (x % y != 0)
	{
		ll a = x / y;
		ll b = x % y;
		printf("%lld%c", a, (flag == 0) ? 'A' : 'B');
		x = y;
		y = b;
		flag ^= 1;
	}
	printf("%lld%c", x / y - 1, (flag == 0) ? 'A' : 'B');
	puts("");
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