#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const double pi = 4 * atan(1);
const double eps = 1e-8;

inline int dcmp (double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }
inline double getDistance (double x, double y) { return sqrt(x * x + y * y); }
inline double torad(double deg) { return deg / 180 * pi; }

struct Point {
	double x, y;
	int be;
	Point (double x = 0, double y = 0, int be = 0): x(x), y(y), be(be) {}
	void read () { scanf("%lf%lf", &x, &y); }
	void write () { printf("%lf %lf", x, y); }

	bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
	bool operator != (const Point& u) const { return !(*this == u); }
	bool operator < (const Point& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }
	bool operator > (const Point& u) const { return u < *this; }
	bool operator <= (const Point& u) const { return *this < u || *this == u; }
	bool operator >= (const Point& u) const { return *this > u || *this == u; }
	Point operator + (const Point& u) { return Point(x + u.x, y + u.y, be); }
	Point operator - (const Point& u) { return Point(x - u.x, y - u.y, be); }
	Point operator * (const double u) { return Point(x * u, y * u, be); }
	Point operator / (const double u) { return Point(x / u, y / u, be); }
	double operator * (const Point& u) { return x*u.y - y*u.x; }
};
typedef Point Vector;
typedef vector<Point> Polygon;

struct Line {
	double a, b, c;
	Line (double a = 0, double b = 0, double c = 0): a(a), b(b), c(c) {}
};

struct DirLine {
	Point p;
	Vector v;
	double ang;
	DirLine () {}
	DirLine (Point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }
	bool operator < (const DirLine& u) const { return ang < u.ang; }
};

struct Circle {
	Point o;
	double r;
	Circle () {}
	Circle (Point o, double r = 0): o(o), r(r) {}
	void read () { o.read(), scanf("%lf", &r); }
	Point point(double rad) { return Point(o.x + cos(rad)*r, o.y + sin(rad)*r); }
	double getArea (double rad) { return rad * r * r / 2; }
};

namespace Punctual {
	double getDistance (Point a, Point b) { double x=a.x-b.x, y=a.y-b.y; return sqrt(x*x + y*y); }
};

namespace Vectorial {
	double getDot (Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
	double getCross (Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

	double getLength (Vector a) { return sqrt(getDot(a, a)); }
	double getPLength (Vector a) { return getDot(a, a); }
	double getAngle (Vector u) { return atan2(u.y, u.x); }
	double getAngle (Vector a, Vector b) { return acos(getDot(a, b) / getLength(a) / getLength(b)); }
	Vector rotate (Vector a, double rad) { return Vector(a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)); }
	Vector getNormal (Vector a) { double l = getLength(a); return Vector(-a.y/l, a.x/l); }
};

namespace ComplexVector {
	typedef complex<double> Point;
	typedef Point Vector;

	double getDot(Vector a, Vector b) { return real(conj(a)*b); }
	double getCross(Vector a, Vector b) { return imag(conj(a)*b); }
	Vector rotate(Vector a, double rad) { return a*exp(Point(0, rad)); }
};

namespace Linear {
	using namespace Vectorial;

	Line getLine (double x1, double y1, double x2, double y2) { return Line(y2-y1, x1-x2, y1*x2-x1*y2); }
	Line getLine (double a, double b, Point u) { return Line(a, -b, u.y * b - u.x * a); }

	bool getIntersection (Line p, Line q, Point& o) {
		if (fabs(p.a * q.b - q.a * p.b) < eps)
			return false;
		o.x = (q.c * p.b - p.c * q.b) / (p.a * q.b - q.a * p.b);
		o.y = (q.c * p.a - p.c * q.a) / (p.b * q.a - q.b * p.a);
		return true;
	}

	bool getIntersection (Point p, Vector v, Point q, Vector w, Point& o) {
		if (dcmp(getCross(v, w)) == 0) return false;
		Vector u = p - q;
		double k = getCross(w, u) / getCross(v, w);
		o = p + v * k;
		return true;
	}

	double getDistanceToLine (Point p, Point a, Point b) { return fabs(getCross(b-a, p-a) / getLength(b-a)); }
	double getDistanceToSegment (Point p, Point a, Point b) {
		if (a == b) return getLength(p-a);
		Vector v1 = b - a, v2 = p - a, v3 = p - b;
		if (dcmp(getDot(v1, v2)) < 0) return getLength(v2);
		else if (dcmp(getDot(v1, v3)) > 0) return getLength(v3);
		else return fabs(getCross(v1, v2) / getLength(v1));
	}

