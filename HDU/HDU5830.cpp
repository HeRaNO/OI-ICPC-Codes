#pragma GCC optimize("O2")
#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 3010
#define MOD 998244353LL
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
int head[MAXN], ecnt;
int n, hn, T, R, u, v;
int cnt[MAXN][MAXN >> 1], son[MAXN][MAXN >> 1], vis[MAXN];
long long ans[MAXN], _2pow[MAXN];
int q[MAXN][2], front, tail;

inline void add(int u, int v)
{
	e[ecnt] = (link)
	{
		v, head[u]
	};
	head[u] = ecnt++;
	e[ecnt] = (link)
	{
		u, head[v]
	};
	head[v] = ecnt++;
}

inline void DFS1(int x, int father)
{
	for (int i = 1; i <= hn; i++) cnt[x][i] = 0;
	cnt[x][0] = 1;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			DFS1(e[i].to, x);
			for (int j = 1; j <= hn; j++) cnt[x][j] += cnt[e[i].to][j - 1];
		}
	return ;
}

inline void DFS2(int x, int father)
{
	int t;
	for (int i = 0; i <= hn; i++) son[x][i] = cnt[x][i];
	for (int dis = 1; dis <= hn; dis++)
	{
		t = son[father][dis - 1];
		if (dis > 1 && father) t -= cnt[x][dis - 2];
		son[x][dis] += t;
	}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) DFS2(e[i].to, x);
	return ;
}

inline void BFS(int x)
{
	front = 1;
	tail = 0;
	q[++tail][0] = x;
	q[tail][1] = 0;
	vis[x] = ++R;
	while (front <= tail)
	{
		int a = q[front][0], b = q[front++][1];
		if (b > hn) continue;
		son[x][b]++;
		for (int i = head[a]; ~i; i = e[i].nxt)
			if (vis[e[i].to] != R)
			{
				vis[e[i].to] = R;
				q[++tail][0] = e[i].to;
				q[tail][1] = b + 1;
			}
	}
	return ;
}

inline void GetAns(int x, int father)
{
	int pre = 1;
	ans[0]++;
	for (int dis = 1; dis <= hn; dis++)
	{
		if (son[x][dis] < 2) break;
		ans[dis << 1] = (ans[dis << 1] + _2pow[pre] * (_2pow[son[x][dis]] - 1 - son[x][dis])) % MOD;
		if (son[x][dis] - cnt[x][dis] > 1)
		{
			int t = son[x][dis] - cnt[x][dis];
			ans[dis << 1] = (ans[dis << 1] - _2pow[pre] * (_2pow[t] - 1 - t)) % MOD;
			ans[dis << 1] = (ans[dis << 1] + MOD) % MOD;
		}
		for (int i = head[x]; ~i; i = e[i].nxt)
			if (e[i].to != father && cnt[e[i].to][dis - 1] > 1)
			{
				ans[dis << 1] = (ans[dis << 1] - _2pow[pre] * (_2pow[cnt[e[i].to][dis - 1]] - 1 - cnt[e[i].to][dis - 1])) % MOD;
				ans[dis << 1] = (ans[dis << 1] + MOD) % MOD;
			}
		pre += son[x][dis];
	}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			GetAns(e[i].to, x);
			pre = 0;
			for (int dis = 0; dis <= hn; dis++)
			{
				int down = cnt[e[i].to][dis], up = son[x][dis];
				if (dis) up -= cnt[e[i].to][dis - 1];
				if (!up || !down) break;
				ans[dis << 1 | 1] = (ans[dis << 1 | 1] + _2pow[pre] * (_2pow[up] - 1) % MOD * (_2pow[down] - 1)) % MOD;
				pre += up + down;
			}
		}
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

inline void write(int x)
{
	if (x < 10)
	{
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
	return ;
}

int main()
{
	_2pow[0] = 1;
	for (int i = 1; i <= 3000; i++) _2pow[i] = (_2pow[i - 1] << 1) % MOD;
	read(T);
	while (T--)
	{
		memset(ans, 0, sizeof ans);
		memset(head, -1, sizeof head);
		ecnt = 0;
		read(n);
		hn = n >> 1;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= hn; j++)
				son[i][j] = 0;
		for (int i = 1; i < n; i++)
		{
			read(u);
			read(v);
			add(u, v);
		}
		DFS1(1, 0); //DFS2(1,0);
		for (int i = 1; i <= n; i++) BFS(i);
		GetAns(1, 0);
		for (int i = 0; i < n; i++) write(ans[i]), putchar(' ');
		putchar('\n');
	}
	return 0;
}