#include <bits/stdc++.h>
using namespace std;

double h,l;

int main()
{
	scanf("%lf %lf",&h,&l);
	printf("%.8lf\n",(l*l-h*h)/(2.0*h));
	return 0;
}