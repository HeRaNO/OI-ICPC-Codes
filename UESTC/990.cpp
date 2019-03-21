#include <bits/stdc++.h>
using namespace std;

int T,a,b,c;
double p,x,y,z,s;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&a,&b,&c);
		x=a;y=b;z=c;
		if (x>y) swap(x,y);if (x>z) swap(x,z);if (y>z) swap(y,z);
		if (x+y<z) printf("(%d,%d,%d) can't construct a triangle!\n",a,b,c);
		else
		{
			p=(x+y+z)/2.0;
			s=sqrt(p*(p-x)*(p-y)*(p-z));
			printf("S(%d,%d,%d)=%.2lf\n",a,b,c,s);
		}
	}
	return 0;
}
