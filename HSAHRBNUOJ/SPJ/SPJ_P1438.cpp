#include <bits/stdc++.h>
#define MAXN 40
using namespace std;

int g[2][MAXN][MAXN];
int std_step[MAXN][2], user_step[MAXN][2];
int n, m, k, c, f, x, std_stone, std_car;
int user_stone, user_car;

int main(int argc, char const *argv[])
{
	ifstream fin(argv[1]), fout(argv[2]), fuser(argv[3]);
	fin >> k >> m >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			fin >> x;
			if (x == 2) g[0][i][j] = g[1][i][j] = 1;
			if (x == 1) g[0][i][j] = g[1][i][j] = -1;
		}
	for (int i = 1; i <= k; i++)
		std_step[i][0] = std_step[i][1] = user_step[i][0] = user_step[i][1] = 1;
	while (fout >> c >> f)
	{
		std_step[c][f]++;
		if (g[0][std_step[c][0]][std_step[c][1]] == 1)
		{
			std_stone++;
			g[0][std_step[c][0]][std_step[c][1]] = 0;
		}
		else if (!~g[0][std_step[c][0]][std_step[c][1]])
		{
			puts("Std goes to the block!");
			return 1;
		}
		if (std_step[c][0] > n || std_step[c][1] > m)
		{
			puts("Std is out of the map!");
			return 1;
		}
	}
	for (int i = 1; i <= k; i++)
		if (std_step[i][0] == n && std_step[i][1] == m) std_car++;
	while (fuser >> c >> f)
	{
		user_step[c][f]++;
		if (g[1][user_step[c][0]][user_step[c][1]])
		{
			user_stone++;
			g[1][user_step[c][0]][user_step[c][1]] = 0;
		}
		else if (!~g[1][user_step[c][0]][user_step[c][1]])
		{
			puts("You go to the block!");
			return 1;
		}
		if (user_step[c][0] > n || user_step[c][1] > m)
		{
			puts("You're out of the map!");
			return 1;
		}
	}
	for (int i = 1; i <= k; i++)
		if (user_step[i][0] == n && user_step[i][1] == m) user_car++;
	if (std_stone != user_stone)
	{
		if (std_stone > user_stone) puts("You collected less stones than std!");
		else puts("Std collected less stones than you!");
		return 1;
	}
	if (std_car != user_car)
	{
		if (std_car > user_car) puts("You make less cars arrive at the terminal than std!");
		else puts("Std makes less cars arrive at the terminal than you!");
		return 1;
	}
	puts("The answer is accepted!");
	return 0;
}