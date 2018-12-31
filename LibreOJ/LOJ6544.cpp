#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 2010
using namespace std;

const double pi = acos(-1.0);

inline int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

struct Angle
{
	int x, y;
	Angle() {}
	Angle(int _x, int _y)
	{
		bool f = (_x < 0);
		if (f) _x = -_x;
		int t = gcd(_x, _y);
		_x /= t;
		_y /= t;
		if (!_x) _y = 1;
		if (f) _x = -_x;
		x = _x;
		y = _y;
	}
	bool operator != (const Angle &a)const
	{
		return !((x == a.x) && (y == a.y));
	}
	bool operator < (const Angle &a)const
	{
		return x == a.x ? y<a.y: x>a.x;
	}
};

struct Point
{
	int x, y;
	Angle a;
	Point() {}
	Point(int x, int y): x(x), y(y) {}
	Point operator - (const Point &p)const
	{
		return Point(x - p.x, y - p.y);
	}
	bool operator < (const Point &p)const
	{
		return a < p.a;
	}
	inline void getAngle(const Point &p)
	{
		int m = p.x, n = p.y;
		if (p.y <= 0)
		{
			m = -m;
			n = -n;
		}
		a = Angle(m, n);
		return ;
	}
} O;

Point p[MAXN], a[MAXN];
int n, l, pt, ans;

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

inline void Analyze(int x)
{
	l = 0;
	pt = 0;
	O = p[x];
	for (int i = 1; i <= n; i++) if (i != x) a[++pt] = p[i];
	for (int i = 1; i < n; i++) a[i].getAngle(a[i] - O);
	sort(a + 1, a + n);
	for (int i = 1; i < n; i++)
		if (a[i].a != a[i - 1].a)
		{
			max(ans, i - l);
			l = i - 1;
		}
	max(ans, n - l);
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(p[i].x), read(p[i].y);
	for (int i = 1; i <= n; i++) Analyze(i);
	printf("%d\n", ans);
	return 0;
}
