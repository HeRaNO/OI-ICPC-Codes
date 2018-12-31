#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;

int V, ceng, bestans = INT_MAX;
int i, j;
int minv[21], mins[21];

void dfs(int dep, int r, int h, int s, int v)
{
	if (dep == 0)
	{
		if (v == V && s < bestans)
			bestans = s;
		return;
	}
	if (minv[dep - 1] + v > V || s + mins[dep - 1] > bestans || 2 * (V - v) / r + s > bestans) return;
	int a, b, tmp;
	for (a = r - 1; a >= dep; a--)
	{
		if (dep == ceng) s = a * a;
		tmp = (V - v - minv[dep - 1]) / (a * a) < h - 1 ? (V - v - minv[dep - 1]) / (a * a) : h - 1;
		for (b = tmp; b >= dep; b--)
			dfs(dep - 1, a, b, s + 2 * a * b, v + a * a * b);
	}
}

int main()
{
	cin >> V >> ceng;
	minv[0] = 0;
	mins[0] = 1;
	for (i = 1; i <= ceng + 1; i++)
	{
		minv[i] = minv[i - 1] + i * i * i;
		mins[i] = mins[i - 1] + 2 * i * i;
	}
	dfs(ceng, sqrt(V), V, 0, 0);
	if (bestans == INT_MAX) cout << 0;
	else cout << bestans;
	//system("pause");
	return 0;
}