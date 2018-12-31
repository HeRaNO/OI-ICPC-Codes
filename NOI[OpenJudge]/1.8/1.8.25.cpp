//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 25
#define MAXL 85
using namespace std;

int r, c, cnt, len, convert;
int table[MAXN][MAXN];
bool have[MAXN][MAXN];
char s[MAXL];
char in[MAXL * 5];

void dfs(int dep, int x, int y, int f)
{
	if (dep == len + 1) return ;
	table[x][y] = in[dep];
	have[x][y] = true;
	if (f == 0)
	{
		if (!have[x][y + 1]) dfs(dep + 1, x, y + 1, 0);
		else dfs(dep + 1, x + 1, y, 1);
	}
	if (f == 1)
	{
		if (!have[x + 1][y]) dfs(dep + 1, x + 1, y, 1);
		else dfs(dep + 1, x, y - 1, 2);
	}
	if (f == 2)
	{
		if (!have[x][y - 1]) dfs(dep + 1, x, y - 1, 2);
		else dfs(dep + 1, x - 1, y, 3);
	}
	if (f == 3)
	{
		if (!have[x - 1][y]) dfs(dep + 1, x - 1, y, 3);
		else dfs(dep + 1, x, y + 1, 0);
	}
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			table[i][j] = '0', have[i][j] = true;
	scanf("%d %d ", &r, &c);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			have[i][j] = false;
	gets(s);
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ') convert = 0;
		else convert = s[i] - 'A' + 1;
		for (int j = i * 5 + 1; j <= (i + 1) * 5; j++) in[j] = '0';
		cnt = (i + 1) * 5;
		while (convert)
		{
			in[cnt] = (convert % 2) + '0';
			convert /= 2;
			cnt--;
		}
	}
	len *= 5;
	dfs(1, 1, 1, 0);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			printf("%c", table[i][j]);
	printf("\n");
	return 0;
}
