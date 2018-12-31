#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 20
#define MAXM 110
using namespace std;

struct bugs
{
	int v;
	int bp, bm, fp, fm;
};

bugs a[MAXM];
int n, m, dis[1 << MAXN];
bool vis[1 << MAXN];
char b[MAXN], f[MAXN];
queue <int> q;

inline bool judge(int x, int i)
{
	if ((x | a[i].bp) != x) return false;
	if (x & a[i].bm) return false;
	return true;
}

inline int SPFA(int S, int T)
{
	memset(dis, 0x7f, sizeof dis);
	q.push(S);
	dis[S] = 0;
	vis[S] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 1; i <= m; i++)
			if (judge(u, i))
			{
				int v = (u ^ (u & a[i].fm)) | a[i].fp;
				if (dis[v] > dis[u] + a[i].v)
				{
					dis[v] = dis[u] + a[i].v;
					if (!vis[v])
					{
						vis[v] = true;
						q.push(v);
					}
				}
			}
	}
	if (dis[T] == 0x7f7f7f7f) return -1;
	else return dis[T];
}

int main()
{
	//freopen("bugs.in","r",stdin);freopen("bugs.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %s %s", &a[i].v, b, f);
		for (int j = 0; j < n; j++)
		{
			if (b[j] == '+') a[i].bp |= 1 << j;
			else if (b[j] == '-') a[i].bm |= 1 << j;
			if (f[j] == '+') a[i].fp |= 1 << j;
			else if (f[j] == '-') a[i].fm |= 1 << j;
		}
	}
	printf("%d\n", SPFA((1 << n) - 1, 0));
	return 0;
}