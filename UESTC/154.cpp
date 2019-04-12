#include <bits/stdc++.h>
using namespace std;

int T,n;
double l,v,p;
char s[3],d[3];

inline void max(double &a,double b){if (a<b) a=b;return ;}

int main()
{
	while (true)
	{
		scanf("%d %lf %lf",&n,&l,&v);
		if (!n&&l==0.0&&v==0.0) break;
		double t=0.0,dis=0.0;
		for (int i=1;i<=n;i++)
		{
			scanf("%lf %s %s",&p,s,d);
			if (d[0]=='W') max(t,p/v),dis+=p;
			else max(t,(l-p)/v),dis+=(l-p);
		}
		printf("%.2lf %.2lf\n",t,dis);
	}
	return 0;
}
