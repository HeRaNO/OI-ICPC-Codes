#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 310
#define INF 1000000000
using namespace std;

int floyed[MAXN][MAXN];
int n, s;
int u, v, w;
int maxl, ecc = INT_MAX;
bool vis[MAXN][MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void pre_work()
{
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			floyed[i][j] = INF;
	for (int i = 0; i < MAXN; i++)
		floyed[i][i] = 0;
}

void Floyed_work()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				floyed[i][j] = mymin(floyed[i][j], floyed[i][k] + floyed[k][j]);
	return ;
}

int main()
{
	pre_work();
	scanf("%d %d", &n, &s);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		floyed[u][v] = floyed[v][u] = w;
	}
	Floyed_work();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			maxl = mymax(maxl, floyed[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (floyed[i][j] == maxl && !vis[i][j])
			{
				for (int k = 1; k <= n; k++)
					if (floyed[i][k] + floyed[k][j] == maxl)
					{
						for (int l = 1; l <= n; l++)
						{
							if (floyed[i][l] + floyed[l][j] == maxl && floyed[k][l] <= s)
								ecc = mymin(ecc, mymax(mymin(floyed[k][i], floyed[l][i]), mymin(floyed[j][k], floyed[j][l])));
						}
					}
			}
			vis[i][j] = vis[j][i] = true;
		}
	printf("%d\n", ecc);
	return 0;
}
