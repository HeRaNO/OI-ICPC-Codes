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
const int N = 550;
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
int n;
char a[N * N];
char s[N][N];
int dx[] = {1, -1, 2, -2, -1, 1, 2, -2};
int dy[] = {-2, 2, -1, 1, -2, 2, 1, -1};
char op[] = "ICPCASIASG";
struct tri
{
	int x, y;
	int deep;
	tri()
	{
	}
	tri(int _x, int _y, int _deep) : x(_x), y(_y), deep(_deep) {}
};
queue<tri> q;
bool bfs()
{
	// for (int i = 1; i <= n; ++i, puts(""))
	//     printf("%s", s[i] + 1);
	while (!q.empty())
	{
		tri u = q.front();
		q.pop();
		if (u.deep == 9)
			return 1;
		for (int k = 0; k < 8; ++k)
		{
			int nx = u.x + dx[k], ny = u.y + dy[k];
			int ndep = u.deep + 1;
			if (nx < 1 || ny < 1 || nx > n || ny > n || s[nx][ny] != op[ndep])
				continue;
			q.push(tri(nx, ny, ndep));
		}
	}
	return 0;
}

inline void solve()
{
	scanf("%d", &n);
	scanf("%s", a + 1);
	int m = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			s[i][j] = a[++m];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (s[i][j] == 'I')
				q.push(tri(i, j, 0));
		}
	bool solved = bfs();
	if (solved)
		puts("YES");
	else
		puts("NO");
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
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
