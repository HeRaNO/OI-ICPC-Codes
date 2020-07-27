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
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, c;
int dp[505][20005];
int pre[505][20005];
struct wupin
{
	int s, d;
	int id;
	bool operator<(const wupin &x) const
	{
		return (s - d < x.s - x.d) || (s - d == x.s - x.d && d < x.d);
	}
} a[505];

vector<int> vec;

void solve()
{
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].d, &a[i].s), a[i].id = i;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = c - a[i].d + a[i].s; j >= 0; --j)
		{
			dp[i][j] = dp[i - 1][j];
			pre[i][j] = pre[i - 1][j];
			if (j >= a[i].s)
			{
				if (dp[i][j] < dp[i - 1][j - a[i].s] + 1)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].s] + 1);
					pre[i][j] = i;
				}
			}
		}
	}
	int mx = 0, mxno = 0, mxu = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= c; ++j)
		{
			if (mx < dp[i][j])
			{
				mx = dp[i][j];
				mxno = j;
				mxu = i;
			}
			// printf("%d ", dp[i][j]);
		}
	printf("%d\n", mx);
	int u = mxu;
	while (mxno && u > 0)
	{
		// printf("%d ", pre[u][mxno]);
		vec.push_back(a[pre[u][mxno]].id);
		int k = pre[u][mxno];
		mxno = mxno - a[pre[u][mxno]].s;
		u = k - 1;
	}
	reverse(vec.begin(), vec.end());
	for (auto i : vec)
		printf("%d ", i);
}

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
/*
4 100
1 1
1 1
1 1
100 97
*/