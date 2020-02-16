#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int MAXN=1e7+10,MAXM=4e7+10;
const int INF=~(1<<31),MOD=1e9+7;
const ll llINF=((1ll<<61));

int n;
char a[105][105],b[105][105],c[105][105];
int dd[4][4]={{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
	while(scanf("%d",&n)==1)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
		int nowx=1,nowy=1,t=0;
		while(1)
		{
			t++;
			if(t>n*n)break;
			b[(t-1)/n+1][(t-1)%n+1]=a[nowy][nowx];
			if((nowx+nowy)&1)
			{
				if(nowy==n) nowx++;
				else if(nowx==1) nowy++;
				else
				{
					nowx--;
					nowy++;
				}
			}
			else
			{
				if(nowx==n) nowy++;
				else if(nowy==1) nowx++;
				else
				{
					nowy--;
					nowx++;
				}
			}
		}
		nowx=nowy=1;t=0;
		int nowdir=0,u=1,d=n,l=1,r=n;
		for(int i=1;i<=n*n;i++)
		{
			t++;
			c[nowx][nowy]=b[(t-1)/n+1][(t-1)%n+1];
			int sx=nowx+dd[nowdir][0];
			int sy=nowy+dd[nowdir][1];
			if(sy>r||sy<l||sx>d||sx<u)
			{
				if(sy<l)d--;
				else if(sy>r)u++;
				else if(sx>d)r--;
				else if(sx<u)l++;
				nowdir=(nowdir+1)%4;
				sx=nowx+dd[nowdir][0],sy=nowy+dd[nowdir][1];
			}
			nowx=sx;
			nowy=sy;
		}
		for(int i=1;i<=n;i++)
			printf("%s\n",c[i]+1);
	}
	return 0;
}