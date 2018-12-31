#include <queue>
#include <cstdio>
#include <cstring>
#define MAXR 25
#define MAXN 810
#define MAXM 4000
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int r, c, d, S, T, ans, CAS;
int head[MAXN], cnt;
char Ss[MAXR];
int dpt[MAXN], a[MAXR][MAXR];
queue <int> q;

inline void Prepare()
{
	cnt = 1;
	memset(head, 0, sizeof head);
	ans = c = 0;
	return ;
}

inline void add(int u, int v, int f)
{
	cnt++;
	e[cnt] = (link)
	{
		v, f, head[u]
	};
	head[u] = cnt;
	cnt++;
	e[cnt] = (link)
	{
		u, 0, head[v]
	};
	head[v] = cnt;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline bool less_than_d(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= d * d;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 1;
	q.push(S);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].flow && !~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[u] + 1;
				q.push(e[i].to);
			}
	}
	return dpt[T] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
	for (int i = head[x]; i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, mymin(e[i].flow, left));
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	if (left) dpt[x] = -1;
	return flow - left;
}

int main()
{
	scanf("%d", &CAS);
	for (int TT = 1; TT <= CAS; TT++)
	{
		Prepare();
		scanf("%d %d", &r, &d);
		for (int i = 1; i <= r; i++)
		{
			scanf("%s", Ss);
			if (!c) c = strlen(Ss);
			for (int j = 0; j < c; j++) a[i][j + 1] = Ss[j] - '0';
		}
		S = 0;
		T = 2 * r * c + 1;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
			{
				if (!a[i][j]) continue;
				add((i - 1)*c + j, (i - 1)*c + j + (T >> 1), a[i][j]);
				if (i <= d || j <= d || i + d > r || j + d > c) add((i - 1)*c + j + (T >> 1), T, ~(1 << 31));
				else
				{
					for (int k = 1; k <= r; k++)
						for (int s = 1; s <= c; s++)
						{
							if (i == k && j == s) continue;
							if (a[k][s] && less_than_d(i, j, k, s))
								add((i - 1)*c + j + (T >> 1), (k - 1)*c + s, ~(1 << 31));
						}
				}
			}
		for (int i = 1; i <= r; i++)
		{
			scanf("%s", Ss);
			for (int j = 0; j < c; j++) if (Ss[j] == 'L') ans++, add(S, (i - 1)*c + j + 1, 1);
		}
		while (BFS()) ans -= Dinic(S, ~(1 << 31));
		printf("Case #%d: ", TT);
		if (ans) printf("%d", ans);
		else printf("no");
		if (ans <= 1) printf(" lizard was left behind.\n");
		else printf(" lizards were left behind.\n");
	}
	return 0;
}