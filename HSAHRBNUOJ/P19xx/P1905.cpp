#include <iostream>
#include <cstring>
using namespace std;

int l[1001][10001];
int n, m, a, b, t;
bool v[1001], huan[1001];

void dfs(int x)
{
	if (huan[t]) return;
	v[x] = true;
	if (x == t)
	{
		huan[t] = true;
		return;
	}
	for (int i = 1; i <= l[x][0]; i++)
		if (!v[l[x][i]])dfs(l[x][i]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		l[a][0]++;
		l[a][l[a][0]] = b;
	}
	for (t = 1; t <= n; t++)
	{
		memset(v, 0, sizeof(v));
		for (int i = 1; i <= l[t][0]; i++)
			dfs(l[t][i]);
	}
	for (int i = 1; i <= n; i++)
		if (huan[i])cout << 'T' << endl;
		else cout << 'F' << endl;
	return 0;
}
