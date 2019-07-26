#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);

int a,b,T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&a,&b);
		printf("%lf\n",a*pi+2.0*(double)b-0.0000005);
	}
	return 0;
}