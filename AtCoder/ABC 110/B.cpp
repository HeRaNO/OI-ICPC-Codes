#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n, m, X, Y, mx = 1 << 31, mn = ~(1 << 31);
int x[MAXN], y[MAXN];

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
	read(X);
	read(Y);
	for (int i = 1; i <= n; i++) read(x[i]);
	for (int i = 1; i <= m; i++) read(y[i]);
	for (int Z = X + 1; Z <= Y; Z++)
	{
		bool f = true;
		for (int i = 1; i <= n && f; i++) if (x[i] >= Z) f = false;
		if (!f) continue;
		for (int i = 1; i <= m && f; i++) if (y[i] < Z) f = false;
		if (f)
		{
			puts("No War");
			return 0;
		}
	}
	puts("War");
	return 0;
}