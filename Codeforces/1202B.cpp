#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000005

int n;
char s[MAXN];
long long ans[15][15];
int a[15];

inline void calc(int x,int y)
{
	long long now=0;
	memset(a,0x3f,sizeof a);
	int INF=a[0];
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
		{
			if(i==0&&j==0) continue;
			a[(x*i+y*j)%10]=min(a[(x*i+y*j)%10],i+j);
		}
	for(int i=1;i<n;i++)
	{
		int d=(s[i+1]-s[i]+10)%10;
		now+=a[d];
	}
	ans[x][y]=now;
	if(ans[x][y]>=INF) ans[x][y]=-1;
	return ;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			calc(i,j);
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			if(ans[i][j]!=-1)
				printf("%lld%c",ans[i][j]-n+1,j==9?'\n':' ');
			else
				printf("-1%c",j==9?'\n':' ');
		}
	return 0;
}