#include <cstdio>
#include <cstring>
#define MAXN 5
using namespace std;

int ax, ay;
int a[MAXN][MAXN];
bool used[17];

inline void print()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 3; j++) printf("%d ", a[i][j]);
		printf("%d\n", a[i][4]);
	}
	puts("");
	return ;
}

void dfs(int x, int y)
{
	if (y == 4)
	{
		if (a[x][y] == 1)
		{
			if (34 - (a[x][1] + a[x][2] + a[x][3]) != 1) return ;
			if (x == 2 && a[1][3] + a[1][4] + a[2][3] + a[2][4] != 34) return ;
			dfs(x + 1, 1);
		}
		else
		{
			a[x][y] = 34 - (a[x][1] + a[x][2] + a[x][3]);
			if (a[x][y] == 1) a[x][y] = 0;
			if (a[x][y] <= 0 || a[x][y] > 16) return ;
			if (used[a[x][y]]) return ;
			if (x == 2 && a[1][3] + a[1][4] + a[2][3] + a[2][4] != 34) return ;
			used[a[x][y]] = true;
			dfs(x + 1, 1);
			used[a[x][y]] = false;
		}
		return ;
	}
	if (x == 2 && y == 2)
	{
		if (a[x][y] == 1)
		{
			if (34 - (a[1][1] + a[1][2] + a[2][1]) != 1) return ;
			dfs(x, y + 1);
		}
		else
		{
			a[x][y] = 34 - (a[1][1] + a[1][2] + a[2][1]);
			if (a[x][y] == 1) a[x][y] = 0;
			if (a[x][y] <= 0 || a[x][y] > 16) return ;
			if (used[a[x][y]]) return ;
			used[a[x][y]] = true;
			dfs(x, y + 1);
			used[a[x][y]] = false;
		}
		return ;
	}
	if (x == 3 && y == 3)
	{
		if (a[x][y] == 1)
		{
			if (34 - (a[3][2] + a[2][3] + a[2][2]) != 1) return ;
			dfs(x, y + 1);
		}
		else
		{
			a[x][y] = 34 - (a[3][2] + a[2][3] + a[2][2]);
			if (a[x][y] == 1) a[x][y] = 0;
			if (a[x][y] <= 0 || a[x][y] > 16) return ;
			if (used[a[x][y]]) return ;
			used[a[x][y]] = true;
			dfs(x, y + 1);
			used[a[x][y]] = false;
		}
		return ;
	}
	if (x == 4)
	{
		int pos;
		bool no = false;
		if (ax != 4)
		{
			for (int i = 1; i <= 4; i++) a[4][i] = 34 - (a[1][i] + a[2][i] + a[3][i]);
			for (int i = 1; i <= 4; i++) if (a[x][i] <= 0 || a[x][i] > 16) return ;
			for (int i = 1; i <= 4; i++)
			{
				if (used[a[x][i]])
				{
					no = true;
					pos = i;
					break;
				}
				else used[a[x][i]] = true;
			}
			if (!no)
			{
				if (a[1][1] + a[1][4] + a[4][1] + a[4][4] != 34) no = true;
				if (a[3][1] + a[3][2] + a[4][1] + a[4][2] != 34) no = true;
				if (a[3][3] + a[3][4] + a[4][3] + a[4][4] != 34) no = true;
				if (a[1][1] + a[2][2] + a[3][3] + a[4][4] != 34) no = true;
				if (a[1][4] + a[2][3] + a[3][2] + a[4][1] != 34) no = true;
				if (!no) print();
				for (int i = 1; i <= 4; i++) used[a[x][i]] = false;
			}
			else for (int i = 1; i < pos; i++) used[a[x][i]] = false;
		}
		else
		{
			for (int i = 1; i <= 4; i++) if (i != ay) a[4][i] = 34 - (a[1][i] + a[2][i] + a[3][i]);
			for (int i = 1; i <= 4; i++) if (a[x][i] <= 0 || a[x][i] > 16) return ;
			if (a[1][ay] + a[2][ay] + a[3][ay] + a[4][ay] != 34) return ;
			for (int i = 1; i <= 4; i++)
			{
				if (i == ay) continue;
				if (used[a[x][i]])
				{
					no = true;
					pos = i;
					break;
				}
				else used[a[x][i]] = true;
			}
			if (!no)
			{
				if (a[1][1] + a[1][4] + a[4][1] + a[4][4] != 34) no = true;
				if (a[3][1] + a[3][2] + a[4][1] + a[4][2] != 34) no = true;
				if (a[3][3] + a[3][4] + a[4][3] + a[4][4] != 34) no = true;
				if (a[1][1] + a[2][2] + a[3][3] + a[4][4] != 34) no = true;
				if (a[1][4] + a[2][3] + a[3][2] + a[4][1] != 34) no = true;
				if (!no) print();
				for (int i = 1; i <= 4; i++) used[a[x][i]] = false;
				used[1] = true;
			}
			else for (int i = 1; i < pos; i++) used[a[x][i]] = false;
			used[1] = true;
		}
		return ;
	}
	if (x == ax && y == ay) dfs(x, y + 1);
	else
	{
		for (int i = 2; i <= 16; i++)
			if (!used[i])
			{
				used[i] = true;
				a[x][y] = i;
				dfs(x, y + 1);
				used[i] = false;
			}
	}
}

int main()
{
	//freopen("magic.in","r",stdin);freopen("magic.out","w",stdout);
	scanf("%d %d", &ax, &ay);
	a[ax][ay] = 1;
	used[1] = true;
	dfs(1, 1);
	return 0;
}
