#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define fi first
#define se second
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 2050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
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
struct point
{
	ll x, y;
} p[N];
struct lines
{
	ll x, y, c;
} l[N];
int ans = 1;
const double eps=1e-7;

vector<pair<double, double>> mp;

inline bool getInter(ll A, ll B, ll C, ll D, ll E, ll F, pair<double, double> &x)
{
	if (B * D == A * E)
	{
		// if (C == F)
		//     return 1;
		// else
		return 0;
		// return 0;
	}
	double q = (double)(A * F - C * D) / (double)(B * D - A * E);
	double p = (double)(B * F - C * E) / (double)(A * E - B * D);
	x = {p, q};
	return true;
}

inline bool equal(pair<double,double> a, pair<double,double> b)
{
	return fabs(a.fi-b.fi)<=eps&&fabs(a.se-b.se)<=eps;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	for (int i = 1; i <= n; ++i)
	{
		l[i].x = 2 * p[i].x;
		l[i].y = 2 * p[i].y;
		l[i].c = -(p[i].x * p[i].x + p[i].y * p[i].y);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			pair<double, double> x;
			if (getInter(l[i].x, l[i].y, l[i].c, l[j].x, l[j].y, l[j].c, x))
				mp.push_back(x);
		}
		sort(mp.begin(), mp.end());
		if (mp.empty())
			continue;
		pair<double, double> now = mp[0];
		int tmp = 1;
		for (auto j : mp)
		{
			if (equal(j, now))
			{
				tmp++;
				ans = max(tmp, ans);
			}
			else
				now = j, tmp = 2, ans = max(ans, tmp);
		}
		mp.clear();
	}
	printf("%d\n", ans);
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