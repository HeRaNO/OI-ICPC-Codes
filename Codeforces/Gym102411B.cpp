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
int n;
int tot;

void solve()
{
	// freopen("B.txt", "w", stdout);
	cin >> n;
	double mx = 2;
	int ans = 0;
	double las = -2;
	for (ll i = 1; i <= 300000; ++i)
	{
		double now = sin(1ll * i * 710LL - 173LL * 45000);
		printf("%lld\n", 1ll * i * 710LL - 173LL * 45000);
		if (now < las)
			break;
		else
		{
			las = now;
			ans++;
			if(ans==n)
				break;
		}
	}
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