#include <cmath>
#include <cstdio>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-2;

struct Point
{
	double x, y;
	Point() {}
	Point(double _x, double _y): x(_x), y(_y) {}
	double dis(const Point &a) const
	{
		return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
	}
};

Point A, B, C, P;
double a, b, c;

inline bool ck(double x)
{
	x /= pi;
	return fabs(x - int(x + 0.5)) <= eps;
}

inline double Angle(Point A, Point B, Point C)
{
	double a = B.dis(C), b = A.dis(C), c = A.dis(B);
	double m = (a * a + c * c - b * b) / (2.0 * a * c);
	return acos(m);
}

int main()
{
	scanf("%lf%lf", &A.x, &A.y);
	scanf("%lf%lf", &B.x, &B.y);
	scanf("%lf%lf", &C.x, &C.y);
	a = Angle(B, A, C);
	b = Angle(A, B, C);
	c = Angle(A, C, B);
	for (int i = 3; i <= 100; i++)
		if (ck(a * i) && ck(b * i) && ck(c * i))
		{
			printf("%d\n", i);
			return 0;
		}
	return 0;
}
