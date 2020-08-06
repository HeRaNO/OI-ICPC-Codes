#include <bits/stdc++.h>
#define MAXN 1000006
using namespace std;

struct point
{
	int x, y;
	point() {}
	point(int _x, int _y): x(_x), y(_y) {}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	bool operator < (const point &p) const {
		if (p.x != x) return p.x < x;
		else return p.y < y;
	}
	long long operator * (const point &p) const {
		return 1LL * x * p.y - 1LL * y * p.x;
	}
};

int n;
point p[MAXN];
double l = 1e-4, r = 1e4;

inline double check(double k)
{
	double r = -1, rk = 1 + 1 / k; k = k + 1;
	for (int i = 0; i < n; i++)
		r = max(r, p[i].x * k + p[i].y * rk);
	return r;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &p[i].x, &p[i].y);
	for (int i = 0; i < 87; i++)
	{
		double lmid = (l + l + r) / 3.0;
		double rmid = (l + r + r) / 3.0;
		if (check(lmid) < check(rmid)) r = rmid;
		else l = lmid;
	}
	printf("%.4lf\n", check((l + r) / 2.0));
	return 0;
}