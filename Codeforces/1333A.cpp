#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,m;
char ans[MAXN][MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		if ((n&1)&&(m&1))
		{
			for (int i=1;i<=n;i++,puts(""))
				for (int j=1;j<=m;j++)
				{
					if (!((i+j)&1)) putchar('B');
					else putchar('W');
				}
		}
		else
		{
			if(!(n&1))
			{
				for (int i=1;i<=n;i++)
					for (int j=1;j<=m;j++)
						ans[i][j]=i&1?'B':'W';
				ans[2][1]='B';
			}
			else
			{
				for (int i=1;i<=n;i++)
					for (int j=1;j<=m;j++)
						ans[i][j]=j&1?'B':'W';
				ans[1][2]='B';
			}
			for (int i=1;i<=n;i++,puts(""))
				for (int j=1;j<=m;j++)
					putchar(ans[i][j]);
		}
	}
	return 0;
}
