#include <cstdio>
#define MAXN 500010
using namespace std;

struct Segment
{
	int l, r, m;
};

Segment b[MAXN];
int n, x, from, pos, cnt, ans;
int a[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("median.in","r",stdin);freopen("median.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[0] = a[1];
	a[n + 1] = a[n];
	n++;
	while (pos <= n)
	{
		x = a[pos];
		from = pos;
		pos++;
		while (pos <= n && a[pos]^x) x = a[pos++];
		if (pos - from <= 1) continue;
		b[++cnt] = (Segment)
		{
			from, pos - 1, (pos - 1 + from) >> 1
		};
		ans = mymax(ans, (pos - 1 - from) >> 1);
	}
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = b[i].l; j <= b[i].m; j++)   a[j] = a[b[i].l];
		for (int j = b[i].m + 1; j <= b[i].r; j++) a[j] = a[b[i].r];
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n - 1; i++) printf("%d ", a[i]);
	return 0;
}
