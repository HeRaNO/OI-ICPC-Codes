#include <cstdio>
#define MAXN 2005
using namespace std;

int n, T, a, x, y, ans, f[MAXN << 1];
bool cnt[MAXN];

inline int getfather(int x)
{
	return x == f[x] ? x : f[x] = getfather(f[x]);
}

inline void Union(int x, int y)
{
	x = getfather(x);
	y = getfather(y);
	if (x != y) f[y] = x;
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'E') return ;
		if (ch == 'F')
		{
			x = 1;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(T);
	for (int i = 1; i <= (n << 1); i++) f[i] = i;
	while (T--)
	{
		read(a);
		read(x);
		read(y);
		if (!a)
		{
			Union(x, y + n);
			Union(y, x + n);
		}
		else Union(x, y);
	}
	for (int i = 1; i <= n; i++) cnt[getfather(i)] = true;
	for (int i = 1; i <= n; i++) if (cnt[i]) ans++;
	printf("%d\n", ans);
	return 0;
}