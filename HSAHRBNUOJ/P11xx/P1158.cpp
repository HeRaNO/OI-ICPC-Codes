#include <cstdio>
#include <cstring>
#define MAXN 81

char a[MAXN], b[MAXN];
int n, m, i, j, ans;

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

int main()
{
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	for (i = 1, j = m; i <= n && j; i++, j--)
	{
		bool f = true;
		for (int k = 1; k <= i && f; k++) if (a[k] != b[j + k - 1]) f = false;
		if (f) max(ans, i);
	}
	for (i = n, j = 1; i && j <= m; i--, j++)
	{
		bool f = true;
		for (int k = 1; k <= j && f; k++) if (a[i + k - 1] != b[k]) f = false;
		if (f) max(ans, j);
	}
	printf("%d\n", ans);
	return 0;
}