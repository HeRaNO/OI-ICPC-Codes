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
const int N = 2000050;
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
int n;
char s[N];
int ans;
int yuer, fish;
int cnt0, cnt1;

void solve()
{
	yuer = fish = cnt0 = cnt1 = 0;
	ans = 0;
	cin >> n;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] - '0' == 0)
			cnt0++;
		else if (s[i] - '0' == 1)
			cnt1++;
	}
	for (int i = 1; i <= n; ++i)
	{
		int type = s[i] - '0';
		switch (type)
		{
			case 0:
			{
				if (yuer > 0)
					ans++, yuer--;
				cnt0--;
				break;
			}
			case 1:
			{
				cnt1--;
				if (yuer > 0 && yuer + 1 > cnt0+cnt1)
				{
					yuer--;
					ans++;
				}
				else
					yuer++;
				break;
			}
			case 2:
			{
				ans++;
				break;
			}
			case 3:
			{
				ans++;
				break;
			}
		}
	}
	cout << ans << '\n';
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}