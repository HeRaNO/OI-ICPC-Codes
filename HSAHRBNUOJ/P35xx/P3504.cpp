#include <cstdio>
#define MAXN 300010
using namespace std;

struct lis
{
	int l, r;
};

lis b[MAXN];
int n, a[MAXN];
int pos, x, from, cnt, ans;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

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
	pos = 1;
	for (int i = 1; i <= n; i++) read(a[i]);
	while (pos <= n)
	{
		x = a[pos];
		from = pos;
		pos++;
		while (pos <= n && x < a[pos]) x = a[pos++];
		b[++cnt] = (lis)
		{
			from, pos - 1
		};
	}
	for (int i = 1; i <= cnt; i++)
	{
		ans = mymax(ans, b[i].r - b[i].l + 1);
		if ((b[i + 1].r > b[i + 1].l && a[b[i + 1].l + 1] > a[b[i].r]) || (b[i].r > b[i].l && a[b[i + 1].l] > a[b[i].r - 1]))
			ans = mymax(ans, b[i + 1].r - b[i].l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
