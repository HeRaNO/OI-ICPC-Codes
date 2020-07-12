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
const int N = 250;
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

struct classMatrix
{
	static const int MAXN = N;
	static const ll M = mod;
	struct Matrix
	{
		long long m[MAXN][MAXN];
		void Init()
		{
			memarray(m, 0);
		}
	};

	int T, n, m, rnk, _0r, _0c, alpha[MAXN], beta[MAXN];
	Matrix a, ast, b, c, inva;
	long long det;
	bool vis[MAXN];
	void Init()
	{
		a.Init(), ast.Init(), b.Init(), c.Init(), inva.Init();
		memarray(vis, 0);
		T = n = m = rnk = _0c = _0r = 0;
		memarray(alpha, 0), memarray(beta, 0);
		det = 0;
	}

	inline long long fpow(long long a, long long b)
	{
		long long r = 1;
		if (a == 1)
			return 1LL;
		for (; b; b >>= 1, a = (a * a) % M)
			if (b & 1)
				r = (r * a) % M;
		return r;
	}

	inline void getDetAndRank(Matrix a)
	{
		memset(vis, 0, sizeof vis);
		det = 1;
		rnk = n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				ast.m[i][j] = i == j;
		for (int i = 1; i <= n; i++)
		{
			int now = 0;
			for (int j = 1; j <= n && !now; j++)
				if (!vis[j] && a.m[j][i])
					now = j;
			if (!now)
			{
				--rnk;
				continue;
			}
			if (now != i)
				det = -det;
			vis[i] = true;
			for (int j = 1; j <= n; j++)
			{
				swap(a.m[now][j], a.m[i][j]);
				swap(ast.m[now][j], ast.m[i][j]);
			}
			long long t = fpow(a.m[i][i], M - 2);
			for (int j = 1; j <= n; j++)
				if (j != i)
				{
					long long x = a.m[j][i] * t % M;
					for (int k = 1; k <= n; k++)
					{
						a.m[j][k] -= x * a.m[i][k] % M;
						(a.m[j][k] += M) %= M;
						ast.m[j][k] -= x * ast.m[i][k] % M;
						(ast.m[j][k] += M) %= M;
					}
				}
		}
		det = (det + M) % M;
		for (int i = 1; i <= n; i++)
		{
			(det *= a.m[i][i]) %= M;
			long long t = fpow(a.m[i][i], M - 2);
			for (int j = 1; j <= n; j++)
				(ast.m[i][j] *= t) %= M;
		}
		return;
	}
	void getInva()
	{
		ll invDet = fpow(det, M - 2);
		// for (int i = 1; i <= n; ++i)
		// {
		//     for (int j = 1; j <= n; ++j)
		//     {
		//         // inva.m[i][j] = ast.m[i][j] * invDet % M;
		//         // printf("%lld ", ast.m[i][j]);
		//     }
		//     // puts("");
		// }
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				inva.m[i][j] = ast.m[i][j] * invDet % M;
				// printf("%lld ", inva.m[i][j]);
			}
			puts("");
		}
	}
	inline Matrix Gauss_Elimination(Matrix a)
	{
		memset(vis, false, sizeof vis);
		for (int i = 1; i <= n; i++)
		{
			int now = 0;
			for (int j = 1; j <= n && !now; j++)
				if (!vis[j] && a.m[j][i])
					now = j;
			if (!now)
				continue;
			vis[i] = true;
			for (int j = 1; j <= n; j++)
				swap(a.m[now][j], a.m[i][j]);
			long long t = fpow(a.m[i][i], M - 2);
			for (int j = 1; j <= n; j++)
				if (j != i)
				{
					long long x = a.m[j][i] * t % M;
					for (int k = 1; k <= n; k++)
						a.m[j][k] -= x * a.m[i][k] % M, (a.m[j][k] += M) %= M;
				}
		}
		return a;
	}
} Mat;
int n;
ll b[N];

void solve()
{
	Mat.Init();
	Mat.n = n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%lld", &Mat.a.m[i][j]);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &b[i]);
	Mat.getDetAndRank(Mat.a);
	// Mat.getInva();
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			ans += b[i] * b[j] % mod * Mat.ast.m[i][j] % mod;
			ans = (ans % mod + mod) % mod;
		}
	printf("%lld\n", ans);
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (scanf("%d", &n) == 1)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}