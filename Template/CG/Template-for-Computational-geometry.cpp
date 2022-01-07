#include <cmath>
#include <deque>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1010
using namespace std;
//double can be replaced by long double or int/long long

//Also,the eps can be changed if the problem needs.

const double eps = 1e-7;

inline int sgn(double x)
{
	if (fabs(x) <= eps) return 0;
	return x < 0 ? -1 : 1;
}

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
	point operator * (double rate) const {
		return point(x * rate, y * rate);
	}
	point operator / (double rate) const {
		return point(x / rate, y / rate);
	}
	bool operator < (const point &p) const {
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	int quadrant() const {
		int xs = sgn(x), ys = sgn(y);
		// Change -1 to 1 when sort points by atan2(y, x)
		return xs == 0 && ys == 0 ? -1 : ((ys < 0 || (ys == 0 && xs > 0)) ? 0 : 1);
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
	double Polar_Angle() const {
		return atan2(y, x);
	}
	point Rotate(double alpha) const {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
	}
	point norm() const {
		return point(-y, x);
	}
	point unit(double r = 1) const {
		double d = length();
		return point(x / d * r, y / d * r);
	}
	bool isZero() const {
		return !sgn(x) && !sgn(y);
	}
};

// compare function used in sortint points by atan2(y, x)
bool cmp(const point &a, const point &p)
{
	int lq = a.quadrant(), rq = p.quadrant();
	if (lq != rq) return lq < rq;
	int s = sgn(a * p);
	return s ? s > 0 : sgn(a.length() - p.length()) < 0;
}

struct line
{
	point p, v;
	line() {}
	line(const point &_p, const point &_v): p(_p), v(_v) {}
	bool OnLeft(const point &A) const {
		return sgn((A - p) * v) < 0;
	}
	bool OnRight(const point &A) const {
		return sgn((A - p) * v) > 0;
	}
	bool On(const point &A) const {
		return sgn((A - p) * v) == 0;
	}
	point GetIntersection(const line &l) {
		point u = p - l.p;
		return p + v * ((l.v * u) / (v * l.v));
	}
	bool operator < (const line &l) const {
		int r1 = sgn(v * l.v), r2 = sgn(v ^ l.v);
		return !r1 && r2 > 0 ? l.OnLeft(p) : cmp(v, l.v);
	}
};

int n;
point p[MAXN], ch[MAXN];
//Please start at 0 when you input.(It can be convenient for figure the size)

int ConvexHull(point *p, int n)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && (ch[m - 1] - ch[m - 2]) * (p[i] - ch[m - 2]) <= eps) --m;
		ch[m++] = p[i];
	} // Lower hull
	int k = m;
	for (int i = n - 2; ~i; i--)
	{
		while (m > k && (ch[m - 1] - ch[m - 2]) * (p[i] - ch[m - 2]) <= eps) --m;
		ch[m++] = p[i];
	} // Upper hull
	if (n > 1) m--;
	return m;
}

double Polygon_Area(point *p, int n) //Figure out the size of the Polygon
{
	double S = 0.0;
	int siz = ConvexHull(p, n);
	for (int i = 0; i < siz; i++) S += ch[i] * ch[(i + 1) % siz];
	return fabs(S / 2.0);
}

double Rotating_Calipers(point p[]) //Get the longest distance among points
{
	double res = 0.0;
	int q = 1;
	int n = ConvexHull(p, n);
	for (int i = 0; i < n; i++)
	{
		while ((ch[i + 1] - ch[i]) * (ch[q + 1] - ch[i]) > (ch[i + 1] - ch[i]) * (ch[q] - ch[i])) q = (q + 1) % n;
		res = max(res, max((ch[i] - ch[q]).length(), (ch[i + 1] - ch[q + 1]).length()));
	}
	return res;
}

// Is segment ab intersect with segment cd?
inline bool isIntersection(point a, point b, point c, point d)
{
	if (max(a.x, b.x) < min(c.x, d.x)) return false;
	if (max(a.y, b.y) < min(c.y, d.y)) return false;
	if (max(c.x, d.x) < min(a.x, b.x)) return false;
	if (max(c.y, d.y) < min(a.y, b.y)) return false;
	double p = (b - a) * (b - c);
	double q = (b - a) * (b - d);
	double r = (d - c) * (d - a);
	double s = (d - c) * (d - b);
	return (p * q <= eps) && (r * s <= eps);
}

// Judge whether point A, B and C listed in a counterclockwise order
// When ccw(A, B, C) = 0, A, B and C lie on a same line
bool ccw(point A, point B, point C)
{
	return sgn(A * B + B * C + C * A) > 0;
}

// PIP Problem: Ray casting algorithm
// Point: (x, y), Polygon size: c
// Return val: 0: out, 1: in, 2: on the polygon
int in(int x, int y, int c)
{
	double k = sqrt(2), b = y - k * x;
	int cnt = 0; point O = point(x, y);
	for (int i = 0; i < c; i++)
		if (ch[i].x == x && ch[i].y == y) return 2;
	for (int i = 0; i < c; i++)
	{
		point oa = ch[i] - O;
		point ob = ch[(i + 1) % c] - O;
		if (!sgn(oa * ob)) return 2;
	}
	for (int i = 0; i < c; i++)
	{
		double A = ch[(i + 1) % c].y - ch[i].y;
		double B = ch[i].x - ch[(i + 1) % c].x;
		double C = ch[(i + 1) % c] * ch[i];
		double lx = min(ch[i].x, ch[(i + 1) % c].x), rx = max(ch[i].x, ch[(i + 1) % c].x);
		double ly = min(ch[i].y, ch[(i + 1) % c].y), ry = max(ch[i].y, ch[(i + 1) % c].y);
		double nx = -(B * b + C) / (A + B * k);
		double ny = k * nx + b;
		if (ny > y) continue;
		if (lx - eps <= nx && nx <= rx + eps && ly - eps <= ny && ny <= ry + eps) ++cnt;
	}
	return cnt & 1;
}

point r[MAXN];

// Consider the left side region of l.v
// There may be same point in ans
// q is the intersection of halfplane
// Should notice the ans only indicate the intersection point of the adjacent halfplanes.
inline int halfplaneIntersection(vector<line> &l)
{
	deque<line> q;
	deque<point> ans;
	int n = l.size();
	sort(l.begin(), l.end());
	q.push_back(l.front());
	for (int i = 1; i < n; i++)
	{
		if (!sgn(l[i].v * l[i - 1].v)) continue;
		while (!ans.empty() && l[i].OnRight(ans.back()))
		{
			ans.pop_back();
			q.pop_back();
		}
		while (!ans.empty() && l[i].OnRight(ans.front()))
		{
			ans.pop_front();
			q.pop_front();
		}
		ans.push_back(l[i].GetIntersection(q.back()));
		q.push_back(l[i]);
	}
	while (!ans.empty() && q.front().OnRight(ans.back()))
	{
		ans.pop_back();
		q.pop_back();
	}
	while (!ans.empty() && q.back().OnRight(ans.front()))
	{
		ans.pop_front();
		q.pop_front();
	}
	ans.push_back(q.back().GetIntersection(q.front()));
	int m = ans.size();
	for (int i = 0; i < m; i++)
	{
		r[i] = ans.front();
		ans.pop_front();
	}
	/* delete the same point
	int m = 0;
	for (point las = ans.back(); !ans.empty(); ans.pop_front())
		if (!(ans.front() - las).isZero())
			r[m++] = ans.front(), las = ans.front();
	*/
	return m;
}

int main()
{
	return 0;
}
