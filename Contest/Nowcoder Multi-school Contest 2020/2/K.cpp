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
#define db double
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
const double PI = acos(-1.0);
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
double a, b, c, d, L, R;
double r1, r2, r3;
double theta1;
inline double Fun2(double x)
{
	double A = r3 * (r1 - r2 * sin(x)), B = r2 * r3 * cos(x), C = -r1 * r2 * cos(x);
	if (fabs(A) < 1e-7 && fabs(B) < 1e-7)
		return 0;
	double p = sqrt(A * A + B * B);
	A /= p;
	B /= p;
	C /= p;
	if (C < 0)
		C = -C;
	double ans = C * 2 * PI;
	if (C < 1)
	{
		double t1 = asin(C), t2 = PI - t1;
		ans -= 2 * C * (t2 - t1);
		ans += 2 * ((-cos(t2)) - (-cos(t1)));
	}
	return p * ans / 2 / PI;
}
inline double simpson(double a, double b)
{
	return (b - a) / 6 * (Fun2(a) + 4 * Fun2((a + b) / 2) + Fun2(b));
}
double asr(db l, db r, db exps, db val)
{
	db mid = (l + r) / 2;
	db lval = simpson(l, mid), rval = simpson(mid, r);
	if (fabs(lval + rval - val) <= 15 * exps)
	{
		return lval + rval + (lval + rval - val) / 15;
	}
	return asr(l, mid, exps / 2, lval) + asr(mid, r, exps / 2, rval);
}
inline double asme(double l, double r, double exps) { return asr(l, r, exps, simpson(l, r)); }

inline void solve()
{
	cin >> r1 >> r2 >> r3;
	double ans = asme(1e-7, 2*PI - (1e-7), 1e-7);
	printf("%.1lf\n", ans / 2 / PI / 2);
}

int main()
{
	// freopen("K.in", "r", stdin);
	// freopen("K.out", "w", stdout);
	TIME_START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}