#include <bits/stdc++.h>
using namespace std;

int T,r,c,w,h;
char a[65][65];

int main()
{
	scanf("%d",&T);
	for (int kas=1;kas<=T;kas++)
	{
		memset(a,0,sizeof a);
		scanf("%d %d %d %d",&r,&c,&w,&h);
		for (int i=1;i<=r*h+r+1;i+=h+1)
		{
			for (int j=1;j<=c*w+c+1;j+=w+1) a[i][j]='+';
			for (int j=1;j<=c*w+c+1;j++) if (!a[i][j]) a[i][j]='-';
		}
		for (int i=1;i<=c*w+c+1;i+=w+1)
			for (int j=1;j<=r*h+r+1;j++)
				if (!a[j][i]) a[j][i]='|';
		printf("Case #%d:\n", kas);
		for (int i=1;i<=r*h+r+1;i++)
		{
			for (int j=1;j<=c*w+c+1;j++)
				putchar(a[i][j]?a[i][j]:'*');
			putchar('\n');
		}
	}
	return 0;
}