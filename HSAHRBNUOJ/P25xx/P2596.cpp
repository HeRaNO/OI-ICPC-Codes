#include <cstdio>
#include <cstring>
#define MAXN 1001
#define MAXM 101
using namespace std;

int a[MAXN * MAXM][7];
int sum[MAXN];
int turn_best, turn_best_people;
int mode[7];
int n, m, mod, p;
int cnt;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n * m; i++)
		for (int j = 1; j <= 6; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= m; i++)
	{
		int j = turn_best_people;
		while (true)
		{
			mod = 0;
			memset(mode, 0, sizeof(mode));
			p = 0;
			for (int k = 1; k <= 6; k++) mode[a[cnt][k]]++;
			for (int k = 1; k <= 6; k++)
				if (mod < mode[k])
				{
					p = k;
					mod = mode[k];
				}
			if (p == 1 || p == 4) sum[j] = sum[j] + mod * 2;
			else sum[j] += mod;
			cnt++;
			j = (j + 1) % n;
			if (cnt == i * n) break;
		}
		for (int i = 0; i < n; i++)
			if (sum[i] > turn_best)
			{
				turn_best = sum[i];
				turn_best_people = i;
			}
	}
	printf("%d %d\n", turn_best_people + 1, turn_best);
	return 0;
}
