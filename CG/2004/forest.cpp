#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 15
using namespace std;

struct point
{
	int x, y, v, l;
	point() {}
	point(int _x, int _y): x(_x), y(_y) {}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	bool operator < (const point &p) const {
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	int operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
	double length() const {
		return sqrt(x * x + y * y);
	}
};

point p[MAXN], a[MAXN], ch[MAXN];
int n;
int ansV = ~(1 << 31), ansSta;
double ansL;
bool f = true;

double ConvexHull(point *p, int n)
{
	if (!n) return 1e18;
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && (ch[m - 1] - ch[m - 2]) * (p[i] - ch[m - 2]) <= 0) ch[m--] = point(0, 0);
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; ~i; i--)
	{
		while (m > k && (ch[m - 1] - ch[m - 2]) * (p[i] - ch[m - 2]) <= 0) ch[m--] = point(0, 0);
		ch[m++] = p[i];
	}
	if (n > 1) --m;
	double ans = 0.0;
	for (int i = 0; i < m; i++) ans += (ch[(i + 1) % m] - ch[i]).length();
	return ans;
}

inline void write(int x)
{
	if (f){ f = false; printf("%d", x); }
	else printf(" %d", x);
	return ;
}

int main()
{
	scanf("%d", &n); ansSta = (1 << n) - 1;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &p[i].x, &p[i].y, &p[i].v, &p[i].l);
	for (int i = 0; i < (1 << n); i++)
	{
		int L = 0, V = 0, A = 0;
		for (int j = 0; j < n; j++)
			if (!(i & (1 << j))) a[A++] = p[j];
			else L += p[j].l, V += p[j].v;
		double allL = ConvexHull(a, A);
		if (L < allL) continue;
		if (ansV > V)
		{
			ansV = V; ansL = L - allL; ansSta = i;
		}
		else if (ansV == V && __builtin_popcount(ansSta) > __builtin_popcount(i))
		{
			ansL = L - allL; ansSta = i;
		}
	}
	printf("%.2lf\n", ansL);
	for (int i = 0; i < n; i++) if (ansSta & (1 << i)) write(i + 1);
	puts("");
	return 0;
}