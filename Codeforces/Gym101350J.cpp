#include <bits/stdc++.h>
using namespace std;

const double cov=acos(-1.0)/180.0;

int n,l,a;
long long x,mx,mn;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&l,&a);
		int p=l*l;
		double q=(double)p/2.0;
		double alpha=(double)a*cov;
		printf("%.6lf\n",q*(alpha-sin(alpha)));
	}
	return 0;
}