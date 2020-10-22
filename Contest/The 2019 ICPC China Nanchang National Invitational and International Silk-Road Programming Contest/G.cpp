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
int n, Q;
struct pos
{
	int a, b, c;
	bool operator<=(const pos &p) const
	{
		return a <= p.a || b <= p.b || c <= p.c;
	}
} p[N];
pair<int, int> pa[N], pb[N], pc[N];
inline void getmin(pos &x, pos &y)
{
	x.a = min(x.a, y.a);
	x.b = min(x.b, y.b);
	x.c = min(x.c, y.c);
}

inline void solve()
{
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &pa[i].first);
		pa[i].second = i;
		p[i].a = pa[i].first;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &pb[i].first);
		pb[i].second = i;
		p[i].b = pb[i].first;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &pc[i].first);
		pc[i].second = i;
		p[i].c = pc[i].first;
	}
	sort(pa + 1, pa + n + 1);
	sort(pb + 1, pb + n + 1);
	sort(pc + 1, pc + n + 1);
	pos now = (pos){inf, inf, inf};
	getmin(now, p[pa[n].second]);
	getmin(now, p[pb[n].second]);
	getmin(now, p[pc[n].second]);
	for (int i = n - 1; i; --i)
	{
		int tmp = pa[i].second;
		if (now.a <= p[tmp].a)
			getmin(now, p[tmp]);
		tmp = pb[i].second;
		if (now.b <= p[tmp].b)
			getmin(now, p[tmp]);
		tmp = pc[i].second;
		if (now.c <= p[tmp].c)
			getmin(now, p[tmp]);
	}
	while (Q--)
	{
		int x;
		scanf("%d", &x);
		if (now <= p[x])
			printf("YES\n");
		else
			printf("NO\n");
	}
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