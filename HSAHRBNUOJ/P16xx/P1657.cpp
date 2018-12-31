#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 17
using namespace std;

struct point
{
	short int x, y;
};

struct AStar
{
	short int ax, ay, bx, by, cx, cy, g, h;
	bool operator < (const AStar &a) const
	{
		return h + g > a.h + a.g;
	}
};

short int d[5][2] =
{
	{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
char g[MAXN][MAXN];
short int w, h, n;
short int stax, stay, stbx, stby, stcx, stcy;
short int edax, eday, edbx, edby, edcx, edcy;
short int dis[3][MAXN][MAXN];
short int f[MAXN][MAXN][MAXN][MAXN][MAXN][MAXN];
bool have[3];
queue <point> q;
priority_queue <AStar> q1;

bool check(short int x, short int y)
{
	return g[x][y] != '#' && x >= 0 && y >= 0 && x < h && y < w;
}

short int mymax(short int a, short int b)
{
	return a > b ? a : b;
}

short int fun_h(short int ax, short int ay, short int bx, short int by, short int cx, short int cy)
{
	return mymax(dis[0][ax][ay], mymax(dis[1][bx][by], dis[2][cx][cy]));
}

inline void pre_work()
{
	stax = stay = stbx = stby = stcx = stcy = 0;
	edax = eday = edbx = edby = edcx = edcy = 0;
	memset(have, 0, sizeof(have));
	memset(g, 0, sizeof(g));
	memset(f, 127, sizeof(f));
	memset(dis, 127, sizeof(dis));
	return ;
}

void pre_h(int opt)
{
	short int stx, sty, tx, ty;
	if (!opt) stx = edax, sty = eday;
	else if (opt == 1) stx = edbx, sty = edby;
	else stx = edcx, sty = edcy;
	q.push((point)
	{
		stx, sty
	});
	dis[opt][stx][sty] = 0;
	while (!q.empty())
	{
		point now = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++)
		{
			tx = now.x + d[i][0];
			ty = now.y + d[i][1];
			if (check(tx, ty))
			{
				if (dis[opt][tx][ty] > dis[opt][now.x][now.y] + 1)
				{
					dis[opt][tx][ty] = dis[opt][now.x][now.y] + 1;
					q.push((point)
					{
						tx, ty
					});
				}
			}
		}
	}
}

short int A_Star()
{
	q1.push((AStar)
	{
		stax, stay, stbx, stby, stcx, stcy, 0, fun_h(stax, stay, stbx, stby, stcx, stcy)
	});
	f[stax][stay][stbx][stby][stcx][stcy] = fun_h(stax, stay, stbx, stby, stcx, stcy);
	short int tax, tay, tbx, tby, tcx, tcy, t;
	while (!q1.empty())
	{
		tax = tay = tbx = tby = tcx = tcy = 0;
		AStar now = q1.top();
		q1.pop();
		if (now.h + now.g > f[now.ax][now.ay][now.bx][now.by][now.cx][now.cy]) continue;
		if (now.ax == edax && now.ay == eday && now.bx == edbx && now.by == edby && now.cx == edcx && now.cy == edcy) return now.g;
		for (int i = 0; i <= 4; i++)
		{
			if (have[0])
			{
				tax = now.ax + d[i][0];
				tay = now.ay + d[i][1];
				if (!check(tax, tay)) continue;
			}
			for (int j = 0; j <= 4; j++)
			{
				if (have[1])
				{
					tbx = now.bx + d[j][0];
					tby = now.by + d[j][1];
					if (!check(tbx, tby)) continue;
					if (tax == tbx && tay == tby) continue;
					if (tax == now.bx && tbx == now.ax && tby == tay) continue;
					if (tay == now.by && tby == now.ay && tbx == tax) continue;
				}
				for (int k = 0; k <= 4; k++)
				{
					if (have[2])
					{
						tcx = now.cx + d[k][0];
						tcy = now.cy + d[k][1];
						if (!check(tcx, tcy)) continue;
						if ((tcx == tbx && tcy == tby) || (tcx == tax && tcy == tay)) continue;
						if (tax == now.cx && tcx == now.ax && tcy == tay) continue;
						if (tay == now.cy && tcy == now.ay && tcx == tax) continue;
						if (tcx == now.bx && tbx == now.cx && tby == tcy) continue;
						if (tcy == now.by && tby == now.cy && tbx == tcx) continue;
					}
					t = fun_h(tax, tay, tbx, tby, tcx, tcy);
					if (f[tax][tay][tbx][tby][tcx][tcy] > now.g + 1 + t)
					{
						f[tax][tay][tbx][tby][tcx][tcy] = now.g + 1 + t;
						q1.push((AStar)
						{
							tax, tay, tbx, tby, tcx, tcy, now.g + 1, t
						});
					}
				}
			}
		}
	}
}

int main()
{
	while (scanf("%d %d %d", &w, &h, &n) != EOF && w && h && n)
	{
		pre_work();
		gets(g[0]);
		for (int i = 0; i < h; i++) gets(g[i]);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				if (g[i][j] == 'A') edax = i, eday = j, have[0] = true;
				else if (g[i][j] == 'B') edbx = i, edby = j, have[1] = true;
				else if (g[i][j] == 'C') edcx = i, edcy = j, have[2] = true;
				else if (g[i][j] == 'a') stax = i, stay = j;
				else if (g[i][j] == 'b') stbx = i, stby = j;
				else if (g[i][j] == 'c') stcx = i, stcy = j;
			}
		for (int i = 0; i < 3; i++)
		{
			if (have[i]) pre_h(i);
			else memset(dis[i], 0, sizeof(dis[i]));
		}
		printf("%d\n", A_Star());
	}
	return 0;
}
