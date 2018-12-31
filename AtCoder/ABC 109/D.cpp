#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

struct e
{
	int a, b, c, d;
	e() {}
	e(int x, int xx, int xxx, int xxxx): a(x), b(xx), c(xxx), d(xxxx) {}
	void print()
	{
		printf("%d %d %d %d\n", a, b, c, d);
	}
};

int n, m, h, a[MAXN][MAXN];
vector <e> p;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++)
			if (a[i][j] & 1)
			{
				p.push_back(e(i, j, i, j + 1));
				--a[i][j];
				++a[i][j + 1];
			}
	for (int i = 1; i < n; i++)
		if (a[i][m] & 1)
		{
			p.push_back(e(i, m, i + 1, m));
			--a[i][m];
			++a[i + 1][m];
		}
	h = p.size();
	printf("%d\n", h);
	for (int i = 0; i < h; i++) p[i].print();
	return 0;
}