	Point getPointToLine (Point p, Point a, Point b) { Vector v = b-a; return a+v*(getDot(v, p-a) / getDot(v,v)); }

	bool haveIntersection (Point a1, Point a2, Point b1, Point b2) {
		double c1=getCross(a2-a1, b1-a1), c2=getCross(a2-a1, b2-a1), c3=getCross(b2-b1, a1-b1), c4=getCross(b2-b1,a2-b1);
		return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
	}

	bool onSegment (Point p, Point a, Point b) { return dcmp(getCross(a-p, b-p)) == 0 && dcmp(getDot(a-p, b-p)) < 0; }
	bool onLeft(DirLine l, Point p) { return dcmp(l.v * (p-l.p)) >= 0; }
}

namespace Triangular {
	using namespace Vectorial;

	double getAngle (double a, double b, double c) { return acos((a*a+b*b-c*c) / (2*a*b)); }
	double getArea (double a, double b, double c) { double s =(a+b+c)/2; return sqrt(s*(s-a)*(s-b)*(s-c)); }
	double getArea (double a, double h) { return a * h / 2; }
	double getArea (Point a, Point b, Point c) { return fabs(getCross(b - a, c - a)) / 2; }
	double getDirArea (Point a, Point b, Point c) { return getCross(b - a, c - a) / 2; }
};

namespace Polygonal {
	using namespace Vectorial;
	using namespace Linear;

	double getArea (Point* p, int n) {
		double ret = 0;
		for (int i = 0; i < n-1; i++)
			ret += (p[i]-p[0]) * (p[i+1]-p[0]);
		return ret/2;
	}

	int getConvexHull (Point* p, int n, Point* ch) {
		sort(p, p + n);
		int m = 0;
		for (int i = 0; i < n; i++) {
			while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) < 0) m--;
			//while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) <= 0) m--;
			ch[m++] = p[i];
		}
		int k = m;
		for (int i = n-2; i >= 0; i--) {
			/* 可共线 */
			while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) < 0) m--;
			//while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
			ch[m++] = p[i];
		}
		if (n > 1) m--;
		return m;
	}

	int isPointInPolygon (Point o, Point* p, int n) {
		int wn = 0;
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			if (onSegment(o, p[i], p[j]) || o == p[i]) return 0; // 边界上
			int k = dcmp(getCross(p[j] - p[i], o-p[i]));
			int d1 = dcmp(p[i].y - o.y);
			int d2 = dcmp(p[j].y - o.y);
			if (k > 0 && d1 <= 0 && d2 > 0) wn++;
			if (k < 0 && d2 <= 0 && d1 > 0) wn--;
		}
		return wn ? -1 : 1;
	}

	void rotatingCalipers(Point *p, int n, vector<pii>& sol) {
		sol.clear();
		int j = 1; p[n] = p[0];
		for (int i = 0; i < n; i++) {
			while (getCross(p[j+1]-p[i+1], p[i]-p[i+1]) > getCross(p[j]-p[i+1], p[i]-p[i+1]))
				j = (j+1) % n;
			sol.push_back(make_pair(i, j));
			sol.push_back(make_pair(i + 1, j + 1));
		}
	}

	void rotatingCalipersGetRectangle (Point *p, int n, double& area, double& perimeter) {
		p[n] = p[0];
		int l = 1, r = 1, j = 1;
		area = perimeter = 1e20;

		for (int i = 0; i < n; i++) {
			Vector v = (p[i+1]-p[i]) / getLength(p[i+1]-p[i]);
			while (dcmp(getDot(v, p[r%n]-p[i]) - getDot(v, p[(r+1)%n]-p[i])) < 0) r++;
			while (j < r || dcmp(getCross(v, p[j%n]-p[i]) - getCross(v,p[(j+1)%n]-p[i])) < 0) j++;
			while (l < j || dcmp(getDot(v, p[l%n]-p[i]) - getDot(v, p[(l+1)%n]-p[i])) > 0) l++;
			double w = getDot(v, p[r%n]-p[i])-getDot(v, p[l%n]-p[i]);
			double h = getDistanceToLine (p[j%n], p[i], p[i+1]);
			area = min(area, w * h);
			perimeter = min(perimeter, 2 * w + 2 * h);
		}
	}

	Polygon cutPolygon (Polygon u, Point a, Point b) {
		Polygon ret;
		int n = u.size();
		for (int i = 0; i < n; i++) {
			Point c = u[i], d = u[(i+1)%n];
			if (dcmp((b-a)*(c-a)) >= 0) ret.push_back(c);
			if (dcmp((b-a)*(c-d)) != 0) {
				Point t;
				getIntersection(a, b-a, c, d-c, t);
				if (onSegment(t, c, d))
					ret.push_back(t);
			}
		}
		return ret;
	}

	int halfPlaneIntersection(DirLine* li, int n, Point* poly) {
		sort(li, li + n);

		int first, last;
		Point* p = new Point[n];
		DirLine* q = new DirLine[n];
		q[first=last=0] = li[0];

		for (int i = 1; i < n; i++) {
			while (first < last && !onLeft(li[i], p[last-1])) last--;
			while (first < last && !onLeft(li[i], p[first])) first++;
			q[++last] = li[i];

			if (dcmp(q[last].v * q[last-1].v) == 0) {
				last--;
				if (onLeft(q[last], li[i].p)) q[last] = li[i];
			}

			if (first < last)
				getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);
		}

		while (first < last && !onLeft(q[first], p[last-1])) last--;
		if (last - first <= 1) { delete [] p; delete [] q; return 0; }
		getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);

		int m = 0;
		for (int i = first; i <= last; i++) poly[m++] = p[i];
		delete [] p; delete [] q;
		return m;
	}

	Polygon simplify (const Polygon& poly) {
		Polygon ret;
		int n = poly.size();
		for (int i = 0; i < n; i++) {
			Point a = poly[i];
			Point b = poly[(i+1)%n];
			Point c = poly[(i+2)%n];
			if (dcmp((b-a)*(c-b)) != 0 && (ret.size() == 0 || b != ret[ret.size()-1]))
				ret.push_back(b);
		}
		return ret;
	}
};

