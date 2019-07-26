#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);

char n[1000000];
double a[200000];

int main()
{
	for (int i=1;i<=110292;i++) a[i]=1.0/(double)(1LL*i*i);
	for (int i=1;i<=110292;i++) a[i]+=a[i-1];
	while (~scanf("%s",n))
	{
		if (strlen(n)>6) printf("%.5lf\n",pi*pi/6.0);
		else
		{
			int x=0,p=strlen(n);
			for (int i=0;i<p;i++) x=x*10+n[i]-'0';
			if (x>=110292) printf("%.5lf\n",pi*pi/6.0);
			else printf("%.5lf\n",a[x]);
		}
	}
	return 0;
}