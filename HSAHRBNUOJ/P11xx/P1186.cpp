#include <cstdio>
#include <algorithm>
#define MAXN 305
#define MAXM 5005
#define MAXT 51
using namespace std;

struct link
{
	int x, y, z;
	bool operator < (const link &a)const
	{
		return z < a.z;
	}
};

link e[MAXM];
int n, m, T, v, k, p, x, y, z, w, f[MAXN], dp[MAXT], c[MAXT][MAXT];
bool ban[MAXT][MAXN][MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline int getf(int x)
{
	return x == f[x] ? x : f[x] = getf(f[x]);
}

inline int Kruskal(int x, int y)
{
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		bool flag = false;
		for (int j = x; j <= y; j++) if (ban[j][e[i].x][e[i].y]) flag = true;
		if (flag) continue;
		int fx = getf(e[i].x), fy = getf(e[i].y);
		if (fx != fy)
		{
			f[fy] = fx;
			++cnt;
			ans += e[i].z;
		}
		if (cnt == n - 1) return ans;
	}
	return 10000000;
}

inline int DP()
{
	for (int i = 1; i <= T; i++)
	{
		dp[i] = c[1][i] * v * i;
		for (int j = 1; j < i; j++)
			if (c[j + 1][i] != 100000000)
				dp[i] = mymin(dp[i], dp[j] + c[j + 1][i] * (i - j) * v);
		dp[i] += k;
	}
	return dp[T];
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(m);
	read(T);
	read(v);
	read(k);
	for (int i = 1; i <= m; i++)
	{
		read(e[i].x);
		read(e[i].y);
		read(e[i].z);
	}
	sort(e + 1, e + m + 1);
	read(p);
	for (int i = 1; i <= p; i++)
	{
		read(x);
		read(y);
		read(z);
		read(w);
		for (int j = z; j <= w; j++) ban[j][x][y] = ban[j][y][x] = true;
	}
	for (int i = 1; i <= T; i++)
		for (int j = i; j <= T; j++)
			c[i][j] = Kruskal(i, j);
	printf("%d\n", DP());
	return 0;
}