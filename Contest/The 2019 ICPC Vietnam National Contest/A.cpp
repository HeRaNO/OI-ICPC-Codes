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
const int N = 2000050, MAXN = N;
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

string s[MAXN];
int n, m, dis[N];
int getid(int x, int y)
{
	return x * m + y;
}
pii getdix(int st)
{
	return {st / m, st % m};
}
queue<int> q;
inline void solve()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int st = 0;
	q.push(st);
	memset(dis, 0x3f, sizeof(dis));
	dis[st] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		pii tmp = getdix(u);
		int x = tmp.first, y = tmp.second;
		if (x >= n - 1)
		{
			printf("%d\n", dis[u] + 1);
			return;
		}
		int ny = (y - 2 + m) % m, py = (y - 1 + m) % m;
		if (s[x][ny] != 'M' && s[x][py] != 'M' && dis[getid(x, ny)] > dis[u] + 1)
		{
			dis[getid(x, ny)] = dis[u] + 1;
			q.push(getid(x, ny));
		}
		if (s[x][py] != 'M' && dis[getid(x, py)] > dis[u] + 1)
		{
			dis[getid(x, py)] = dis[u] + 1;
			q.push(getid(x, py));
		}
		int px = (x + 1);
		if (s[px][py] != 'M' && s[px][y] != 'M' && dis[getid(px, py)] > dis[u] + 1)
		{
			dis[getid(px, py)] = dis[u] + 1;
			q.push(getid(px, py));
		}
		int tx = (x - 1);
		if (tx >= 0 && s[tx][py] != 'M' && s[tx][y] != 'M' && dis[getid(tx, py)] > dis[u] + 1)
		{
			dis[getid(tx, py)] = dis[u] + 1;
			q.push(getid(tx, py));
		}
	}
	puts("-1");
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	//scanf("%d", &Test);
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
