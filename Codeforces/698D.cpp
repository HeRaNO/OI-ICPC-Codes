#include <bits/stdc++.h>
#define MAXN 1005
#define MAXK 8
using namespace std;

struct Point
{
	int x,y;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	Point operator - (const Point &p)const{
		return Point(x-p.x,y-p.y);
	}
}O;

long long cross(Point a,Point b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
long long dot(Point a,Point b){return 1LL*a.x*b.x+1LL*a.y*b.y;}

int n,m,s[MAXK],pre[MAXK][MAXN][MAXK],q[MAXK],cnt;
bool ans[MAXN],vis[MAXN];
Point p[MAXN],a[MAXK];

int main()
{
	scanf("%d %d",&m,&n);
	for (int i=1;i<=m;i++) scanf("%d %d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++) scanf("%d %d",&p[i].x,&p[i].y);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n&&pre[i][j][0]<m;k++)
				if (!cross(p[j]-a[i],p[k]-a[i])&&dot(a[i]-p[k],p[j]-p[k])<0)
					pre[i][j][++pre[i][j][0]]=k;
	for (int i=1;i<=m;i++) s[i]=i;
	do {
		for (int i=1;i<=n;i++)
		{
			int t;vis[q[t=1]=i]=true;
			for (int j=1;j<=t&&t<=m;j++)
				for (int x=1,y;x<=pre[s[j]][q[j]][0];x++)
					if (!vis[y=pre[s[j]][q[j]][x]]) vis[q[++t]=y]=true;
			if (t<=m) ans[i]=true;
			for (int j=1;j<=t;j++) vis[q[j]]=false;
		}
	} while (next_permutation(s+1,s+m+1));
	for (int i=1;i<=n;i++) ans[i]?++cnt:0;
	printf("%d\n",cnt);
	return 0;
}
/*
2 5
0 -4
4 -4
0 0
0 4
1 2
2 0
0 2
Ans: 4
*/