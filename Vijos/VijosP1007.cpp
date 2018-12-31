#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	double x1, y1, x2, y2;
	double x, y;
	double r;
	double sum = 0.0;
	cin >> n >> r;
	cin >> x1 >> y1;
	x = x1;
	y = y1;
	for (int i = 1; i < n; i++)
	{
		cin >> x2 >> y2;
		sum += sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
		x = x2;
		y = y2;
	}
	sum += sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
	sum += 3.14159265359 * 2 * r;
	printf("%.2f\n", sum);
	return 0;
}
