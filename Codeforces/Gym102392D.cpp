#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
using namespace std;
const int N = 1000050;
const int inf = 0x3f3f3f3f;
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
int tot, mx, mxalpha;
int cnt[30];

void solve2()
{
	if (cnt[mxalpha] >= 2 * (n / 2) - 2)
	{
		puts("NO");
		return;
	}
	for (int i = 1; i <= n / 2; ++i)
	{
		s[i] = mxalpha + 'a';
		cnt[mxalpha]--;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] && i != mxalpha)
		{
			cnt[i]--;
			s[n / 2 + 1] = i + 'a';
			break;
		}
	}
	int j = n / 2 + 2;
	for (int i = n / 2 + 2; cnt[mxalpha] > 0; ++i)
	{
		s[j] = mxalpha + 'a';
		cnt[mxalpha]--;
		j++;
	}
	for (int i = 0; i < 26; ++i)
	{
		while (cnt[i])
		{
			s[j++] = i + 'a';
			cnt[i]--;
		}
	}
	printf("YES\n%s\n", s + 1);
}
void solve3()
{
	puts("YES");
	for (int i = 1; i <= n / 2; ++i)
	{
		s[i] = mxalpha + 'a';
		cnt[mxalpha]--;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] && i != mxalpha)
		{
			cnt[i]--;
			s[n / 2 + 1] = i + 'a';
			break;
		}
	}
	int j = n / 2 + 2;
	for (int i = j; cnt[mxalpha]; ++i)
	{
		s[j++] = mxalpha + 'a';
		cnt[mxalpha]--;
	}
	for (int i = 0; i < 26; ++i)
	{
		while (cnt[i])
		{
			s[j++] = i + 'a';
			cnt[i]--;
		}
	}
	printf("%s\n", s + 1);
}

void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (cnt[s[i] - 'a'] == 0)
			tot++;
		cnt[s[i] - 'a']++;
		if (cnt[s[i] - 'a'] > mx)
		{
			mx = cnt[s[i] - 'a'];
			mxalpha = s[i] - 'a';
		}
	}
	if (mx <= n / 2)
	{
		sort(s + 1, s + n + 1);
		puts("YES");
		printf("%s\n", s + 1);
		return;
	}
	if (tot <= 2)
		solve2();
	else
		solve3();
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}