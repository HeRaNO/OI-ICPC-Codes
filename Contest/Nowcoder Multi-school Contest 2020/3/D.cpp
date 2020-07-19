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
int n, m;
int xiajie[55];
int shangjie[55];
pii nxt[55][255];
bool isend[55][255];
int a[105][205];
vector<pii> ans;
bool isValid(int n, int m)
{
	return n * 4 >= m && m >= xiajie[n] && (m % 2 == 0);
}
int howmany(int x, int y)
{
	return a[x][y + 1] + a[x - 1][y] + a[x + 1][y] + a[x][y - 1];
}
void initxiajie()
{
	xiajie[1] = 4, xiajie[2] = 6;
	int nowshangjie = 2, now = 8;
	shangjie[1] = shangjie[2] = 1;
	int cnt2 = 0;
	int cnt = 0;
	for (int i = 3; i <= 50; ++i)
	{
		xiajie[i] = now;
		shangjie[i] = nowshangjie;
		cnt++;
		if (cnt == nowshangjie)
		{
			cnt2++;
			cnt = 0;
			now += 2;
			if (cnt2 == 2)
			{
				cnt2 = 0;
				nowshangjie++;
			}
		}
	}
}

void initdraw(int n, int m)
{
	int hang = shangjie[n];
	int shang = n / hang;
	if (n % hang > 0)
		shang++;
	int nown = n;
	for (int j = 1; j <= hang; ++j)
	{
		int nowmx = min(shang, nown);
		for (int i = 1; i <= nowmx; ++i)
		{
			a[i][j] = 1;
			nown--;
		}
	}
}
int nowm;
void change1(int x, int y)
{
	for (int i = 100; i > 0; --i)
	{
		if (a[i][1] == 0 && howmany(i, 1) == 1)
		{
			a[x][y] = 0;
			a[i][1] = 1;
			return;
		}
	}
}
void process1()
{
	if (nowm == m)
		return;
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (a[i][j] == 1 && howmany(i, j) == 2)
			{
				change1(i, j);
				nowm += 2;
				if (nowm == m)
					return;
			}
		}
	}
}
void process2()
{
	int nowj = 200;
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (a[i][j] == 0)
				continue;
			if (howmany(i, j) != 1)
				continue;
			a[i][j] = 0;
			a[i][nowj] = 1;
			nowm += 2;
			nowj-=2;
			if (nowm == m)
				return;
		}
	}
}

void solve()
{
	memarray(a, 0);
	cin >> n >> m;
	if (!isValid(n, m))
		return puts("No"), void();
	puts("Yes");
	initdraw(n, m);
	nowm = xiajie[n];
	process1();
	if (nowm < m)
		process2();
	for (int i = 0; i <= 100; ++i)
		for (int j = 0; j <= 200; ++j)
			if (a[i][j] == 1)
				printf("%d %d\n", i, j);
}

int main()
{
	TIME_START = clock();
	initxiajie();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}