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
string s1, s2;
int n, m;
bool flag;
bool ispre()
{
	for (int i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i])
			return 0;
	}
	return 1;
}

void solve()
{
	flag = 0;
	n = s1.length(), m = s2.length();
	if (n > m)
		swap(s1, s2), flag = 1;
	n = s1.length(), m = s2.length();
	if (ispre())
	{
		if (n == m)
			return puts("="), void();
		for (int i = 0; i < m; ++i)
			s2.push_back(s2[i]);
		int j = 0;
		while (s1.length() < s2.length())
		{
			s1.push_back(s1[j]);
			j++;
		}
	}
	if (s1 > s2)
	{
		if (flag)
			puts("<");
		else
			puts(">");
	}
	else if (s1 == s2)
		puts("=");
	else
	{
		if (flag)
			puts(">");
		else
			puts("<");
	}
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (cin >> s1 >> s2)
	{
		solve();
		s1.clear(), s2.clear();
	}
	TIME_END = clock();
	program_end();
	return 0;
}
