#include <cstdio>
#define MAXN 50
#define MAXC 26
#define MAXW 21
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;

int n, cnt;
char in[MAXN][MAXW];
int g[MAXN][MAXW];
int vis[MAXN][MAXW], used[MAXC];
int range[MAXC][2];
bool color[MAXC], out[MAXC], finish;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int x, int y, int c)
{
	vis[x][y] = true;
	range[c][0] = mymin(range[c][0], y);
	range[c][1] = mymax(range[c][1], y);
	if (x >= 2 && g[x - 1][y] == c && !vis[x - 1][y]) dfs(x - 1, y, c);
	if (x + 1 <= n && g[x + 1][y] == c && !vis[x + 1][y]) dfs(x + 1, y, c);
	if (y >= 2 && g[x][y - 1] == c && !vis[x][y - 1]) dfs(x, y - 1, c);
	if (y + 1 <= 20 && g[x][y + 1] == c && !vis[x][y + 1]) dfs(x, y + 1, c);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", in[i]);
		for (int j = 0; j < 20; j++)
		{
			if (in[i][j] == '.') g[i][j + 1] = -1;
			else
			{
				g[i][j + 1] = in[i][j] - 'A';
				color[g[i][j + 1]] = true;
			}
		}
	}
	for (int i = 0; i < 26; i++) cnt += color[i], range[i][0] = INT_MAX, range[i][1] = INT_MIN;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 20; j++)
			if (g[i][j] != -1 && !vis[i][j])
				dfs(i, j, g[i][j]);
	while (cnt)
	{
		for (int i = 0; i < 26; i++)
		{
			if (color[i] && !out[i])
			{
				finish = false;
				for (int j = range[i][0]; j <= range[i][1] && !finish; j++)
					for (int k = n; k && g[k][j] != i && !finish; k--)
						if (g[k][j] != -1 && !out[g[k][j]])
							finish = true;
				if (!finish)
				{
					cnt--;
					out[i] = true;
					putchar(i + 'A');
					break;
				}
			}
		}
	}
	puts("");
	return 0;
}
