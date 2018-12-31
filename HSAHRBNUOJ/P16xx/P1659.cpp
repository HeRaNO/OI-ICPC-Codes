#include <map>
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#define MAXN 6
using namespace std;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int dice[24][6] =
{
	{1, 2, 3, 4, 5, 6}, {1, 4, 2, 5, 3, 6},
	{1, 5, 4, 3, 2, 6}, {1, 3, 5, 2, 4, 6},
	{2, 6, 3, 4, 1, 5}, {2, 4, 6, 1, 3, 5},
	{2, 1, 4, 3, 6, 5}, {2, 3, 1, 6, 4, 5},
	{3, 2, 6, 1, 5, 4}, {3, 1, 2, 5, 6, 4},
	{3, 5, 1, 6, 2, 4}, {3, 6, 5, 2, 1, 4},
	{4, 2, 1, 6, 5, 3}, {4, 6, 2, 5, 1, 3},
	{4, 5, 6, 1, 2, 3}, {4, 1, 5, 2, 6, 3},
	{5, 1, 3, 4, 6, 2}, {5, 4, 1, 6, 3, 2},
	{5, 6, 4, 3, 1, 2}, {5, 3, 6, 1, 4, 2},
	{6, 5, 3, 4, 2, 1}, {6, 4, 5, 2, 3, 1},
	{6, 2, 4, 3, 5, 1}, {6, 3, 2, 5, 4, 1}
};

int a[MAXN][MAXN], method[6], color[26];
int ans, n, cnt;
bool zero;
string s;

void dfs(int dep)
{
	if (dep == n)
	{
		int cc, res = 0;
		for (int j = 0; j < 6; j++)
		{
			cc = 0;
			memset(color, 0, sizeof(color));
			for (int i = 1; i <= n; i++)
			{
				color[a[i][dice[method[i]][j]]]++;
				cc = mymax(cc, color[a[i][dice[method[i]][j]]]);
			}
			res += n - cc;
		}
		ans = mymin(ans, res);
		if (!ans) zero = true;
		return ;
	}
	for (int i = 0; i < 24 && !zero; i++)
	{
		method[dep] = i;
		dfs(dep + 1);
	}
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		map <string, int> hash_table;
		cnt = 0;
		ans = INT_MAX;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 6; j++)
			{
				cin >> s;
				if (hash_table.find(s) == hash_table.end()) hash_table.insert(make_pair(s, ++cnt));
				a[i][j] = hash_table[s];
			}
		zero = false;
		if (n == 1)
		{
			printf("0\n");
			continue;
		}
		else dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