namespace Circular {
	using namespace Linear;
	using namespace Vectorial;
	using namespace Triangular;

	int getLineCircleIntersection (Point p, Point q, Circle O, double& t1, double& t2, vector<Point>& sol) {
		Vector v = q - p;
		//sol.clear();
		double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
		double e = a*a+c*c, f = 2*(a*b+c*d), g = b*b+d*d-O.r*O.r;
		double delta = f*f - 4*e*g;
		if (dcmp(delta) < 0) return 0;
		if (dcmp(delta) == 0) {
			t1 = t2 = -f / (2 * e);
			sol.push_back(p + v * t1);
			return 1;
		}

		t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(p + v * t1);
		t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(p + v * t2);
		return 2;
	}

	int getCircleCircleIntersection (Circle c1, Circle c2, vector<Point>& sol) {
		double d = getLength(c1.o - c2.o);

		if (dcmp(d) == 0) {
			if (dcmp(c1.r - c2.r) == 0) return -1;
			return 0;
		}

		if (dcmp(c1.r + c2.r - d) < 0) return 0;
		if (dcmp(fabs(c1.r-c2.r) - d) > 0) return 0;

		double a = getAngle(c2.o - c1.o);
		double da = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (2*c1.r*d));

		Point p1 = c1.point(a-da), p2 = c1.point(a+da);

