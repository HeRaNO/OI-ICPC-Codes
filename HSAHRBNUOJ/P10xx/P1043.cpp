#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[100];
char b[100][100];
int a[100], c[100];
int n;
void print()
{
	int i;
	for (i = 65; i < 64 + n; i++) printf("%d ", a[i]);
	printf("%d", a[64 + n]);
	return ;
}
bool judge1()
{
	int i;
	for (i = n; i > 0; i--)
		if (a[b[i][1]] != -1 &&  a[b[i][2]] != -1 && a[b[i][3]] != -1  &&
				(a[b[i][1]] + a[b[i][2]]) % n != a[b[i][3]] &&
				(a[b[i][1]] + a[b[i][2]] + 1) % n != a[b[i][3]]) return 0;
	return 1;
}

bool judge2()
{
	int i, k = 0;
	for (i = n; i > 1; i--)
	{
		k = a[b[i][1]] + a[b[i][2]] + k;
		if (a[b[i][3]] != k % n) return false;
		k /= n;
	}
	return true;
}
void DFS(int m)
{
	int i;
	if (!judge1()) return ;
	if (a[b[1][1]] + a[b[1][2]] >= n) return ;
	if (m > n)
	{
		if (judge2())
		{
			print();
			exit(0);
		}
		else return ;
	}
	else
	{
		for (i = n - 1; i >= 0; i--)
		{
			if (vis[i])
			{
				a[c[m]] = i;
				vis[i] = 0;
				DFS(m + 1);
				a[c[m]] = -1;
				vis[i] = 1;
			}
		}
	}
}
int main()
{
	int k = 1;
	bool h[100];
	memset(h, 1, sizeof(h));
	memset(vis, 1, sizeof(vis));
	memset(a, -1, sizeof(a));
	scanf("%d", &n);
	for (int j = 1; j < 4; j++)
		for (int i = 1; i <= n; i++)
			cin >> b[i][j];
	for (int i = n; i > 0; i--)
		for (int j = 1; j < 4; j++)
			if (h[b[i][j]])
			{
				c[k++] = b[i][j];
				h[b[i][j]] = 0;
			}
	DFS(1);
	return 0;
}
