#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXX 2010
#define ZERO 1000
using namespace std;

const int d[4][2] =
{
	{0, 1}, {0, -1},
	{1, 0}, {-1, 0}
};

int n, R = 1, mxx, mxy, ans;
bool mp[MAXX][MAXX], vis[MAXX][MAXX], vist[MAXX][MAXX];
queue <pair<int, int> > q;
pair <int, int> sp;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void BFS()
{
	q.push(make_pair(mxx, mxy));
	q.push(make_pair(0, 0));
	q.push(make_pair(ZERO, mxy));
	vis[0][0] = true;
	if (!mp[mxx][mxy]) vis[mxx][mxy] = true;
	if (!mp[ZERO][mxy]) vis[ZERO][mxy] = true;
	while (!q.empty())
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = u.first + d[i][0], ty = u.second + d[i][1];
			if (tx >= 0 && tx <= mxx && ty >= 0 && ty <= mxy)
			{
				if (!mp[tx][ty] && !vis[tx][ty])
				{
					vis[tx][ty] = true;
					q.push(make_pair(tx, ty));
				}
			}
		}
	}
	for (int i = 0; i <= mxx; i++)
		for (int j = 0; j <= mxy; j++)
			vis[i][j] = !vis[i][j];
	for (int i = 0; i <= mxx; i++)
		for (int j = 0; j <= mxy; j++)
		{
			if (vis[i + 1][j] && vis[i - 1][j] && vis[i][j + 1] && vis[i][j - 1])
			{
				if (vis[i + 1][j - 1] && vis[i - 1][j + 1] && !vis[i + 1][j + 1] && !vis[i - 1][j - 1])
					vis[i][j] = false;
				if (!vis[i + 1][j - 1] && !vis[i - 1][j + 1] && vis[i + 1][j + 1] && vis[i - 1][j - 1])
					vis[i][j] = false;
			}
			else
			{
				if (vis[i][j] && !vis[i - 1][j] && !vis[i + 1][j]) vis[i][j] = false;
				if (vis[i][j] && !vis[i][j - 1] && !vis[i][j + 1]) vis[i][j] = false;
				else if (!vis[i][j] && vis[i - 1][j] && vis[i + 1][j]) vis[i][j] = true;
				else if (!vis[i][j] && vis[i][j - 1] && vis[i][j + 1]) vis[i][j] = true;
			}
		}
	return ;
}

inline void BFS(int x, int y)
{
	sp = make_pair(0, 0);
	q.push(make_pair(x, y));
	vist[x][y] = true;
	while (!q.empty())
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = u.first + d[i][0], ty = u.second + d[i][1];
			if (tx >= 0 && tx <= mxx && ty >= 0 && ty <= mxy)
			{
				if (vis[tx][ty] && !vist[tx][ty])
				{
					vist[tx][ty] = true;
					sp = sp < make_pair(tx, ty) ? make_pair(tx, ty) : sp;
					q.push(make_pair(tx, ty));
				}
			}
		}
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	int x0, y0, x1, y1;
	read(n);
	if (n < 4)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		read(x0);
		read(y0);
		read(x1);
		read(y1);
		x0 += ZERO;
		y0 += ZERO;
		x1 += ZERO;
		y1 += ZERO;
		mxx = mymax(mxx, mymax(x1, x0));
		mxy = mymax(mxy, mymax(y1, y0));
		if (x0 == x1)
		{
			if (y0 > y1) swap(y0, y1);
			for (int j = y0; j <= y1; j++) mp[x0][j] = 1;
		}
		if (y0 == y1)
		{
			if (x0 > x1) swap(x0, x1);
			for (int j = x0; j <= x1; j++) mp[j][y0] = 1;
		}
	}
	BFS();
	for (int i = 0; i <= mxx; i++)
		for (int j = 0; j <= mxy; j++)
			if (vis[i][j] && !vist[i][j])
			{
				BFS(i, j);
				if (sp.first != i && sp.second != j) ans++;
			}
	printf("%d\n", ans);
	return 0;
}