		sol.push_back(p1);
		if (p1 == p2) return 1;
		sol.push_back(p2);
		return 2;
	}

	int getTangents (Point p, Circle o, Vector* v) {
		Vector u = o.o - p;
		double d = getLength(u);
		if (d < o.r) return 0;
		else if (dcmp(d - o.r) == 0) {
			v[0] = rotate(u, pi / 2);
			return 1;
		} else {
			double ang = asin(o.r / d);
			v[0] = rotate(u, -ang);
			v[1] = rotate(u, ang);
			return 2;
		}
	}

	int getTangents (Circle c1, Circle c2, Point* a, Point* b) {
		int cnt = 0;
		if (c1.r < c2.r) { swap(c1, c2); swap(a, b); }
		//double d2 = getLength(c1.o - c2.o); d2 = d2 * d2;
		double x1 = c1.o.x-c2.o.x, y1 = c1.o.y-c2.o.y;
		double d2 = x1 * x1 + y1 * y1;
		double rdif = c1.r - c2.r, rsum = c1.r + c2.r;
		if (d2 < rdif * rdif) return 0;
		if (dcmp(d2) == 0 && dcmp(c1.r - c2.r) == 0) return -1;

		double base = atan2(y1,x1);
		if (dcmp(d2 - rdif * rdif) == 0) {
			a[cnt] = c1.point(base); b[cnt] = c2.point(base); cnt++;
			return cnt;
		}

		double ang = acos( (c1.r - c2.r) / sqrt(d2) );
		a[cnt] = c1.point(base+ang); b[cnt] = c2.point(base+ang); cnt++;
		a[cnt] = c1.point(base-ang); b[cnt] = c2.point(base-ang); cnt++;

		if (dcmp(d2 - rsum * rsum) == 0) {
			a[cnt] = c1.point(base); b[cnt] = c2.point(pi + base); cnt++;
		} else if (d2 > rsum * rsum) {
			double ang = acos( (c1.r + c2.r) / sqrt(d2) );
			a[cnt] = c1.point(base+ang); b[cnt] = c2.point(pi + base+ang); cnt++;
			a[cnt] = c1.point(base-ang); b[cnt] = c2.point(pi + base-ang); cnt++;
		}
		return cnt;
	}

	Circle CircumscribedCircle(Point p1, Point p2, Point p3) {  
		double Bx = p2.x - p1.x, By = p2.y - p1.y;  
		double Cx = p3.x - p1.x, Cy = p3.y - p1.y;  
		double D = 2 * (Bx * Cy - By * Cx);  
		double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;  
		double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;  
		Point p = Point(cx, cy);  
		return Circle(p, getLength(p1 - p));  
	}

	Circle InscribedCircle(Point p1, Point p2, Point p3) {  
		double a = getLength(p2 - p3);  
		double b = getLength(p3 - p1);  
		double c = getLength(p1 - p2);  
		Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);  
		return Circle(p, getDistanceToLine(p, p1, p2));  
	} 

	double getPublicAreaToTriangle (Circle O, Point a, Point b) {
		if (dcmp((a-O.o)*(b-O.o)) == 0) return 0;
		int sig = 1;
		double da = getPLength(O.o-a), db = getPLength(O.o-b);
		if (dcmp(da-db) > 0) {
			swap(da, db);
			swap(a, b);
			sig = -1;
		}

		double t1, t2;
		vector<Point> sol;
		int n = getLineCircleIntersection(a, b, O, t1, t2, sol);

		if (dcmp(da-O.r*O.r) <= 0) {
			if (dcmp(db-O.r*O.r) <= 0)	return getDirArea(O.o, a, b) * sig;

			int k = 0;
			if (getPLength(sol[0]-b) > getPLength(sol[1]-b)) k = 1;

			double ret = getArea(O.o, a, sol[k]) + O.getArea(getAngle(sol[k]-O.o, b-O.o));
			double tmp = (a-O.o)*(b-O.o);
			return ret * sig * dcmp(tmp);
		}

		double d = getDistanceToSegment(O.o, a, b);
		if (dcmp(d-O.r) >= 0) {
			double ret = O.getArea(getAngle(a-O.o, b-O.o));
			double tmp = (a-O.o)*(b-O.o);
			return ret * sig * dcmp(tmp);
		}

		double k1 = O.r / getLength(a - O.o), k2 = O.r / getLength(b - O.o);
		Point p = O.o + (a - O.o) * k1, q = O.o + (b - O.o) * k2;
		double ret1 = O.getArea(getAngle(p-O.o, q-O.o));
		double ret2 = O.getArea(getAngle(sol[0]-O.o, sol[1]-O.o)) - getArea(O.o, sol[0], sol[1]);
		double ret = (ret1 - ret2), tmp = (a-O.o)*(b-O.o);
		return ret * sig * dcmp(tmp);
	}

	double getPublicAreaToPolygon (Circle O, Point* p, int n) {
		if (dcmp(O.r) == 0) return 0;
		double area = 0;
		for (int i = 0; i < n; i++) {
			int u = (i + 1) % n;
			area += getPublicAreaToTriangle(O, p[i], p[u]);
		}
		return fabs(area);
	}
};

using namespace Vectorial;
using namespace Polygonal;
using namespace Circular;

const int maxn = 1005;

int nc, np, no;
Circle C[maxn];
Polygon poly[maxn];
Point P[maxn * maxn], ch[maxn * maxn];

void getPointTangents(Point p, Circle c, Point& a, Point& b) {
	double k = 2 * (c.r*c.r + c.o.x*p.x + c.o.y*p.y - c.o.x*c.o.x - c.o.y*c.o.y);
	double s = 2 * (p.x-c.o.x), t = 2 * (p.y - c.o.y);

	if (dcmp(t) == 0) {
		a.x = b.x = k / s;
		double tmp = sqrt(c.r * c.r - (c.o.x-a.x)*(c.o.x-a.x));
		a.y = c.o.y + tmp;
		b.y = c.o.y - tmp;
	} else {
		double x = c.o.y - k/t;
		double A = 1 + (s/t) * (s/t);
		double B = 2 * (x*s/t - c.o.x);
		double C = c.o.x * c.o.x + x * x - c.r * c.r;
		double tmp = sqrt(B * B - 4 * A * C);
		a.x = (tmp - B) / 2 / A;
		b.x = (-tmp - B) / 2 / A;
		a.y = (k - s * a.x) / t;
		b.y = (k - s * b.x) / t;
	}
}

