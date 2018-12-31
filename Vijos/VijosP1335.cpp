#include <iostream>
#include <cstring>
#include <cstdio>
#define cle(a) memset(a,0,sizeof(a))
using namespace std;

int main()
{
	int row[10][10], col[10][10], sq[10][10];
	int t, a;
	cin >> t;
	while (t--)
	{
		cle(row), cle(col);
		cle(sq);
		for (int  i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				cin >> a;
				row[i][a] = 1;
				col[j][a] = 1;
				int x = (i - 1) / 3 * 3 + (j - 1) / 3;
				sq[x][a] = 1;
			}
		}
		int mark = 0;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (col[j][i] == 0 || row[i][j] == 0 || !sq[i - 1][j])
				{
					mark = 1;
					break;
				}
			}
			if (mark)break;
		}
		if (mark)puts("Wrong");
		else puts("Right");
	}
	return 0;
}
