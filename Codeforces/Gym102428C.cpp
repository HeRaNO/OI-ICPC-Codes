#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
using namespace std;
const int N = 100050;
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
int n, Q;
ll a[N], L, U;
ll sum[N];
ll minsum[N][20], maxsum[N][20];
int nxt[N][2][20];
void presum()
{
	for (int i = 1; i <= n; ++i)
	{
		minsum[i][0] = maxsum[i][0] = sum[i];
	}
	for (int j = 1; j < 18; ++j)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i + st(j - 1) > n + 1)
				break;
			minsum[i][j] = min(minsum[i][j - 1], minsum[i + st(j - 1)][j - 1]);
			maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + st(j - 1)][j - 1]);
		}
	}
}
inline ll qmax(ll l, ll r)
{
	int k = (int)log2(1.0 * r - l + 1);
	return max(maxsum[l][k], maxsum[r - st(k) + 1][k]);
}
inline ll qmin(ll l, ll r)
{
	int k = (int)log2(1.0 * r - l + 1);
	return min(minsum[l][k], minsum[r - st(k) + 1][k]);
}
inline int getnode(int pos, int f, int k)
{
	if (pos > n)
		return nxt[pos][f][k] = (n + 1) * 2;
	if (nxt[pos][f][k])
		return nxt[pos][f][k];
	int t = getnode(pos, f, k - 1);
	nxt[pos][f][k] = getnode(t >> 1, t & 1, k - 1);
	return nxt[pos][f][k];
}

inline int calnxt(int pos, ll coin)
{
	int l = pos + 1, r = n + 1, ret = pos;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (coin + qmax(pos, mid - 1) >= U + sum[pos - 1] || coin + qmin(pos, mid - 1) <= L + sum[pos - 1])
			r = mid - 1;
		else
			l = mid + 1, ret = mid;
	}
	if (ret > n)
		return ret * 2;
	else if (coin + sum[ret] - sum[pos - 1] > L)
		return ret * 2 + 1;
	else
		return ret * 2;
}
void prenxt()
{
	for (int i = 0; i <= n; ++i)
	{
		nxt[i][0][0] = calnxt(i + 1, L);
		nxt[i][1][0] = calnxt(i + 1, U);
	}
}

void solve()
{
	scanf("%d%lld%lld", &n, &L, &U);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
	presum();
	prenxt();
	scanf("%d", &Q);
	while (Q--)
	{
		int B, E, X;
		scanf("%d%d%d", &B, &E, &X);
		int pos = calnxt(B, X);
		if ((pos >> 1) >= E)
		{
			ll ans = X + sum[E] - sum[B - 1];
			ans = min(ans, U);
			ans = max(ans, L);
			printf("%lld\n", ans);
		}
		else
		{
			for (int i = 17; i >= 0; --i)
			{
				int tmp = getnode(pos >> 1, pos & 1, i);
				if ((tmp >> 1) <= E)
					pos = tmp;
			}
			ll ans = sum[E] - sum[pos >> 1];
			if (pos & 1)
				ans += U;
			else
				ans += L;
			ans = min(ans, U);
			ans = max(ans, L);
			printf("%lld\n", ans);
		}
	}
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