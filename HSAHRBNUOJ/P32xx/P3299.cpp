#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10
#define MAXS 30000000
using namespace std;

int ans[MAXS];
int n, T, s, top[MAXN], a[MAXN], order[MAXN];
int bit[MAXN], place[MAXN];
bool vis[MAXS];
int q[MAXS], head = 1, tail = 0;

bool cmp(int aa, int bb)
{
	return a[aa] < a[bb];
}

inline void BFS()
{
	memset(vis, false, sizeof vis);
	int status = 0;
	bit[0] = 1;
	for (int i = 1; i <= 7; i++)
	{
		bit[i] = bit[i - 1] * 10;
		status = status * 10 + i;
		q[++tail] = status;
		vis[status] = true;
	}
	while (head <= tail)
	{
		int r = q[head++];
		memset(top, 0, sizeof top);
		memset(place, 0, sizeof place);
		int cnt = 0, s = r;
		while (r)
		{
			place[++cnt] = r % 10;
			r /= 10;
		}
		reverse(place + 1, place + cnt + 1);
		for (int i = cnt; i; i--) top[place[i]] = i;
		for (int i = 1; i <= cnt; i++)
			if (i == top[place[i]])
			{
				int p = place[i];
				if (p != 1 && (i < top[p - 1] || !top[p - 1]))
				{
					int news = s - bit[cnt - i];
					if (!vis[news])
					{
						vis[news] = true;
						q[++tail] = news;
						ans[news] = ans[s] + 1;
					}
				}
				if (p != cnt && (i < top[p + 1] || !top[p + 1]))
				{
					int news = s + bit[cnt - i];
					if (!vis[news])
					{
						vis[news] = true;
						q[++tail] = news;
						ans[news] = ans[s] + 1;
					}
				}
			}
	}
	return ;
}

int main()
{
	//freopen("huakai.in","r",stdin);freopen("huakai.out","w",stdout);
	BFS();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			order[i] = i;
		}
		sort(order + 1, order + n + 1, cmp);
		s = 0;
		for (int i = 1; i <= n; i++) s = s * 10 + order[i];
		if (!vis[s]) puts("-1");
		else printf("%d\n", ans[s]);
	}
	return 0;
}
