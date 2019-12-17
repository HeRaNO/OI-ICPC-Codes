#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int v,a,b,s;
		scanf("%d %d.%2d %d",&v,&a,&b,&s);
		a=a*100+b;v*=100;
		printf("%.2lf %s\n",(double)v/a,v*v>200*a*s?"No":"Yes");
	}
	return 0;
}