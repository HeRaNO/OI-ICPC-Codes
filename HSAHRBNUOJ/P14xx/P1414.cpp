#include <cstdio>
#define MAXN 305
using namespace std;

int a[MAXN][MAXN], s[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN], h[MAXN][MAXN];
int n, m, ans;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

inline int calc_s(int x, int y, int l, int r, int h)
{
	return s[x][r-1] + s[x-h][l] - s[x-h][r-1] - s[x][l];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	for (int i = 1; i <= n; i++)
	{
		l[i&1][0] = 0;
		for (int j = 1; j <= m; j++)
		{
			if (!a[i][j]) l[i&1][j] = j;
			else l[i&1][j] = l[i&1][j-1];
		}
		r[i&1][m+1] = m + 1;
		for (int j = m; j >= 1; j--)
		{
			if (!a[i][j]) r[i&1][j] = j;
			else r[i&1][j] = r[i&1][j+1];
		}
		for (int j = 1; j <= m; j++)
		{
			if (!a[i][j])
			{
				h[i&1][j] = 0;
				continue;
			}
			else if (!a[i-1][j])
			{
				h[i&1][j] = 1;
				ans = max(ans, calc_s(i, j, l[i&1][j], r[i&1][j], h[i&1][j]));
			}
			else
			{
				h[i&1][j] = h[(i-1)&1][j] + 1;
				l[i&1][j] = max(l[i&1][j], l[(i-1)&1][j]);
				r[i&1][j] = min(r[i&1][j], r[(i-1)&1][j]);
				ans = max(ans, calc_s(i, j, l[i&1][j], r[i&1][j], h[i&1][j]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}