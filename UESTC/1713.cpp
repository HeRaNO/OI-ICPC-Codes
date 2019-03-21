#include <cmath>
#include <cstdio>
using namespace std;

const double PI = acos(-1.0);
int T;
double x1, y11, r1, x2, y2, r2;
double dis, A, B, S;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y11, &r1, &x2, &y2, &r2);
		dis = sqrt((x1 - x2) * (x1 - x2) + (y11 - y2) * (y11 - y2));
		if (fabs(r1 - r2) >= dis)
		{
			double r = r1 < r2 ? r1 : r2;
			printf("%.6lf\n", PI * r * r);
		}
		else if (dis >= r1 + r2) printf("%.6lf\n", 0.0);
		else
		{
			S = PI * (r1 * r1 + r2 * r2);
			A = acos((r1 * r1 + dis * dis - r2 * r2) / (2 * r1 * dis));
			B = acos((r2 * r2 + dis * dis - r1 * r1) / (2 * r2 * dis));
			S -= r1 * r1 * A + r2 * r2 * B;
			S += r1 * dis * sin(A);
			S -= PI * (r1 * r1 + r2 * r2);
			printf("%.6lf\n", -S);
		}
	}
	return 0;
}
