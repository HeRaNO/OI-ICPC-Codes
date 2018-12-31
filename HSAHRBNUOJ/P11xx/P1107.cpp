#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c, p, s;
	scanf("%d %d %d", &a, &b, &c);
	p = (a + b + c) / 2.0;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("s=%0.2f\n", s);
	return 0;
}
