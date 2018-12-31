#include <cstdio>
#include <algorithm>
#define MAXQ 200010
#define MAXW 2000010
using namespace std;

struct Mokia
{
	int x, y, opt, delta, id, pos;
};

Mokia q[MAXQ], t[MAXQ];
int n, T, opt, x1, x2, y_1, y2, A;
int c[MAXW], ans[MAXQ];

bool cmp(Mokia a, Mokia b)
{
	if (a.x == b.x && a.y == b.y) return a.opt < b.opt;
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, int v)
{
	for (; x <= n; x += lowbit(x)) c[x] += v;
	return ;
}

inline int query(int x)
{
	int res = 0;
	for (; x; x -= lowbit(x)) res += c[x];
	return res;
}

void CDQ(int l, int r)
{
	if (l == r) return ;
	int mid = l + r >> 1, ll = l, rl = mid + 1;
	for (int i = l; i <= r; i++)
	{
		if (q[i].id <= mid && !q[i].opt) modify(q[i].y, q[i].delta);
		else if (q[i].id > mid && q[i].opt) ans[q[i].pos] += q[i].delta * query(q[i].y);
	}
	for (int i = l; i <= r; i++)
		if (q[i].id <= mid && !q[i].opt) modify(q[i].y, -q[i].delta);
	for (int i = l; i <= r; i++)
		if (q[i].id <= mid) t[ll++] = q[i];
		else t[rl++] = q[i];
	for (int i = l; i <= r; i++) q[i] = t[i];
	CDQ(l, mid);
	CDQ(mid + 1, r);
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	while (true)
	{
		read(opt);
		opt--;
		if (!~opt) read(n);
		else if (!opt)
		{
			read(x1);
			read(y_1);
			read(A);
			q[++T] = (Mokia)
			{
				x1, y_1, opt, A, 0, 0
			};
			q[T].id = T;
		}
		else if (opt == 1)
		{
			read(x1);
			read(y_1);
			read(x2);
			read(y2);
			ans[0]++;
			q[++T] = (Mokia)
			{
				x1 - 1, y_1 - 1, opt, 1, 0, ans[0]
			};
			q[T].id = T;
			q[++T] = (Mokia)
			{
				x2, y_1 - 1, opt, -1, 0, ans[0]
			};
			q[T].id = T;
			q[++T] = (Mokia)
			{
				x1 - 1, y2, opt, -1, 0, ans[0]
			};
			q[T].id = T;
			q[++T] = (Mokia)
			{
				x2, y2, opt, 1, 0, ans[0]
			};
			q[T].id = T;
		}
		else break;
	}
	sort(q + 1, q + T + 1, cmp);
	CDQ(1, T);
	for (int i = 1; i <= ans[0]; i++) printf("%d\n", ans[i]);
	return 0;
}
