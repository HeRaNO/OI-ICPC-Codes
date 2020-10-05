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
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
ll d[505][505];
ll pcost[505][505];
ll rec[505][505];
ll layers[505];
ll F, L, n;
inline void solve()
{
	scanf("%lld%lld", &F, &L);
	for (int i = 0; i < F; ++i)
	{
		for (int j = 0; j < F; ++j)
			scanf("%lld", &d[i][j]);
		for (int j = 0; j < L; ++j)
			scanf("%lld", &pcost[i][j]);
		for (int j = 0; j < L; ++j)
			scanf("%lld", &rec[i][j]);
	}
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &layers[i]);
		layers[i]--;
	}
	vector<ll> mn(F, llinf);
	for (int i = 0; i < n; ++i)
	{
		ll nowlay = layers[i];
		if (!i)
		{
			for (int j = 0; j < F; ++j)
			{
				ll pCost = pcost[j][nowlay];
				if (~pCost)
					mn[j] = pCost;
			}
		}
		else
		{
			vector<ll> tmpv(F, llinf);
			for (int j = 0; j < F; ++j)
			{
				if (mn[j] != llinf)
				{
					ll mnc = mn[j];
					for (int i = 0; i < F; ++i)
					{
						ll costnow = d[j][i];
						ll prodCost = pcost[i][nowlay];
						if (prodCost != -1)
						{
							ll nCost = mnc + costnow + prodCost;
							tmpv[i] = min(tmpv[i], nCost);
						}
					}
				}
			}
			mn = tmpv;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		ll nowlay = layers[n - 1 - i];
		if (!i)
		{
			vector<ll> tmpv(F, llinf);
			for (int c = 0; c < F; ++c)
			{
				if (mn[c] != llinf)
				{
					ll mnc = mn[c];
					for (int i = 0; i < F;++i)
					{
						ll rCost = rec[i][nowlay];
						if (rCost != -1)
						{
							ll nCost = mnc + rCost;
							tmpv[i] = min(tmpv[i], nCost);
						}
					}
				}
			}
			mn = tmpv;
		}
		else
		{
			vector<ll> tmpv(F, llinf);
			for (int c = 0; c < F; ++c)
			{
				if (mn[c] != llinf)
				{
					ll mnc = mn[c];
					for (int i = 0; i < F;++i)
					{
						ll costnow = d[c][i];
						ll rCost = rec[i][nowlay];
						if (rCost != -1)
						{
							ll nCost = mnc + costnow + rCost;
							tmpv[i] = min(tmpv[i], nCost);
						}
					}
				}
			}
			mn = tmpv;
		}
	}
	ll ans = llinf;
	for (int i = 0; i < F; ++i)
		ans = min(ans, mn[i]);
	printf("%lld\n",ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
	{
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}