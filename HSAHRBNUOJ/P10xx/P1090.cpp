#include <cstdio>
#include <algorithm>
#define MAXN 5010
using namespace std;

int n, a[MAXN];

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
