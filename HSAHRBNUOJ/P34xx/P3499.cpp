#include <cstdio>
#include <cstring>
#define MAXN 2010
#define MAXM 2010
using namespace std;

int n, m, ans;
char g[MAXN][MAXM];
int rank[MAXN], now[MAXN];
bool flag;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= m; i++)
	{
		now[1] = 0;
		flag = false;
		for (int j = 1; j < n; j++)
		{
			if (rank[j] < rank[j + 1]) now[j + 1] = now[j] + 1;
			else
			{
				if (g[j][i] > g[j + 1][i])
				{
					ans++;
					flag = true;
					break;
				}
				else if (g[j][i] == g[j + 1][i]) now[j + 1] = now[j];
				else now[j + 1] = now[j] + 1;
			}
		}
		if (!flag) for (int j = 1; j <= n; j++) rank[j] = now[j];
	}
	printf("%d\n", ans);
	return 0;
}
