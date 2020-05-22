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
map<int, bool> vis;
ll Ans[20] = {
	0,
	4,
	10,
	20,
	35,
	56,
	83,
	116,
	155,
	198,
	244,
	292,
	341,
	390,
	439,
	488,
};

void solve()
{
	int n;
	int las = 0;
	cin >> n;
	// ll ans = 0;
	// for (n = 1; n <= 15; ++n)
	// {
	//     vis.clear();
	//     int ans = 0;
	//     for (int a = 0; a <= n; ++a)
	//         for (int b = 0; b <= n && a + b <= n; ++b)
	//             for (int c = 0; c <= n && a + b + c <= n; ++c)
	//             {
	//                 int d = n - a - b - c;
	//                 if (d < 0)
	//                     continue;
	//                 int now = a + 5 * b + 10 * c + 50 * d;
	//                 if (!vis[now])
	//                     ans++;
	//                 vis[now] = 1;
	//             }
	if (n <= 15)
		printf("%lld\n", Ans[n]);
	else
		printf("%lld\n", Ans[15] + 49ll * (n - 15));
	// las = ans;
	// }
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