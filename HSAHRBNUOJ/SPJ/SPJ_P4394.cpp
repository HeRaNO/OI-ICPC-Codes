#include <bits/stdc++.h>
#define MAXN 1001
#define MAXK 25
using namespace std;

int n, k, f, uf, x;
int sum[MAXN];
int m[MAXN][MAXK];
bool used[MAXN];
string choose;

int main(int argc, char const *argv[])
{
	ifstream fin(argv[1]), fout(argv[2]), fuser(argv[3]);
	fin >> k >> n;
	for (int i = 1; i <= k; i++) fin >> sum[i];
	for (int i = 1; i <= n; i++)
	{
		fin >> x;
		for (int j = 1; j <= x; j++) fin >> m[i][++m[i][0]];
	}
	fout >> f;
	getline(fuser, choose);
	if (f ^ (choose[0] - '0'))
	{
		puts("Solution Wrong!");
		return 1;
	}
	if (!f) return 0;
	for (int i = 1; i <= n; i++)
	{
		getline(fuser, choose);
		int len = choose.length(), x = 0, cnt = 0;
		for (int j = 0; j < len; j++)
		{
			if (choose[j] < '0' || choose[j] > '9')
			{
				if (used[x] || !x)
				{
					puts("The problem is used before.");
					printf("%d %d\n", x, j);
					return 1;
				}
				bool flag = false;
				for (int k = 1; k <= m[x][0] && !flag; k++)
					if (m[x][k] == i) flag = true;
				if (!flag)
				{
					puts("The problem is not in this category.");
					return 1;
				}
				used[x] = true;
				x = 0;
				cnt++;
			}
			else x = (x << 3) + (x << 1) + choose[j] - '0';
		}
		if (x)
		{
			if (used[x] || !x)
			{
				puts("The problem is used before.p");
				printf("%d\n", x);
				return 1;
			}
			bool flag = false;
			for (int k = 1; k <= m[x][0] && !flag; k++)
				if (m[x][k] == i) flag = true;
			if (!flag)
			{
				puts("The problem is not in this category.");
				return 1;
			}
			used[x] = true;
			x = 0;
			cnt++;
		}
		if (cnt != sum[i])
		{
			puts("More or less category.");
			printf("%d %d\n", cnt, sum[i]);
			return 1;
		}
	}
	//if (fuser>>choose) return 1;
	return 0;
}
