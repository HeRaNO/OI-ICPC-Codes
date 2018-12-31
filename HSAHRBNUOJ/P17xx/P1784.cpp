#include <cstdio>
#include <cstring>
#define MAXN 510
using namespace std;

int result[MAXN];
bool state[MAXN];
int V, n1, n2, m;
int u, v;
int road[MAXN][MAXN];
int ans;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

bool Hungary(int x)
{
	for (int i = 1; i <= road[x][0]; i++)
	{
		if (state[road[x][i]]) continue;
		state[road[x][i]] = true;
		if (!result[road[x][i]] || Hungary(result[road[x][i]]))
		{
			result[road[x][i]] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	//freopen("tree.in","r",stdin);freopen("tree.out","w",stdout);
	scanf("%d %d %d %d", &V, &n1, &n2, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		road[u][++road[u][0]] = v;
	}
	for (int i = 1; i <= n1; i++)
	{
		memset(state, false, sizeof(state));
		if (Hungary(i)) ans++;
	}
	printf("%d\n", mymin(n1 + n2 - ans, V + 1));
	return 0;
}
