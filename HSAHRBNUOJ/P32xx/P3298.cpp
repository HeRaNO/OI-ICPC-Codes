#include <cstdio>
#include <climits>
#include <algorithm>
#define MOD 1000000000
using namespace std;

struct wosa
{
	int opt, v, c;
};

wosa a[510];
int n, C, v, c;
int down[4] = {1, 3, 2, 1}, up[4] = {1, 5, 5, 3};
char pos[20];
int dp[2][6][6][4][1010][3];
int ansv, ansc = INT_MAX, cnt;

bool cmp(wosa a, wosa b)
{
	return a.v < b.v;
}

inline void update(int a, int b, int c, int d, int e, int v, int cnt, int capv)
{
	if (dp[a][b][c][d][e][0] < v)
	{
		dp[a][b][c][d][e][0] = v;
		dp[a][b][c][d][e][1] = 0;
		dp[a][b][c][d][e][2] = capv;
	}
	if (dp[a][b][c][d][e][0] == v && dp[a][b][c][d][e][2] < capv)
	{
		dp[a][b][c][d][e][1] = 0;
		dp[a][b][c][d][e][2] = capv;
	}
	if (dp[a][b][c][d][e][0] == v && dp[a][b][c][d][e][2] == capv)
	{
		dp[a][b][c][d][e][1] += cnt;
		if (dp[a][b][c][d][e][1] > MOD) dp[a][b][c][d][e][1] = MOD;
	}
	return ;
}

void dpit(int p)
{
	for (int aa = up[0] - (a[p].opt == 0); ~aa; aa--)
		for (int b = up[1] - (a[p].opt == 1); ~b; b--)
			for (int c = up[2] - (a[p].opt == 2); ~c; c--)
				for (int d = up[3] - (a[p].opt == 3); ~d; d--)
					if (aa + b + c + d < 11)
					{
						for (int e = C - a[p].c; ~e; e--)
							if (dp[aa][b][c][d][e][1])
								update(aa + (a[p].opt == 0), b + (a[p].opt == 1), c + (a[p].opt == 2), d + (a[p].opt == 3), e + a[p].c, dp[aa][b][c][d][e][0] + a[p].v, dp[aa][b][c][d][e][1], a[p].v);
					}
}

inline void getans()
{
	for (int aa = down[0]; aa <= up[0]; aa++)
		for (int b = down[1]; b <= up[1]; b++)
			for (int c = down[2]; c <= up[2]; c++)
				for (int d = down[3]; d <= up[3]; d++)
					if (aa + b + c + d == 11)
						for (int e = 0; e <= C; e++)
							if (dp[aa][b][c][d][e][1])
							{
								int nowv = dp[aa][b][c][d][e][0] + dp[aa][b][c][d][e][2];
								int nowc = e;
								int nowcnt = dp[aa][b][c][d][e][1];
								if (nowv > ansv)
								{
									ansv = nowv;
									ansc = nowc;
									cnt = 0;
								}
								if (nowv == ansv && nowc < ansc)
								{
									ansc = nowc;
									cnt = 0;
								}
								if (nowv == ansv && nowc == ansc)
								{
									cnt += nowcnt;
									if (cnt > MOD) cnt = MOD;
								}
							}
	return ;
}

int main()
{
	//freopen("wosa.in","r",stdin);freopen("wosa.out","w",stdout);
	dp[0][0][0][0][0][1] = 1;
	dp[0][0][0][0][0][2] = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s %d %d", pos, &v, &c);
		if (pos[0] == 'G') a[i] = (wosa)
		{
			0, v, c
		};
		else if (pos[0] == 'D') a[i] = (wosa)
		{
			1, v, c
		};
		else if (pos[0] == 'M') a[i] = (wosa)
		{
			2, v, c
		};
		else a[i] = (wosa)
		{
			3, v, c
		};
	}
	scanf("%d", &C);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) dpit(i);
	getans();
	printf("%d %d %d\n", ansv, ansc, cnt);
	return 0;
}
