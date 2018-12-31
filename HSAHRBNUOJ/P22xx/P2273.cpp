#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#define MAXN 21
#define MAXM 256
#define MAXL 23340
using namespace std;

char in[MAXL];
int graph[MAXM][MAXN][500][3];
int ans[MAXM][MAXN];
bool vis[MAXM][MAXN], workout[MAXM][MAXN];
int n, m;

int dfs(int x, int y)
{
	if (vis[x][y] && !workout[x][y])
	{
		for (int ii = 1; ii <= n; ii++)
		{
			for (int jj = 1; jj < m; jj++)
				printf("ERROR ");
			printf("ERROR\n");
		}
		exit(0);
	}
	if (workout[x][y]) return ans[x][y];
	vis[x][y] = true;
	int get = 0;
	for (int i = 1; i <= graph[x][y][0][0]; i++)
		get += dfs(graph[x][y][i][0], graph[x][y][i][1]) * graph[x][y][i][2];
	workout[x][y] = true;
	ans[x][y] += get;
	return ans[x][y];
}

int main()
{
	memset(vis, false, sizeof(vis));
	memset(workout, false, sizeof(workout));
	scanf("%d %d", &n, &m);
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%s", in);
			bool all_num = true;
			int len = strlen(in);
			for (int k = 0; k < len; k++)
				if (in[k] >= 'A' && in[k] <= 'Z')
				{
					all_num = false;
					break;
				}
			if (all_num)
			{
				int num = 0;
				int pos = 0;
				int sign = 1;
				if (in[pos] == '-')
				{
					sign = -1;
					pos++;
				}
				else if (in[pos] == '+')
					pos++;
				else sign = 1;
				int tmp = 0;
				while (pos <= len)
				{
					if (pos == len || in[pos] == '+' || in[pos] == '-')
					{
						num += tmp * sign;
						if (in[pos] == '+') sign = 1;
						else sign = -1;
						pos++;
						tmp = 0;
					}
					else tmp = tmp * 10 + in[pos++] - '0';
				}
				ans[i][j] = num;
				workout[i][j] = true;
			}
			else
			{
				int pos = 0, sign = 1;
				if (in[pos] == '-')
				{
					sign = -1;
					pos++;
				}
				else if (in[pos] == '+') pos++;
				while (pos <= len)
				{
					if (in[pos] >= '0' && in[pos] <= '9')
					{
						int tmp = 0;
						while (true)
						{
							if (pos == len || in[pos] == '+' || in[pos] == '-')
							{
								ans[i][j] += tmp * sign;
								if (in[pos] == '+') sign = 1;
								else sign = -1;
								pos++;
								break;
							}
							tmp = tmp * 10 + in[pos++] - '0';
						}
					}
					else
					{
						graph[i][j][0][0]++;
						graph[i][j][graph[i][j][0][0]][1] = in[pos] - 'A' + 1;
						pos++;
						int row = 0;
						while (true)
						{
							if (pos == len || in[pos] == '+' || in[pos] == '-')
							{
								graph[i][j][graph[i][j][0][0]][0] = row;
								graph[i][j][graph[i][j][0][0]][2] = sign;
								if (in[pos] == '+') sign = 1;
								else sign = -1;
								pos++;
								break;
							}
							row = row * 10 + in[pos++] - '0';
						}
					}
				}
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!workout[i][j])
				dfs(i, j);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
			printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][m]);
	}
	return 0;
}
