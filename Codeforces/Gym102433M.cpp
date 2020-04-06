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
using namespace std;
const int N = 1050;
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
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int r, c;
char s[N][N];
bool vis[N][N];
int ans;
int f[N * N];
inline int id(int x, int y) { return (x - 1) * c + y; }
int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }

inline int bfs(int x, int y)
{
	int flag = 1;
	queue<pii> q;
	q.push(mp(x, y));
	vis[x][y] = 1;
	while (!q.empty())
	{
		pii u = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int nx = u.first + dx[k];
			int ny = u.second + dy[k];
			if (nx >= 1 && ny >= 1 && nx <= r && ny <= c && s[nx][ny] != '\\' && s[nx][ny] != '/')
			{
				int fx = Find(id(nx, ny));
				int fy = Find(id(u.first, u.second));
				if (fx != fy)
					f[fy] = fx;
				if (Find(id(u.first, u.second)) == Find(r * c + 1))
					flag = false;
				if (!vis[nx][ny])
				{
					vis[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
		}
		int x = u.first, y = u.second;
		if (s[x - 1][y + 1] == '.' && (s[x - 1][y] == '.' || s[x][y + 1] == '.' || (s[x - 1][y] == '/' && s[x][y + 1] == '/')))
		{
			int fx = Find(id(x, y));
			int fy = Find(id(x - 1, y + 1));
			if (fx != fy)
				f[fy] = fx;
			if (Find(id(x, y)) == Find(r * c + 1))
				flag = false;
			if (!vis[x - 1][y + 1])
			{
				vis[x - 1][y + 1] = 1;
				q.push({x - 1, y + 1});
			}
		}
		if (s[x + 1][y - 1] == '.' && (s[x + 1][y] == '.' || s[x][y - 1] == '.' || (s[x + 1][y] == '/' && s[x][y - 1] == '/')))
		{
			int fx = Find(id(x, y));
			int fy = Find(id(x + 1, y - 1));
			if (fx != fy)
				f[fy] = fx;
			if (Find(id(x, y)) == Find(r * c + 1))
				flag = false;
			if (!vis[x + 1][y - 1])
			{
				vis[x + 1][y - 1] = 1;
				q.push({x + 1, y - 1});
			}
		}
		if (s[x - 1][y - 1] == '.' && (s[x - 1][y] == '.' || s[x][y - 1] == '.' || (s[x - 1][y] == '\\' && s[x][y - 1] == '\\')))
		{
			int fx = Find(id(x, y));
			int fy = Find(id(x - 1, y - 1));
			if (fx != fy)
				f[fy] = fx;
			if (Find(id(x, y)) == Find(r * c + 1))
				flag = false;
			if (!vis[x - 1][y - 1])
			{
				vis[x - 1][y - 1] = 1;
				q.push({x - 1, y - 1});
			}
		}
		if (s[x + 1][y + 1] == '.' && (s[x + 1][y] == '.' || s[x][y + 1] == '.' || (s[x + 1][y] == '\\' && s[x][y + 1] == '\\')))
		{
			int fx = Find(id(x, y));
			int fy = Find(id(x + 1, y + 1));
			if (fx != fy)
				f[fy] = fx;
			if (Find(id(x, y)) == Find(r * c + 1))
				flag = false;
			if (!vis[x + 1][y + 1])
			{
				vis[x + 1][y + 1] = 1;
				q.push({x + 1, y + 1});
			}
		}
	}
	return flag;
}

void solve()
{
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; ++i)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			f[id(i, j)] = id(i, j);
	f[r * c + 1] = r * c + 1;
	for (int i = 1; i <= r; ++i)
	{
		if (s[i][1] == '.')
		{
			int fx = Find(id(i, 1));
			int fy = Find(r * c + 1);
			if (fx != fy)
				f[fy] = fx;
			vis[i][1] = 1;
		}
		if (s[i][c] == '.')
		{
			int fx = Find(id(i, c));
			int fy = Find(r * c + 1);
			if (fx != fy)
				f[fy] = fx;
			vis[i][c] = 1;
		}
	}
	for (int i = 1; i <= c; ++i)
	{
		if (s[1][i] == '.')
		{
			int fx = Find(id(1, i));
			int fy = Find(r * c + 1);
			if (fx != fy)
				f[fy] = fx;
			vis[1][i] = 1;
		}
		if (s[r][i] == '.')
		{
			int fx = Find(id(r, i));
			int fy = Find(r * c + 1);
			if (fx != fy)
				f[fy] = fx;
			vis[r][i] = 1;
		}
	}
	int tmp = 0;
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (!vis[i][j] && s[i][j] == '.')
				ans += bfs(i, j);
			if (s[i][j] == '/' && s[i][j + 1] == '\\' && s[i + 1][j] == '\\' && s[i + 1][j + 1] == '/')
				ans++;
		}
	}
	printf("%d\n", ans);
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
