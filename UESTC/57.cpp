#include <bits/stdc++.h>
using namespace std;

int a[4][4],b[4][4],c[4][4],T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
				scanf("%d",&b[i][j]);
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
			{
				c[i][j]=0;
				for (int k=1;k<=3;k++) c[i][j]+=a[i][k]*b[k][j];
			}
		for (int i=1;i<=3;i++)
		{
			for (int j=1;j<=3;j++) printf("%d ",c[i][j]);
			puts("");
		}
		puts("");
	}
	return 0;
}