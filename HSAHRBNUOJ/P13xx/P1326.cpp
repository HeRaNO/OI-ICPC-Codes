#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;

bool road[MAXN][MAXN];
bool state[MAXN];
int result[MAXN], link[MAXN];
int n;
int ans;
int x, y;

bool Hungary(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (road[x][i] || state[i]) continue;
		state[i] = true;
		if (!result[i] || Hungary(result[i]))
		{
			result[i] = x;
			link[x] = i;
			return true;
		}
	}
	return false;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(road, false, sizeof(road));
		memset(result, 0, sizeof(result));
		memset(link, 0, sizeof(link));
		ans = 0;
		while (scanf("%d %d", &x, &y) != EOF && x && y)
			road[x][y] = true;
		for (int i = 1; i <= n; i++)
		{
			memset(state, false, sizeof(state));
			if (Hungary(i)) ans++;
		}
		if (ans != n)
		{
			printf("none\n");
			continue;
		}
		bool flag = false;
		for (int i = 1; i <= n; i++)
		{
			memset(state, false, sizeof(state));
			int t = link[i];
			road[i][t] = true;
			result[t] = 0;
			link[i] = 0;
			if (!Hungary(i))
			{
				printf("%d %d\n", i, t);
				result[t] = i;
				link[i] = t;
				flag = true;
			}
			road[i][t] = false;
		}
		if (!flag) printf("none\n");
	}
	return 0;
}
