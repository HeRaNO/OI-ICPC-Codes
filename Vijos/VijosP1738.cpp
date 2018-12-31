#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXX 10
#define MAXY 10
#define MAXC 13
using namespace std;

int c, n, tmp;
int a[MAXX][MAXY], cnt[MAXC];
bool used[MAXX][MAXY];
int ans[MAXX][3];

void get_down(int x)
{
	for (int i = 0; i < 7; i++)
	{
		if (!a[x][i])
		{
			int j = i + 1;
			while (j < 7 && !a[x][j]) j++;
			if (j == 7) return ;
			else swap(a[x][i], a[x][j]);
		}
	}
	return ;
}

bool clear()
{
	bool flag = false;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 7; j++)
		{
			if (!a[i][j]) continue;
			if (i < 3 && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j])
				used[i][j] = used[i + 1][j] = used[i + 2][j] = true;
			if (j < 5 && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2])
				used[i][j] = used[i][j + 1] = used[i][j + 2] = true;
		}
	for (int i = 0; i < 5; i++)
		for (int j = 0; a[i][j] && j < 7; j++)
			if (used[i][j])
			{
				flag = true;
				cnt[a[i][j]]--;
				a[i][j] = used[i][j] = 0;
			}
	for (int i = 0; i < 5; i++) get_down(i);
	return flag;
}

int check()
{
	int minc = 0;
	for (int i = 1; i <= c; i++)
		if (cnt[i] && (!minc || minc > cnt[i]))
			minc = cnt[i];
	return minc;
}

void print()
{
	for (int i = 1; i <= n; i++)
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	exit(0);
}

void dfs(int dep)
{
	int mem[MAXX][MAXY], memc[MAXC];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 7; j++)
			mem[i][j] = a[i][j];
	for (int i = 1; i <= c; i++) memc[i] = cnt[i];
	for (int i = 0; i < 5; i++)
		for (int j = 0; a[i][j] && j < 7; j++)
			for (int k = 1; k >= -1; k -= 2)
				if (i + k >= 0 && i + k < 5)
				{
					if ((k == -1 && a[i - 1][j]) || a[i][j] == a[i + k][j]) continue;
					ans[dep][0] = i;
					ans[dep][1] = j;
					ans[dep][2] = k;
					swap(a[i][j], a[i + k][j]);
					get_down(i);
					get_down(i + k);
					while (clear());
					int tmp = check();
					if (dep == n)
					{
						if (!tmp) print();
					}
					else if (tmp > 2) dfs(dep + 1);
					for (int ii = 0; ii < 5; ii++)
						for (int jj = 0; jj < 7; jj++)
							a[ii][jj] = mem[ii][jj];
					for (int ii = 1; ii <= c; ii++) cnt[ii] = memc[ii];
				}
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	memset(used, false, sizeof(used));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j <= 7; j++)
		{
			scanf("%d", &tmp);
			if (!tmp) break;
			a[i][j] = tmp;
			c = mymax(c, tmp);
			cnt[tmp]++;
		}
	dfs(1);
	printf("-1\n");
	return 0;
}