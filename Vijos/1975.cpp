#include <cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n, m;
int matrix[105][105];
int dir[] = {1, 0, -1};
char ch[105];

int main()
{
	cin >> n >> m;
	int i, j, k, t;
	memset(matrix, 0, sizeof(matrix));
	for (i = 1; i <= n; i++)
	{
		scanf("%s", ch + 1);
		for (j = 1; j <= m; j++)
		{
			if (ch[j] == '*')
				matrix[i][j] = -1;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (matrix[i][j] != -1)
			{
				for (k = 0; k < 3; k++)
				{
					for (t = 0; t < 3; t++)
					{
						if (k != 1 || t != 1)
						{
							if (matrix[i + dir[k]][j + dir[t]] == -1)
								matrix[i][j]++;
						}
					}
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (matrix[i][j] == -1)
				putchar('*');
			else
				putchar(matrix[i][j] + '0');
		}
		putchar('\n');
	}
	return 0;
}