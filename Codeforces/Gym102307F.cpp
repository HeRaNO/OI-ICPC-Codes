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
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
char s[N];
int n;
struct Angle
{
	ll x, y;
	Angle() {}
	Angle(ll _x, ll _y)
	{
		bool f = (_x < 0);
		if (f)
			_x = -_x;
		ll t = __gcd(_x, _y);
		_x /= t;
		_y /= t;
		if (!_x)
			_y = 1;
		if (f)
			_x = -_x;
		x = _x;
		y = _y;
	}
	void clear()
	{
		x = 0, y = 1;
	}
};
Angle ans;
bool isNum(char c) { return c <= '9' && c >= '0'; }
bool isDivisor(char c) { return c == '/'; }
bool isOperator(char c) { return c == '+' || c == '-'; }
inline Angle operator+(const Angle &A, const Angle &B)
{
	ll fenmu = A.y * B.y;
	ll fenzi = A.x * B.y + A.y * B.x;
	return Angle(fenzi, fenmu);
}
inline Angle operator-(const Angle &A, const Angle &B)
{
	ll fenmu = A.y * B.y;
	ll fenzi = A.x * B.y - A.y * B.x;
	return Angle(fenzi, fenmu);
}
stack<Angle> sta;
int op, rev[N];

void solve()
{
	while (!sta.empty())
		sta.pop();
	ans.clear();
	n = strlen(s + 1);
	int i = 1;
	for (int i = 0; i <= n; ++i)
		rev[i] = 0;
	op = 1;
	int now = 1;
	int cnt = 0;
	while (i < n)
	{
		Angle tmp;
		bool flag = false;
		if (isNum(s[i]))
		{
			ll fenzi = 0, fenmu = 0;
			while (!isDivisor(s[i]))
			{
				fenzi *= 10;
				fenzi += s[i] - '0';
				i++;
			}
			i++;
			while (isNum(s[i]))
			{
				fenmu *= 10;
				fenmu += s[i] - '0';
				i++;
			}
			sta.push(Angle(fenzi, fenmu));
			flag = true;
		}
		else if (isOperator(s[i]))
		{
			if (s[i] == '+')
				op = 1;
			else
				op = -1;
			i++;
		}
		else if (s[i] == '(')
		{
			now++;
			if (s[i - 1] == '-')
				rev[now] = rev[now - 1] ^ 1;
			else if (s[i - 1] == '(' || s[i - 1] == '+')
				rev[now] = rev[now - 1];
			op = 1;
			i++;
		}
		else if (s[i] == ')')
		{
			rev[now] = 0;
			now--;
			i++;
		}
		if (flag && sta.size() >= 1)
		{
			Angle frac = sta.top();
			sta.pop();
			if ((op == 1 && rev[now] == 0) || (op == -1 && rev[now] == 1))
				ans = ans + frac;
			else if ((op == 1 && rev[now] == 1) || (op == -1 && rev[now] == 0))
				ans = ans - frac;
		}
	}
	printf("%lld/%lld\n", ans.x, ans.y);
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (scanf("%s", s + 1) == 1)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}
/*
1/2-(-1/2-(-1/2))
*/