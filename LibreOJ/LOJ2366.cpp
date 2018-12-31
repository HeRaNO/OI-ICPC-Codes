#include <cstdio>
#include <algorithm>
#define MAXN 20
using namespace std;

struct glove
{
	int l, r;
	bool operator < (const glove &a)
	{
		return l != a.l ? l<a.l: r>a.r;
	}
};

glove sta[1 << 20 | 1], p[1 << 20 | 1];
int a[2][MAXN], top, n, x, l, r;
int ans = ~(1 << 31), ansl, ansr;

inline void check(int x, int y)
{
	if (ans > x + y)
	{
		ans = x + y;
		ansl = x;
		ansr = y;
	}
	return ;
}

int main()
{
	scanf("%d", &x);
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j < x; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < x; i++)
	{
		if (!a[0][i] || !a[1][i])
		{
			l += a[0][i];
			r += a[1][i];
		}
		else
		{
			a[0][n] = a[0][i];
			a[1][n++] = a[1][i];
		}
	}
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) p[i].r += a[1][j];
			else p[i].l += a[0][j];
		}
	check(p[0].l, 1);
	check(1, p[(1 << n) - 1].r);
	sort(p, p + (1 << n));
	for (int i = 0; i < (1 << n); i++)
	{
		while (top && sta[top].r < p[i].r) top--;
		sta[++top] = p[i];
	}
	for (int i = 2; i <= top; i++) check(sta[i - 1].l + 1, sta[i].r + 1);
	printf("%d\n%d\n", ansl + l, ansr + r);
	return 0;
}