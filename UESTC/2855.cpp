#include <queue>
#include <tuple>
#include <cstdio>
#include <vector>
#include <algorithm>

const int d[4][2] = {
	{-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
const int Z = 500;
const int N = Z * 2 + 2;
const int INF = 1'000'000'000;

int main()
{
	int dx, dy, n;
	scanf("%d %d %d", &dx, &dy, &n);
	dx += Z; dy += Z;
	std::vector<std::vector<int>> dis(N, std::vector<int>(N, 0));
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x += Z; y += Z;
		dis[x][y] = INF;
	}
	std::queue<std::pair<int, int>> q;
	q.push({Z, Z});
	while (!q.empty())
	{
		int x, y; std::tie(x, y) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + d[i][0], ny = y + d[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !dis[nx][ny])
			{
				dis[nx][ny] = dis[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	printf("%d\n", dis[dx][dy]);
	return 0;
}