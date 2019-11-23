#include <bits/stdc++.h>
using namespace std;

int T,n;
char s[5][5],p[10],opt[5];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=0;i<3;i++) scanf("%s",s[i]);
		while (n--)
		{
			int x,y;
			scanf("%s",opt);
			if (opt[0]=='1'){x=0;y=0;}
			else if (opt[0]=='2'){x=0;y=1;}
			else if (opt[0]=='3'){x=1;y=0;}
			else{x=1;y=1;}
			p[0]=s[x][y];p[1]=s[x][y+1];p[2]=s[x+1][y+1];p[3]=s[x+1][y];
			if (opt[1]=='C')
			{
				s[x][y+1]=p[0];s[x+1][y+1]=p[1];
				s[x+1][y]=p[2];s[x][y]=p[3];
			}
			else
			{
				s[x+1][y]=p[0];s[x][y]=p[1];
				s[x][y+1]=p[2];s[x+1][y+1]=p[3];
			}
		}
		for (int i=0;i<3;i++) puts(s[i]);
	}	
	return 0;
}