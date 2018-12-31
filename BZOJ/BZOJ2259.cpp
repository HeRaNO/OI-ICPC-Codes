#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 8000010
using namespace std;

int n;
int a[MAXN], dis[MAXN];
bool vis[MAXN];
queue <int> q;

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

inline void relax(int x, int k)
{
	while (x > 0 && x < n + n && !vis[x])
	{
		dis[x] = k;
		vis[x] = true;
		q.push(x);
		x += a[x] + 1;
	}
	return ;
}

int BFS()
{
	for (int i = n; i < n + n; i++) a[i] = n;
	vis[0] = true;
	relax(a[0] + 1, 0);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (u == n) break;
		relax(u - 1, dis[u] + 1);
		relax(u + 1, dis[u] + 1);
	}
	return dis[n];
}

int main()
{
	//freopen("lang.in","r",stdin);freopen("lang.out","w",stdout);
	read(n);
	for (int i = 0; i < n; i++) read(a[i]);
	if (a[0] >= n - 1)
	{
		printf("%d\n", a[0] - n + 1);
		return 0;
	}
	else printf("%d\n", BFS());
	return 0;
}