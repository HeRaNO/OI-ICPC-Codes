#include <bits/stdc++.h>
using namespace std;

double ans,x;
char u[10];
int n;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%s",&x,u);
		if (u[0]=='J') ans+=x;
		else ans+=x*380000.00;
	}
	printf("%.8lf\n",ans);
	return 0;
}
