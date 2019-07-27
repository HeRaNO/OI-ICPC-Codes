#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct score
{
	int p,x;
	score(){}
	score(int _p,int _x):p(_p),x(_x){}
	bool operator < (const score &a)const{
		return p==a.p?x<a.x:p<a.p;
	}
};

score a[MAXN*3];
int n,m,k,x,p,b,c,ans,cnt,pt,vis[MAXN];

int main()
{
	while (~scanf("%d",&n))
	{
		m=0;memset(vis,0,sizeof vis);ans=~(1<<31);cnt=k=0;pt=1;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&p);
			if (!p) continue;
			scanf("%d %d",&b,&c);
			a[++m]=score(x,i);
			if (b) a[++m]=score(x+b,i);
			if (c) a[++m]=score(x-c,i);
			++k;
		}
		sort(a+1,a+m+1);
		vis[a[1].x]=1;cnt=1;
		for (int i=1;i<=m;i++)
		{
			while (pt<m&&cnt<k)
			{
				++pt;
				if (!vis[a[pt].x]) ++cnt;
				++vis[a[pt].x];
			}
			if (cnt==k) ans=min(ans,a[pt].p-a[i].p);
			if (vis[a[i].x]==1) --cnt;
			--vis[a[i].x];
		}
		printf("%d\n",k?ans:0);
	}
	return 0;
}