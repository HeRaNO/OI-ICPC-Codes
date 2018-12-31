#include <cstdio>
#define MAXN 110
using namespace std;

int n;
char g[MAXN][MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", g[i]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			if (g[i][j] == '#')
			{
				if (g[i + 1][j - 1] == '#' && g[i + 1][j] == '#' && g[i + 1][j + 1] == '#' && g[i + 2][j] == '#')
					g[i][j] = g[i + 1][j - 1] = g[i + 1][j] = g[i + 1][j + 1] = g[i + 2][j] = '.';
				else
				{
					puts("NO");
					return 0;
				}
			}
	puts("YES");
	return 0;
}
