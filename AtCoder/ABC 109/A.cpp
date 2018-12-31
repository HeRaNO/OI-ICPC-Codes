#include <bits/stdc++.h>
using namespace std;

int a, b;

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
	read(a);
	read(b);
	if (a * b % 2) puts("Yes");
	else puts("No");
	return 0;
}