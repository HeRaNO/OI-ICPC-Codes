#include <cstdio>
#include <algorithm>
#define MAXN 110
using namespace std;

const int d[8][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1},
	{1, -1}, {-1, 1},
	{1, 1}, {-1, -1}
};
int n, m, T, x;
bool (*a)[MAXN], (*nxt)[MAXN];
char s[MAXN];

int getcell(int x, int y)
{
	int res = 0;
	for (int i = 0; i < 8; i++)
	{
		int tx = x + d[i][0], ty = y + d[i][1];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
			if (a[tx][ty]) res++;
	}
	return res;
}

int main()
{
	//freopen("life.in","r",stdin);freopen("life.out","w",stdout);
	a = new bool [MAXN][MAXN];
	nxt = new bool [MAXN][MAXN];
	scanf("%d %d %d", &m, &n, &T);
	T--;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < m; j++) a[i][j + 1] = (s[j] == '1');
	}
	while (T--)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				x = getcell(i, j);
				if (a[i][j])
				{
					if (x == 2 || x == 3) nxt[i][j] = true;
					else nxt[i][j] = false;
				}
				else
				{
					if (x == 3) nxt[i][j] = true;
					else nxt[i][j] = false;
				}
			}
		swap(a, nxt);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d", a[i][j]);
		puts("");
	}
	return 0;
}
