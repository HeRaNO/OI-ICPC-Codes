//Code By HeRaNO
#include<stdio.h>
#include<math.h>
float getlength(float x1, float y1, float x2, float y2)
{
	return sqrt(fabs((x1 - x2) * (x1 - x2)) + fabs((y1 - y2) * (y1 - y2)));
}
int main()
{
	float a, b, c, r, s;
	float x1, x2, x3, y1, y2, y3;
	scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
	a = getlength(x1, y1, x2, y2);
	b = getlength(x1, y1, x3, y3);
	c = getlength(x2, y2, x3, y3);
	r = (a + b + c) / 2;
	s = sqrt(r * (r - a) * (r - b) * (r - c));
	printf("%0.2f", s);
	return 0;
}

