#include <cmath>
#include <cstdio>
using namespace std;

double a, b, c, delta;

inline int read()
{
	int x = 0;
	bool f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = 0;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return f ? x : -x;
}

int main()
{
	a = read();
	b = read();
	c = read();
	if (a < 0)
	{
		a = -a;
		b = -b;
		c = -c;
	}
	delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		printf("%.8lf %.8lf\n", -b / (2.0 * a), -sqrt(-delta) / (2.0 * a));
		printf("%.8lf %.8lf\n", -b / (2.0 * a), sqrt(-delta) / (2.0 * a));
	}
	else
	{
		printf("%.8lf 0\n", (-b - sqrt(delta)) / (2.0 * a));
		printf("%.8lf 0\n", (-b + sqrt(delta)) / (2.0 * a));
	}
	return 0;
}
