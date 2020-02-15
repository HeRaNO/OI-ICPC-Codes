#include <bits/stdc++.h>
using namespace std;

int T,x,y,a,b;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d",&x,&y,&a,&b);
		if ((y-x)%(a+b)) puts("-1");
		else printf("%d\n",(y-x)/(a+b));
	}
	return 0;
}