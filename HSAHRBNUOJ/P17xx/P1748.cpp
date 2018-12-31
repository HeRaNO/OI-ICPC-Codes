#include<iostream>
#include<cstdio>
using namespace std;

int a[201][201], f[201][201];
int n, m;

int main()
{
	cin >> m >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int maxl = -10;
			for (int k = 0; k <= j; k++)
			{
				f[i][j] = f[i - 1][k] + a[i][j - k];
				if (f[i][j] > maxl)
					maxl = f[i][j];
			}
			f[i][j] = maxl;
		}
	cout << f[n][m] << endl;
	return 0;
}
