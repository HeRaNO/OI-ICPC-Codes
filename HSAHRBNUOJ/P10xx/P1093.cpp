#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

int n, k, a[MAXN];

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

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	read(n);
	read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1, cmp);
	printf("%d\n", a[k]);
	return 0;
}
