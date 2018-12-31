#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int n, x[MAXN], y[MAXN], tx, ty, p;
vector <int> v;

inline int abs(int a)
{
	return a < 0 ? -a : a;
}

inline int read()
{
	int x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	x[1] = read();
	y[1] = read();
	p = (abs(x[1]) + abs(y[1])) % 2;
	for (int i = 2; i <= n; i++)
	{
		x[i] = read();
		y[i] = read();
		if ((abs(x[i]) + abs(y[i])) % 2 != p)
		{
			puts("-1");
			return 0;
		}
	}
	for (int i = 30; ~i; i--) v.push_back(1 << i);
	if (!p) v.push_back(1);
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) printf("%d%c", v[i], i == v.size() - 1 ? '\n' : ' ');
	for (int i = 1; i <= n; i++)
	{
		tx = x[i];
		ty = y[i];
		for (int j = 0; j < v.size(); j++)
		{
			if (abs(tx) > abs(ty))
			{
				if (tx > 0)
				{
					tx -= v[j];
					putchar('R');
				}
				else
				{
					tx += v[j];
					putchar('L');
				}
			}
			else
			{
				if (ty > 0)
				{
					ty -= v[j];
					putchar('U');
				}
				else
				{
					ty += v[j];
					putchar('D');
				}
			}
		}
		putchar('\n');
	}
	return 0;
}