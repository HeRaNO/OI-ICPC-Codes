#include <cstdio>
using namespace std;

int n, x, y, ans;

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch - getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x);
		read(y);
		max(ans, x + y);
	}
	printf("%d\n", ans);
	return 0;
}