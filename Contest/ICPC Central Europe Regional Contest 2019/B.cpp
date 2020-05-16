#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<ll, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 500050;
const int MAXN = 500050;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n;
ll a[N];
ll ans;
namespace rmq
{
	int lg[MAXN];
	pair<int, int> mx[MAXN][19], mn[MAXN][19];
	int g[MAXN][19];

	void init(int n, ll a[])
	{
		for (int i = 2; i <= n; i++)
			lg[i] = lg[i >> 1] + 1;
		for (int i = 1; i <= n; i++)
			mx[i][0] = mn[i][0] = {a[i], i}, g[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
			{
				mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
				g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
			}
		return;
	}

	pair<int, int> queryMax(int l, int r)
	{
		int t = lg[r - l + 1];
		return max(mx[l][t], mx[r - (1 << t) + 1][t]);
	}

	pair<int, int> queryMin(int l, int r)
	{
		int t = lg[r - l + 1];
		return min(mn[l][t], mn[r - (1 << t) + 1][t]);
	}

	int queryGcd(int l, int r)
	{
		// assert(l > r);
		int t = lg[r - l + 1];
		return __gcd(g[l][t], g[r - (1 << t) + 1][t]);
	}
} // namespace rmq
int totl, totr;
int LL[N], RR[N];
inline int checkToRight(int st,int l, int r, int g)
{
	int ret = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (rmq::queryGcd(st, mid) < g)
			 r = mid - 1;
		else
			ret = mid, l = mid + 1;
	}
	return ret;
}
inline int checkToLeft(int en,int l, int r, int g)
{
	int ret = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (rmq::queryGcd(mid, en) < g)
			 l = mid + 1;
		else
			ret = mid, r = mid - 1;
	}
	return ret;
}
inline ll cal(ll X, ll Y)
{
	return max(X, Y) - min(X, Y);
}

ll fenzhi(int L, int R)
{
	if (L > R)
		return 0;
	int MID = rmq::queryMax(L, R).second;
	totl = totr = 0;
	int I = MID, J = MID;
	ll ret = 0;
	LL[++totl] = MID + 1, RR[++totr] = MID - 1;
	while (J <= R)
	{
		int g = rmq::queryGcd(MID, J);
		J = checkToRight(MID,J, R, g);
		if (J == -1)
			break;
		RR[++totr] = J ;J++;
	}
	while (I >= L)
	{
		int g = rmq::queryGcd(I, MID);
		I = checkToLeft(MID,L, I, g);
		if (I == -1)
			break;
		LL[++totl] = I ;I--;
	}
	LL[++totl] = L;
	RR[++totr] = R;
	ll mx = a[MID];
	for (int i = 2; i <= totl; ++i)
	{
		if (LL[i]==LL[i-1]) continue;
		for (int j = 2; j <= totr; ++j)
		{
			if (RR[j]==RR[j-1]) continue;
			ret += mx * __gcd(rmq::queryGcd(LL[i], MID), rmq::queryGcd(MID, RR[j])) % mod * cal(LL[i], LL[i - 1]) % mod * cal(RR[j], RR[j - 1]) % mod;
			ret%=mod;
		}
	}
	return (ret + fenzhi(L, MID - 1) + fenzhi(MID + 1, R)) % mod;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	rmq::init(n, a);
	ans = fenzhi(1, n);
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