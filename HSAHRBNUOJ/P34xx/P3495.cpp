#include <cstdio>
#define MAXN 1000010
using namespace std;

int a, b, c, ans, n, m;
int debt[MAXN];

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(a);
		read(b);
		read(c);
		debt[a] += c;
		debt[b] -= c;
	}
	for (int i = 1; i <= n; i++) if (debt[i] > 0) ans += debt[i];
	printf("%d\n", ans);
	return 0;
}
