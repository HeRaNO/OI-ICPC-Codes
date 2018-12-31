#include <cstdio>
#include <iostream>
using namespace std;
int v[51], m[51], w[51];
int f[501][501];
int i, j, k, V, M, n, maxl, r, a;
int mymax(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	//freopen("NASA.in","r",stdin);freopen("NASA.out","w",stdout);
	cin >> V >> M;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> v[i] >> m[i] >> w[i];
	for (i = 1; i <= n; i++)
		for (j = V; j >= v[i]; j--)
			for (k = M; k >= m[i]; k--)
			{
				f[j][k] = mymax(f[j][k], f[j - v[i]][k - m[i]] + w[i]);
				maxl = mymax(maxl, f[j][k]);
			}
	cout << maxl << endl;
	return 0;
}
