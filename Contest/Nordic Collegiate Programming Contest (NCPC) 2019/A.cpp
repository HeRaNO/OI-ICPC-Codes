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
int n, m;
char s[N];
char fir[N], lst[N];
vector<int> vec, vecid;
int vis[30];
char t[N][30];

inline void solve()
{
	scanf("%s", s + 1);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", t[i] + 1);
		int len = strlen(t[i] + 1);
		fir[i] = t[i][1], lst[i] = t[i][len];
		vis[fir[i] - 'a']++;
	}
	m = strlen(s + 1);
	char nowlst = s[m];
	for (int i = 1; i <= n; ++i)
	{
		if (fir[i] == nowlst)
			vec.push_back(lst[i] - 'a'), vecid.push_back(i);
	}
	if (vec.empty())
		return puts("?"), void();
	for (auto i : vecid)
	{
		vis[fir[i] - 'a']--;
		if (!vis[lst[i] - 'a'])
			return printf("%s!\n", t[i] + 1), void();
		vis[fir[i] - 'a']++;
	}
	printf("%s\n", t[vecid[0]] + 1);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
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