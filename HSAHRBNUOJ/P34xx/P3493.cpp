#include <cstdio>
#define MAXN 55
using namespace std;

char g[MAXN][MAXN];
int n, ans[MAXN * 2][MAXN * 2], t, tx, ty;
bool vis[MAXN][MAXN];

bool judge(int x, int y)
{
	if (x >= 1 && x <= n && y >= 1 && y <= n) return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int dx = -n + 1; dx <= n - 1; dx++)
		for (int dy = -n + 1; dy <= n - 1; dy++)
		{
			t = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (g[i][j] == 'o')
					{
						tx = i + dx;
						ty = j + dy;
						if (judge(tx, ty))
							if (g[tx][ty] == '.' && !t) t = 1;
					}
			ans[dx + n][dy + n] = t;
			if (!t)
			{
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= n; j++)
						if (g[i][j] == 'o')
						{
							tx = i + dx;
							ty = j + dy;
							if (judge(tx, ty)) vis[tx][ty] = true;
						}
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j] == 'x' && !vis[i][j])
			{
				puts("NO");
				return 0;
			}
	puts("YES");
	for (int i = 1; i < 2 * n; i++)
	{
		for (int j = 1; j < 2 * n; j++)
		{
			if (i == n && j == n)
			{
				putchar('o');
				continue;
			}
			if (ans[i][j]) putchar('.');
			else putchar('x');
		}
		putchar('\n');
	}
	return 0;
}
