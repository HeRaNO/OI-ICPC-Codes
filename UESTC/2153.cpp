#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

struct Parity
{
	int l, r;
	bool type;
	Parity() {}
	Parity(int _l, int _r, bool _t): l(_l), r(_r), type(_t) {}
};

Parity a[MAXN >> 1];
int n, m, T, l, r, t, f[MAXN << 1], fx, fy;
pair <int, int *> b[MAXN];

inline int getfather(int x)
{
	return x == f[x] ? x : f[x] = getfather(f[x]);
}

inline void Union(int x, int y)
{
	x = getfather(x);
	y = getfather(y);
	if (x != y) f[y] = x;
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'e')
		{
			getchar();
			getchar();
			getchar();
			x = 1;
			return ;
		}
		if (ch == 'o')
		{
			getchar();
			getchar();
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(T);
	for (int i = 1; i <= (T << 2); i++) f[i] = i;
	for (int i = 1; i <= T; i++)
	{
		read(l);
		read(r);
		read(t);
		a[i] = Parity(l - 1, r, t);
		b[(i << 1) - 1] = make_pair(a[i].l, &a[i].l);
		b[i << 1] = make_pair(a[i].r, &a[i].r);
	}
	sort(b + 1, b + (T << 1) + 1);
	for (int i = 1; i <= (T << 1); i++)
	{
		if (b[i].first != b[i - 1].first) m++;
		*b[i].second = m;
	}
	for (int i = 1; i <= T; i++) //even-true odd-false
	{
		if (!a[i].type)
		{
			fx = getfather(a[i].l);
			fy = getfather(a[i].r);
			if (fx == fy)
			{
				printf("%d\n", i - 1);
				return 0;
			}
			Union(a[i].r + (T << 1), a[i].l);
			Union(a[i].l + (T << 1), a[i].r);
		}
		else
		{
			fx = getfather(a[i].l);
			fy = getfather(a[i].r + (T << 1));
			if (fx == fy)
			{
				printf("%d\n", i - 1);
				return 0;
			}
			Union(a[i].l, a[i].r);
			Union(a[i].l + (T << 1), a[i].r + (T << 1));
		}
	}
	puts("ORZQHQH");
	return 0;
}