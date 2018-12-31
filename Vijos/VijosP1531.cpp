#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXN 50000*3+10
using namespace std;

int f[MAXN];
int n, k, d, x, y, ans = 0;
int i, j;

void init(int n) //初值，每一个节点是自己的爹  (3*n)??
{
	for (i = 1; i <= 3 * n; i++)
		f[i] = i;
}

int find(int x)  //找爹
{
	if (f[x] != x)
		return f[x] = find(f[x]);
	return x;
}

bool same(int x, int y) //看两个节点是不是一个爹
{
	return find(x) == find(y);
}

void add(int x, int y)
{
	int u = find(x);
	int v = find(y);
	if (u != v)
		f[u] = v;
	return;
}

int main()
{
	scanf("%d%d", &n, &k);
	init(n);
	for (i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &d, &x, &y);
		if (x > n || y > n)
		{
			ans++;
			continue;
		}
		if (d == 1)
		{
			if (same(x, y + n) || same(x, y + 2 * n))
				ans++;
			else
			{
				add(x, y);
				add(x + n, y + n);
				add(x + 2 * n, y + 2 * n);
			}
		}
		else
		{
			if (same(x, y) || same(x, y + 2 * n))
				ans++;
			else
			{
				add(x, y + n);
				add(x + n, y + 2 * n);
				add(x + 2 * n, y);
			}
		}
	}
	cout << ans;
	//system("PAUSE");
	return 0;
}