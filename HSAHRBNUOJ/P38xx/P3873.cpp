#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXN 5
#define MOD 10000007
using namespace std;

const int d[8][2] =
{
	{1, 0}, {0, 1}, {-1, 0}, {0, -1},
	{1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

int n;
int st, ed, _3pow[17];
char g[MAXN][MAXN], t[MAXN][MAXN];
int a[MAXN][MAXN];
bool vis[MOD];
queue <pair<int, int> > q;

inline int trans(char a)
{
	if (a == '*') return 0;
	if (a == 'w') return 1;
	if (a == 'b') return 2;
	return 0;
}

inline int zip()
{
	int cnt = 0, x = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			x += a[i][j] * _3pow[++cnt];
	return x;
}

inline void spread(int status)
{
	int cnt = n * n;
	for (int i = n; i; i--)
		for (int j = n; j; j--)
		{
			a[i][j] = status / _3pow[cnt];
			status %= _3pow[cnt--];
		}
	return ;
}

inline void Prework()
{
	_3pow[0] = 1;
	for (int i = 1; i <= n * n; i++) _3pow[i] = _3pow[i - 1] * 3;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = trans(g[i][j]);
	st = zip();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = trans(t[i][j]);
	ed = zip();
	return ;
}

inline bool check(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > n || a[x][y] || g[x][y] == '#' || t[x][y] == '#') return false;
	return true;
}

inline int BFS()
{
	q.push(make_pair(st, 0));
	vis[st % MOD] = true;
	while (!q.empty())
	{
		pair <int, int> u = q.front();
		q.pop();
		if (u.first == ed) return u.second;
		spread(u.first);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[i][j] == (u.second & 1) + 1)
				{
					for (int k = 0; k < 8; k++)
					{
						int tx = i, ty = j;
						while (check(tx + d[k][0], ty + d[k][1])) tx += d[k][0], ty += d[k][1];
						if (tx == i && ty == j) continue;
						swap(a[i][j], a[tx][ty]);
						int t = zip();
						if (!vis[t % MOD])
						{
							vis[t % MOD] = true;
							q.push(make_pair(t, u.second + 1));
						}
						swap(a[i][j], a[tx][ty]);
					}
				}
	}
	return -1;
}

int main()
{
	//freopen("chess.in","r",stdin);freopen("chess.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= n; i++) scanf("%s", t[i] + 1);
	Prework();
	printf("%d\n", BFS());
	return 0;
}
