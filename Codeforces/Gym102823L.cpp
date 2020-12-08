#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

inline int sgn(double x){ return fabs(x) <= eps ? 0 : (x < 0 ? -1 : 1); }

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	point operator + (const point &p) const {
		return point(x + p.x, y + p.y);
	}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	point operator * (double r) const {
		return point(x * r, y * r);
	}
	bool operator == (const point &p) const {
		return fabs(x - p.x) <= eps && fabs(y - p.y) <= eps;
	}
	double length() const {
		return sqrt(x * x + y * y);
	}
	double operator ^ (const point &p) const {
		return x * p.x + y * p.y;
	}
	double operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
};

struct line
{
	point p, v;
	line() {}
	line(const point &_p, const point &_v): p(_p), v(_v) {}
	point GetIntersection(const line &l) {
		point u = p - l.p;
		return p + v * ((l.v * u) / (v * l.v));
	}
};

int n, x, y;

inline bool OnSeg(point A, point B, point P)
{
	point PA = A - P, PB = B - P;
	if (sgn(PA * PB)) return false;
	if (P == A || P == B) return true;
	return sgn(PA ^ PB) == -1;
}

inline double S(point A, point B, point C)
{
	return (C - A) * (C - B) / 2.0;
}

inline void Solve(int cas)
{
	point wa, wb, ba, bb;
	scanf("%d %d", &x, &y); wa = point(x, y);
	scanf("%d %d", &x, &y); wb = point(x, y);
	scanf("%d %d", &x, &y); ba = point(x, y);
	scanf("%d %d", &x, &y); bb = point(x, y);
	if (wa == wb) return printf("Case %d: 0\n", cas), void();
	if (ba == bb) return printf("Case %d: inf\n", cas), void();
	line W = line(wa, wb - wa);
	line B = line(ba, bb - ba);
	point CRO = W.GetIntersection(B);
	if (!sgn((wb - ba) * (wa - bb)))return printf("Case %d: 0\n", cas), void();
	if (CRO == bb || CRO == ba)
	{
		if (OnSeg(wa, wb, CRO))
			return printf("Case %d: inf\n", cas), void();
		else return printf("Case %d: 0\n", cas), void();
	}
	if (OnSeg(ba, bb, CRO))
		return printf("Case %d: 0\n", cas), void();
	if (OnSeg(wa, wb, CRO))
		return printf("Case %d: inf\n", cas), void();

	if (!sgn((wa - bb) * (wb - ba))) return printf("Case %d: inf\n", cas), void();
	if (!sgn((wb - bb) * (wa - ba))) return printf("Case %d: inf\n", cas), void();
	line wawb = line(wa, bb - wa);
	line babb = line(wb, ba - wb);

	point C = wawb.GetIntersection(babb);
	point bbC = C - bb;
	point bbwa = wa - bb;
	if (sgn(bbC ^ bbwa) == -1) return printf("Case %d: inf\n", cas), void();
	if (bbC.length() > bbwa.length())
		return printf("Case %d: %.9lf\n", cas, fabs(S(C, wa, wb))), void();

	line wabb = line(wa, ba - wa);
	line wbba = line(wb, bb - wb);
	C = wabb.GetIntersection(wbba);
	point baC = C - bb;
	point bawb = wb - bb;
	if (sgn(baC ^ bawb) == -1) return printf("Case %d: inf\n", cas), void();
	if (baC.length() > bawb.length())
		return printf("Case %d: %.9lf\n", cas, fabs(S(C, wa, wb))), void();
	printf("Case %d: 0\n", cas);
	return ;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) Solve(i);
	return 0;
}
