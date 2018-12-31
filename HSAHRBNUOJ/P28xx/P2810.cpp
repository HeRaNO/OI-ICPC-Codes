#include <cstdio>
#include <climits>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct stack
{
	int num;
	int l, r;
};

stack s[MAXN];
pair <int, int *> a[MAXN];
int n, T, r, m, x, top;
int sum[MAXN], b[MAXN], ori[MAXN];
long long cnt[MAXN];
char opt[3];

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

inline void Monotonous_Stack(stack p)
{
	while (top && p.num >= s[top - 1].num)
	{
		top--;
		p.l = s[top].l;
		cnt[s[top].num] += (long long)(s[top].r - s[top].l + 1) * (p.r - s[top].r);
	}
	s[top++] = p;
	return ;
}

inline int binary(int x)
{
	int left = 0, right = m + 1, middle;
	while (left + 1 != right)
	{
		middle = (left + right) >> 1;
		if (x >= ori[middle]) left = middle;
		else right = middle;
	}
	return left;
}

int main()
{
	//freopen("jxthree.in","r",stdin);freopen("jxthree.out","w",stdout);
	n = read();
	T = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].first = read();
		a[i].second = &b[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || a[i].first != a[i - 1].first) ori[++m] = a[i].first;
		*a[i].second = m;
	}
	for (int i = 1; i <= n; i++) Monotonous_Stack((stack)
	{
		b[i], i, i
	});
	Monotonous_Stack((stack)
	{
		INT_MAX, n + 1, n + 1
	});
	for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	while (T--)
	{
		scanf("%s", opt);
		x = read();
		r = x;
		x = binary(x);
		if (opt[0] == '=')
		{
			if (ori[x] != r) puts("0");
			else printf("%lld\n", cnt[x] - cnt[x - 1]);
		}
		else if (opt[0] == '>') printf("%lld\n", cnt[m] - cnt[x]);
		else
		{
			if (ori[x] == r) printf("%lld\n", cnt[x - 1]);
			else printf("%lld\n", cnt[x]);
		}
	}
	return 0;
}
