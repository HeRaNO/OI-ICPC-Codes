#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 110

int n, m, k, s, t, x, u, v, w;
int culture[MAXN];
int against_num[MAXN];
int against[MAXN][MAXN];
int road[MAXN][MAXN], road_dis[MAXN][MAXN];
int road_num[MAXN];
int dis[MAXN];
int q[MAXN];
bool inq[MAXN], can_arrive[MAXN], arrive[MAXN][MAXN];
//arrive:DI YI WEI SHI GUO JIA,DI ER WEI SHI WEN HUA

bool cmp(int a, int b)
{
	for (int i = 1; i <= against_num[culture[b]]; i++)
		if (arrive[a][against[culture[b]][i]])
			return false;
	return true;
}

int spfa()
{
	int head = 0, tail = 1, j;
	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
	q[tail] = s;
	arrive[s][culture[s]] = true;
	inq[s] = true;
	dis[s] = 0;
	while (head != tail)
	{
		head = (head % n) + 1;
		inq[q[head]] = false;
		for (int i = 1; i <= road_num[q[head]]; i++)
		{
			if (cmp(q[head], road[q[head]][i]))
			{
				if (can_arrive[culture[road[q[head]][i]]])
				{
					if (dis[q[head]] + road_dis[q[head]][i] < dis[road[q[head]][i]])
					{
						dis[road[q[head]][i]] = dis[q[head]] + road_dis[q[head]][i];
						for (j = 1; j <= k; j++)
							arrive[road[q[head]][i]][j] = arrive[q[head]][j];
						arrive[road[q[head]][i]][culture[road[q[head]][i]]] = true;
						if (!inq[road[q[head]][i]])
						{
							inq[road[q[head]][i]] = true;
							tail = (tail % n) + 1;
							q[tail] = road[q[head]][i];
						}
					}
				}
			}
		}
	}
	if (dis[t] == INT_MAX) return -1;
	else return dis[t];
}

int main()
{
	scanf("%d %d %d %d %d", &n, &k, &m, &s, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &culture[i]);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
		{
			scanf("%d", &x);
			if (x == 1)
			{
				against_num[i]++;
				against[i][against_num[i]] = j;
			}
		}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		road_num[u] += 1;
		road[u][road_num[u]] = v;
		road_dis[u][road_num[u]] = w;
		road_num[v] += 1;
		road[v][road_num[v]] = u;
		road_dis[v][road_num[v]] = w;
	}
	memset(can_arrive, true, sizeof(can_arrive));
	memset(inq, false, sizeof(inq));
	memset(arrive, false, sizeof(arrive));
	for (int i = 1; i <= against_num[culture[t]]; i++)
		can_arrive[against[culture[t]][i]] = false;
	printf("%d\n", spfa());
	return 0;
}
