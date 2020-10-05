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
vector<pii> vec;
char s[5];
int kase;
int cocnt, incocnt;
int coword[5], incoword[5];
int inco[5][5];

inline void solve()
{
	printf("Case #%d: ", ++kase);
	vec.resize(0);
	memarray(coword, 0), memarray(incoword, 0);
	memarray(inco, 0);
	cocnt = incocnt = 0;
	while (true)
	{
		scanf("%s", s);
		if (s[0] == '0' && s[1] == '0')
			break;
		vec.push_back(mp(s[0] - '0', s[1] - '0'));
	}
	int m = vec.size();
	for (int i = 0; i < m - 2; ++i)
		if (vec[i].first == vec[i + 1].first && vec[i + 1].first == vec[i + 2].first)
			return puts("Not Stroop"), void();
	for (int i = 0; i < m - 2; ++i)
		if (vec[i].second == vec[i + 1].second && vec[i + 1].second == vec[i + 2].second)
			return puts("Not Stroop"), void();
	for (auto i : vec)
	{
		if (i.first == i.second)
			cocnt++, coword[i.first]++;
		else
			incocnt++, incoword[i.second]++, inco[i.first][i.second]++;
	}
	if (cocnt != incocnt)
		return puts("Not Stroop"), void();
	for (int i = 1; i <= 4; ++i)
	{
		if (coword[i] != incoword[i])
			return puts("Not Stroop"), void();
	}
	for (int i = 1; i <= 4; ++i)
	{
		vector<int> tmp;
		for (int j = 1; j <= 4; ++j)
			if (i != j)
				tmp.push_back(inco[i][j]);
		if (tmp[0] != tmp[1] || tmp[1] != tmp[2] || tmp[0] != tmp[2])
			return puts("Not Stroop"), void();
	}
	puts("Stroop");
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