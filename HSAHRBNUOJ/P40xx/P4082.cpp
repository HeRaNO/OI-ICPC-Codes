#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define MAXK 200010
using namespace std;

struct flower
{
	int x, y, z, cnt, ans;
	inline bool operator == (const flower &a) const
	{
		return x == a.x && y == a.y && z == a.z;
	}
	inline bool operator < (const flower &a) const
	{
		if (x != a.x) return x < a.x;
		if (y != a.y) return y < a.y;
		return z < a.z;
	}
};

flower a[MAXN], b[MAXN];
int n, m, k, T;
int c[MAXK], tim[MAXK], ans[MAXN];

inline void solve_1stDimension()
{
	int head = 1, tail;
	sort(b + 1, b + n + 1);
	while (head <= n)
	{
		tail = head + 1;
		while (tail <= n && b[head] == b[tail]) tail++;
		a[++m] = b[head];
		a[m].cnt = tail - head;
		head = tail;
	}
	return ;
}

inline bool cmp(flower a, flower b)
{
	return a.y == b.y ? a.z <= b.z : a.y < b.y;
}

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, int v)
{
	for (; x <= k; x += lowbit(x))
	{
		if (tim[x] != T) c[x] = 0;
		tim[x] = T;
		c[x] += v;
	}
	return ;
}

inline int query(int x)
{
	int res = 0;
	for (; x; x -= lowbit(x)) if (tim[x] == T) res += c[x];
	return res;
}

void CDQ(int l, int r)
{
	if (l == r) return ;
	int mid = l + r >> 1, ll = l, rl = mid + 1;
	CDQ(l, mid);
	CDQ(rl, r);
	T++;
	for (int i = l; i <= r; i++)
	{
		if (rl > r || (ll <= mid && cmp(a[ll], a[rl])))
		{
			b[i] = a[ll++];
			modify(b[i].z, b[i].cnt);
		}
		else
		{
			b[i] = a[rl++];
			b[i].ans += query(b[i].z);
		}
	}
	for (int i = l; i <= r; i++) a[i] = b[i];
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
	read(n);
	read(k);
	for (int i = 1; i <= n; i++) read(b[i].x), read(b[i].y), read(b[i].z);
	solve_1stDimension();
	CDQ(1, m);
	for (int i = 1; i <= m; i++) ans[a[i].cnt + a[i].ans - 1] += a[i].cnt;
	for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
	return 0;
}