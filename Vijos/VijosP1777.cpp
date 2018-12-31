#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
const int L = 501;
const int INF = INT_MAX;
int n, m;
int map[L][L];
int F[L], LEFT[L], RIGHT[L]; //main
struct zk
{
	int x, y;
};
queue<zk> q;
bool used[L][L];//bfs
bool LEFTused[L][L], RIGHTused[L][L]; //dfs
void read()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
		F[i] = INF;
	F[1] = 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	return;
}
bool bfs()
{
	while (!q.empty())  q.pop();
	zk temp;
	temp.y = 1;
	int a, b, i;
	for (i = 1; i <= m; i++)
	{
		temp.x = i;
		q.push(temp);
		used[1][i] = 1;
	}
	while (!q.empty())
	{
		temp = q.front();
		a = temp.y;
		b = temp.x;
		if (a > 1 && !used[a - 1][b] && map[a][b] > map[a - 1][b])
		{
			temp.y = a - 1;
			temp.x = b;
			q.push(temp);
			used[a - 1][b] = 1;
		}
		if (a < n && !used[a + 1][b] && map[a][b] > map[a + 1][b])
		{
			temp.y = a + 1;
			temp.x = b;
			q.push(temp);
			used[a + 1][b] = 1;
		}
		if (b > 1 && !used[a][b - 1] && map[a][b] > map[a][b - 1])
		{
			temp.y = a;
			temp.x = b - 1;
			q.push(temp);
			used[a][b - 1] = 1;
		}
		if (b < m && !used[a][b + 1] && map[a][b] > map[a][b + 1])
		{
			temp.y = a;
			temp.x = b + 1;
			q.push(temp);
			used[a][b + 1] = 1;
		}
		q.pop();
	}
	for (i = 1; i <= m; i++)
		if (!used[n][i])
			return 0;
	return 1;
}
void dfs1(int num, int x, int y, int front)
{
	if (LEFTused[x][y] == 1) return;
	LEFTused[x][y] = 1;
	if (x == 1) LEFT[y] = num;
	if (x - 1 >= 1 && front != 2 && map[x - 1][y] > map[x][y])  dfs1(num, x - 1, y, 1);
	if (x + 1 <= n && front != 1 && map[x + 1][y] > map[x][y])  dfs1(num, x + 1, y, 2);
	if (y - 1 >= 1 && front != 4 && map[x][y - 1] > map[x][y])  dfs1(num, x, y - 1, 3);
	if (y + 1 <= m && front != 3 && map[x][y + 1] > map[x][y])  dfs1(num, x, y + 1, 4);
	return;
}
void dfs2(int num, int x, int y, int front)
{
	if (RIGHTused[x][y] == 1) return;
	RIGHTused[x][y] = 1;
	if (x == 1) RIGHT[y] = num;
	if (x - 1 >= 1 && front != 2 && map[x - 1][y] > map[x][y])  dfs2(num, x - 1, y, 1);
	if (x + 1 <= n && front != 1 && map[x + 1][y] > map[x][y])  dfs2(num, x + 1, y, 2);
	if (y - 1 >= 1 && front != 4 && map[x][y - 1] > map[x][y])  dfs2(num, x, y - 1, 3);
	if (y + 1 <= m && front != 3 && map[x][y + 1] > map[x][y])  dfs2(num, x, y + 1, 4);
	return;
}
void dp()
{
	int i, j;
	for (i = 2; i <= m; i++)
		for (j = 1; j <= m; j++)
		{
			if (LEFT[j] <= i && RIGHT[j] >= i)
				F[i] = min(F[i], F[LEFT[j] - 1] + 1);
			else if (LEFT[j] > i)
				break;
		}
	return;
}
void work()
{
	int i, ans = 0;
	if (!bfs())
	{
		for (i = 1; i <= m; i++)
			if (!used[n][i])
				ans++;
		printf("0\n%d", ans);
	}
	else
	{
		for (i = 1; i <= m; i++)
			dfs1(i, n, i, 0);
		for (i = m; i >= 1; i--)
			dfs2(i, n, i, 0);
		dp();
		printf("1\n%d", F[m]);
	}
	return;
}
int main()
{
	read();
	work();
	return 0;
}