#include <cstdio>
#define MAXV 1000010
using namespace std;

int n, V, x, y, f[MAXV], ans;

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(V);
	for (int i = 1; i <= n; i++)
	{
		read(x);
		read(y);
		for (int j = V; j >= x; j--) max(f[j], f[j - x] + y);
	}
	for (int i = 0; i <= V; i++) max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
