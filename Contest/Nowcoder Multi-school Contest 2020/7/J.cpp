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
#define vecall(v) v.begin(), v.end()
#define vecupsort(v) (sort(v.begin(), v.end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 30;
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
int n;
char s1[205][N], s2[205][N];
int f[N][N][N], g[N][N];
inline bool islower(char c) { return c >= 'a' && c <= 'z'; }
inline bool isupper(char c) { return c >= 'A' && c <= 'Z'; }
inline bool ismember(char *s) { return strlen(s) == 3; }
inline int idupper(char c) { return c - 'A'; }
inline int idlower(char c) { return c - 'a'; }

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%s = %s", s1[i], s2[i]);
	int cnt = 200;
	while (cnt--)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (!ismember(s1[i]) && islower(s2[i][0]))
				g[idupper(s1[i][0])][idlower(s2[i][0])] = true;
			else if (!ismember(s1[i]) && !ismember(s2[i]) && isupper(s2[i][0]))
			{
				for (int j = 0; j < 26; ++j)
					g[idupper(s1[i][0])][j] |= g[idupper(s2[i][0])][j];
			}
			else if (ismember(s1[i]) && !ismember(s2[i]))
			{
				for (int j = 0; j < 26; ++j)
					for (int k = 0; k < 26; ++k)
					{
						if (!g[idupper(s1[i][0])][j] || !g[idupper(s2[i][0])][k])
							continue;
						f[j][idlower(s1[i][2])][k] = true;
					}
			}
			else if (!ismember(s1[i]) && ismember(s2[i]))
			{
				for (int j = 0; j < 26; ++j)
					for (int k = 0; k < 26; ++k)
					{
						if (!g[idupper(s2[i][0])][j] || !f[j][idlower(s2[i][2])][k])
							continue;
						g[idupper(s1[i][0])][k] = true;
					}
			}
		}
	}

	for (int i = 0; i < 26; ++i, puts(""))
	{
		printf("%c: ", i + 'A');
		for (int j = 0; j <= 25; ++j)
		{
			if (g[i][j])
				printf("%c", j + 'a');
		}
	}
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}