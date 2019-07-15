#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

int n, k, a[MAXN];

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

int main()
{
	n = read(); k = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	if (k == 0)
	{
		if (a[1] == 1) puts("-1");
		else printf("%d\n",a[1] - 1);
		return 0;
	}
	if (a[k] == a[k + 1]) puts("-1");
	else printf("%d\n",a[k]);
	return 0;
}