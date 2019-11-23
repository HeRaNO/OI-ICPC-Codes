#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,m,k,t,now,p,q,cnt;
char s[MAXN][MAXN],cr[MAXN],ans[MAXN][MAXN];

int main()
{
	scanf("%d",&T);
	for (int i=0;i<=9;i++) cr[i]=i+'0';
	for (int i=10;i<=35;i++) cr[i]=i-10+'A';
	for (int i=36;i<=61;i++) cr[i]=i-36+'a';
	while (T--)
	{
		scanf("%d %d %d",&n,&m,&k);cnt=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);ans[i][m+1]='\0';
			for (int j=1;j<=m;j++) if (s[i][j]=='R') ++cnt;
		}
		p=cnt/k;q=cnt%k;t=0;now=1;
		for (int i=1;i<=n;i++)
			if (i&1)
			{
				for (int j=1;j<=m;j++)
				{
					ans[i][j]=cr[min(now-1,k-1)];
					if (s[i][j]=='R')
					{
						++t;
						if (now<=q)
						{
							if (t==p+1){++now;t=0;}
						}
						else if (t==p){++now;t=0;}
					}
				}
			}
			else
			{
				for (int j=m;j;j--)
				{
					ans[i][j]=cr[min(now-1,k-1)];
					if (s[i][j]=='R')
					{
						++t;
						if (now<=q)
						{
							if (t==p+1){++now;t=0;}
						}
						else if (t==p){++now;t=0;}
					}
				}
			}
		for (int i=1;i<=n;i++) puts(ans[i]+1);
	}
	return 0;
}