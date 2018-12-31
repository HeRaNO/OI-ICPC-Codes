#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

int f[MAXN], p[MAXN], n, x, T, a[MAXN];

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
	read(T);
	while (T--)
	{
		read(n);
		f[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			read(a[i]);
			f[i] = 1;
		}
		for (int i = n; ~i; i--)
			for (int j = i + 1; j <= n; j++)
				if (a[j] > a[i])
				{
					if (f[i] < f[j] + 1 || (f[i] == f[j] + 1 && a[p[i]] > a[j]))
					{
						p[i] = j;
						f[i] = f[j] + 1;
					}
				}
		printf("%d ", f[0] - 1);
		for (int i = p[0]; i; i = p[i]) printf("%d ", a[i]);
		puts("");
		memset(p, 0, sizeof p);
	}
	return 0;
}