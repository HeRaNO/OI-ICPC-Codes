#include<iostream>
#include<cstdio>
using namespace std;
int v[51] = {0}, m[51] = {0}, w[51] = {0};
int f[501][501] = {0};
int i, j, k, V, M, n, maxl = -99, r, a;
int max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	//freopen("NASA.in","r",stdin);
	//freopen("NASA.out","w",stdout);
	cin >> V >> M;
	cin >> n;
	for (j = 0; j <= V; j++)
		for (k = 0; k <= M; k++)
			f[j][k] = 0;
	for (i = 1; i <= n; i++)
		cin >> v[i] >> m[i] >> w[i];
	for (i = 1; i <= n; i++)
		for (j = V; j >= v[i]; j--)
			for (k = M; k >= m[i]; k--)
			{
				f[j][k] = max(f[j][k], f[j - v[i]][k - m[i]] + w[i]);
				if (f[j][k] > maxl)
					maxl = f[j][k];
			}
	cout << maxl;
	return 0;
}