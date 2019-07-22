#include <bits/stdc++.h>
using namespace std;

int ans,r,x,y;

int score(int x,int y)
{
	if (x*x+y*y<=r*r) return 10;
	if (x*x+y*y<=4*r*r) return 9;
	if (x*x+y*y<=9*r*r) return 8;
	if (x*x+y*y<=16*r*r) return 7;
	if (x*x+y*y<=25*r*r) return 6;
	if (x*x+y*y<=36*r*r) return 5;
	if (x*x+y*y<=49*r*r) return 4;
	if (x*x+y*y<=64*r*r) return 3;
	if (x*x+y*y<=81*r*r) return 2;
	if (x*x+y*y<=100*r*r) return 1;
	return 0;
}

int main()
{
	scanf("%d",&r);
	for (int i=1;i<=3;i++)
	{
		scanf("%d %d",&x,&y);
		ans+=score(x,y);
	}
	printf("%d\n",ans);
	return 0;
}