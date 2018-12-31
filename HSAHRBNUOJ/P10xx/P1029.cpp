#include <iostream>
#include <cstdio>
using namespace std;
int f[30][30005], i, j, k, n, m, l, v[30], w[30];
int main()
{
	cin >> n >> m;
	for (i = 1; i <= m; i++)
		cin >> v[i] >> w[i];
	for (i = 1; i <= m; i++)
		for (j = 0; j <= n; j++)
			if (j > v[i])
				f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + v[i] * w[i]);
			else f[i][j] = f[i - 1][j];
	cout << f[m][n] << endl;
	return 0;
}
