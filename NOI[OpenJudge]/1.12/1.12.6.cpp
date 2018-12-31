//Code By HeRaNO
#include <cstdio>
#define MOD 20123
using namespace std;

int n, m, x;
int i, j, k;
int score[10001][101];
int road[10001][101];
int can_room[10005];
int ans, cnt;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 0; j < m; j++)
		{
			scanf("%d %d", &road[i][j], &score[i][j]);
			can_room[i] += road[i][j];
		}
	scanf("%d", &x);
	for (i = 1; i <= n; i++)
	{
		ans = (ans + score[i][x]) % MOD;
		if (i == n) break;
		cnt = score[i][x] % can_room[i];
		if (!cnt) cnt = can_room[i];
		k = x;
		if (road[i][k]) cnt--;
		while (cnt > 0)
		{
			k++;
			k %= m;
			if (road[i][k]) cnt--;
		}
		x = k;
	}
	ans %= MOD;
	printf("%d", ans);
	return 0;
}
