#include <bits/stdc++.h>
#define MAXN 15
using namespace std;

const double pi=acos(-1.0);
const double cov=pi/180.0;

int n,d;
int a[MAXN];

int main()
{
	while (~scanf("%d %d",&n,&d))
	{
		double s=0;
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		for (int i=0;i<n;i++) s+=0.5*d*d*sin(a[i]*cov);
		printf("%.3lf\n",s);
	}
	return 0;
}