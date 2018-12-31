#include <iostream>
#include <cstdio>
#define MAXN 10001
using namespace std;

int m, n;
int i, j, k;
int v;
int c[MAXN], f[MAXN], w[MAXN];
int ans;

int mymax(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	cin >> m >> n;
	for (i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &c[i]);
	for (i = 1; i <= n; i++)
		for (v = c[i]; v <= m; v++)
		{
			f[v] = mymax(f[v], f[v - c[i]] + w[i]);
			ans = mymax(ans, f[v]);
		}
	cout << ans << endl;
	return 0;
}
