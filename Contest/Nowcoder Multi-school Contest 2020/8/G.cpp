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
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 300;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353LL;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, kase;
int s[N][5];
vector<int> ans;
vector<int> id[3500];
unordered_map<string, int> hstr;
string strtmp[] = {"one", "two", "three", "diamond", "squiggle", "oval", "solid", "striped", "open", "red", "green", "purple"};

inline int Hash(int card[5])
{
	int ret = 0;
	int k = 1;
	for (int i = 1; i <= 4; ++i)
		ret += card[i] * k, k *= 10;
	return ret;
}

void solve()
{
	printf("Case #%d: ", ++kase);
	memarray(s, 0);
	for (int i = 0; i < 3500; ++i)
		id[i].resize(0);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		char ss[100];
		scanf("%s", ss);
		string tmp;
		int j = 1;
		int len = strlen(ss);
		for (int kk = 0; kk < len; ++kk)
		{
			if (ss[kk] == '[')
				continue;
			else if (ss[kk] == ']')
			{
				s[i][j] = hstr[tmp];
				tmp.clear();
				j++;
			}
			else
				tmp.push_back(ss[kk]);
		}
		id[Hash(s[i])].push_back(i);
		int nowcard[5] = {0};
		for (int k = 1; k <= 4; ++k)
			nowcard[k] = s[i][k];
		for (int a = 1; a <= 3; ++a)
			for (int b = 1; b <= 3; ++b)
				for (int c = 1; c <= 3; ++c)
					for (int d = 1; d <= 3; ++d)
					{
						if (s[i][1] == 0)
							s[i][1] = a;
						if (s[i][2] == 0)
							s[i][2] = b;
						if (s[i][3] == 0)
							s[i][3] = c;
						if (s[i][4] == 0)
							s[i][4] = d;
						id[Hash(s[i])].push_back(i);
						if (nowcard[1] == 0)
							s[i][1] = 0;
						if (nowcard[2] == 0)
							s[i][2] = 0;
						if (nowcard[3] == 0)
							s[i][3] = 0;
						if (nowcard[4] == 0)
							s[i][4] = 0;
					}
	}
	for (int i = 0; i < 3500; ++i)
		id[i].resize(unique(vecall(id[i])) - id[i].begin());
	for (int i = 0; i < 3500; ++i)
	{
		if (id[i].size() >= 3)
		{
			for (int j = 0; j < 3; ++j)
				printf("%d ", id[i][j]);
			putchar('\n');
			return;
		}
	}
	ans.resize(0);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			ans.resize(0);
			ans.push_back(i), ans.push_back(j);
			int card[5] = {0}, card2[5] = {0};
			for (int k = 1; k <= 4; ++k)
			{
				if (s[i][k] == 0 || s[j][k] == 0)
					continue;
				if (s[i][k] == s[j][k])
					card[k] = s[i][k];
				else
					card[k] = 6 - s[i][k] - s[j][k];
				card2[k] = card[k];
			}
			for (int a = 1; a <= 3 && ans.size() < 3; ++a)
				for (int b = 1; b <= 3 && ans.size() < 3; ++b)
					for (int c = 1; c <= 3 && ans.size() < 3; ++c)
						for (int d = 1; d <= 3 && ans.size() < 3; ++d)
						{
							if (card[1] == 0)
								card[1] = a;
							if (card[2] == 0)
								card[2] = b;
							if (card[3] == 0)
								card[3] = c;
							if (card[4] == 0)
								card[4] = d;
							for (auto k : id[Hash(card)])
							{
								if (k == i || k == j)
									continue;
								ans.push_back(k);
								break;
							}
							if (card2[1] == 0)
								card[1] = 0;
							if (card2[2] == 0)
								card[2] = 0;
							if (card2[3] == 0)
								card[3] = 0;
							if (card2[4] == 0)
								card[4] = 0;
						}
			if (ans.size() == 3)
				break;
		}
		if (ans.size() == 3)
			break;
	}
	if (ans.size() < 3)
		return puts("-1"), void();
	for (auto i : ans)
		printf("%d ", i);
	puts("");
}

int main()
{
	TIME__START = clock();
	for (int i = 0; i < 12; ++i)
		hstr.insert({strtmp[i], i % 3 + 1});
	hstr.insert(mp("*", 0));
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}