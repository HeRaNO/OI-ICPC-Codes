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
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, k;
vector<pii> anshang, anslie;
void printans()
{
	sort(anshang.begin(), anshang.end());
	sort(anslie.begin(), anslie.end());
	int nowtot = 0;
	for (auto i : anshang)
	{
		nowtot++;
		printf("%d ", i.second);
		if (nowtot % n == 0)
			puts("");
	}
	nowtot = 0;
	for (auto i : anslie)
	{
		nowtot++;
		printf("%d ", i.second);
		if (nowtot % n == 0)
			puts("");
	}
}
int starthang, startlie;
int every;
int nowcolor;
int havecolored;
int cnt;
void drawhang()
{
	int x = starthang, y = starthang * n + 1;
	int nowtot = 0;
	while (nowtot < n - starthang + 1)
	{
		anshang.push_back(mp(x, nowcolor));
		cnt--;
		if (cnt == 0)
			cnt = every, nowcolor++;
		anslie.push_back(mp(y, nowcolor));
		x += n + 1, y += n + 1;
		cnt--;
		if (cnt == 0)
			cnt = every, nowcolor++;
		nowtot++;
		havecolored += 2;
	}
	starthang += 2;
}
void drawlie()
{
	int x = startlie * n + 1, y = startlie;
	int nowtot = 0;
	while (nowtot < n - startlie + 1)
	{
		anslie.push_back(mp(y, nowcolor));
		cnt--;
		if (cnt == 0)
			cnt = every, nowcolor++;
		anshang.push_back(mp(x, nowcolor));
		x += n + 1, y += n + 1;
		cnt--;
		if (cnt == 0)
			cnt = every, nowcolor++;
		nowtot++;
		havecolored += 2;
	}
	startlie += 2;
}

void solve()
{
	anshang.clear(), anslie.clear();
	nowcolor = 1;
	starthang = 1;
	startlie = 2;
	scanf("%d%d", &n, &k);
	if (n == 1)
		return puts("-1"), void();
	if (n == 2 && k == 3)
	{
		puts("1 2\n3 1\n3 2\n1 3\n2 1\n2 3");
		return;
	}
	if (n * 2 * (n + 1) % k != 0 || k == 1)
		return puts("-1"), void();
	every = n * 2 * (n + 1) / k;
	cnt = every;
	havecolored = 0;
	bool flag = 0;
	while (havecolored < n * (n + 1))
	{
		if (flag == 0)
			drawhang();
		else
			drawlie();
		flag ^= 1;
	}
	flag = 0;
	starthang = 2;
	startlie = 1;
	while (nowcolor <= k)
	{
		if (flag == 0)
			drawlie();
		else
			drawhang();
		flag ^= 1;
	}
	printans();
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}