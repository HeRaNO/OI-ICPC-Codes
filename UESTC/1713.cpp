#include <cmath>
#include <cstdio>
using namespace std;

const double PI = acos(-1.0);
int T, x, y, r1, a, b, r2, dis;
double A, B, S;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d %d %d", &x, &y, &r1, &a, &b, &r2);
		dis = (x - a) * (x - a) + (y - b) * (y - b);
		if ((r1 - r2) * (r1 - r2) >= dis)
		{
			int r = r1 < r2 ? r1 : r2;
			printf("%lf\n", PI * r * r);
		}
		else if (dis >= (r1 + r2) * (r1 + r2)) puts("0.000000");
		else
		{
			A = acos((r1 * r1 + dis - r2 * r2) / (2 * r1 * sqrt(dis)));
			B = acos((r2 * r2 + dis - r1 * r1) / (2 * r2 * sqrt(dis)));
			S = r1 * r1 * A + r2 * r2 * B;
			S -= r1 * sqrt(dis) * sin(A);
			printf("%lf\n", S);
		}
	}
	return 0;
}