void getCircleTangents (Circle c1, Circle c2, Point& a, Point& b) {
	double x0 = c2.o.x - c1.o.x, y0 = c2.o.y - c1.o.y, cs, sn, rdis = c1.r - c2.r;

	if (dcmp(y0) == 0) {
		cs = rdis / x0;
		sn = sqrt(1 - cs * cs);
		a = Point(c1.r * cs + c1.o.x, c1.r * sn + c1.o.y);
		b = Point(c1.r * cs + c1.o.x, c1.r * (-sn) + c1.o.y);
	} else {
		double A = (x0/y0)*(x0/y0) + 1;
		double B = -2 * x0 * rdis / y0 / y0;
		double C = (rdis / y0) * (rdis / y0) - 1;
		double delta = sqrt(B * B - 4 * A * C);
		cs = (-B + delta) / 2 / A;
		sn = (rdis - x0 * cs) / y0;
		a = Point(c1.r * cs + c1.o.x, c1.r * sn + c1.o.y);

		cs = (-B - delta) / 2 / A;
		sn = (rdis - x0 * cs) / y0;
		b = Point(c1.r * cs + c1.o.x, c1.r * sn + c1.o.y);
	}
}

void solve (Point t) {
	Point a, b;
	P[np++] = Point(t.x, t.y, 0);;

	for (int i = 0; i < nc; i++) {
//		if (dcmp(getLength(t-C[i].o) - C[i].r) < 0) continue;
		getPointTangents(t, C[i], a, b);
		P[np++] = Point(a.x, a.y, i+1);
		P[np++] = Point(b.x, b.y, i+1);
	}
}

const double s3 = sqrt(3) / 2.0;

void init () {
	no = nc = np = 0;
	int k, n;
	Point t, a, b;
	char s[5];

	scanf("%d", &n);
	scanf("%s", s);

	for (int i = 0; i < n; i++) {
		if (s[i] == 'C') {
			C[nc++] = Circle(Point(i + 0.5, 0.5), 0.5);
		} else if (s[i] == 'T') {
			poly[no].push_back(Point(i, 0));
			poly[no].push_back(Point(i + 1, 0));
			poly[no++].push_back(Point(i + 0.5, s3));
		} else {
			poly[no].push_back(Point(i, 0));
			poly[no].push_back(Point(i + 1, 0));
			poly[no].push_back(Point(i + 1, 1));
			poly[no++].push_back(Point(i, 1));
		}
	}

	for (int i = 0; i < nc; i++) {
		for (int j = 0; j < nc; j++) if (i != j) {
			getCircleTangents (C[i], C[j], a, b);
			P[np++] = Point(a.x, a.y, i+1);
			P[np++] = Point(b.x, b.y, i+1);
		}
	}

	for (int i = 0; i < no; i++) {
		for (int j = 0; j < poly[i].size(); j++)
			solve(poly[i][j]);
	}
}

double getAngle(Point a, Point b, Point c) {
	double lc = getLength(a-b);
	double lb = getLength(a-c);
	double la = getLength(b-c);
	return acos((la * la + lb * lb - lc * lc) / (2 * la * lb));
}

double get(Point a, Point b) {
	if (a.be != 0 && a.be == b.be) {
		int i = a.be-1;
		double rad = getAngle(a-C[i].o, b-C[i].o);
		if (dcmp((b-a)*(C[i].o-a)) < 0) rad = 2 * pi - rad;
		return rad * C[i].r;
	}
	return getLength(a-b);
}

int main () {
	init ();
	if (np == 0 && nc == 1) {
		printf("%.9lf\n", 2 * pi * C[0].r);
		return 0;
	}

	sort(P, P + np);
	np = unique(P, P + np) - P;
	int n = getConvexHull(P, np, ch);

	ch[n] = ch[0];
	double ans = 0;
	for (int i = 0; i < n; i++)
		ans += get(ch[i], ch[i+1]);
	printf("%.9lf\n", ans);
	return 0;
}