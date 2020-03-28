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
int n, a, b, ans;

void solve()
{
	cin >> a >> b >> n;
	int t1 = b, t2 = a;
	ans = 0;
	int now = 1;
	while (t1 != n || t2 != n)
	{
		if (now == 0)
		{
			t1 += b - a;
			t1 = min(t1, n);
		}
		else
		{
			t2 += b - a;
			t2 = min(t2, n);
		}
		now ^= 1;
		ans++;
	}
	cout << ans << endl;
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