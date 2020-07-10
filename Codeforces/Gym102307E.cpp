#include <bits/stdc++.h>
#define MAXN 100005
#define RANGE 0,100001
using namespace std;

struct E
{
	int r,o;
	bool operator < (const E &a)const{
		if (o==a.o) return r<a.r;
		return o<a.o;
	}
};

E a[MAXN<<1];
int n,d,x,y,alpha,ans;
int c[1<<18],lazy[1<<18];

inline void add(int u,int v)
{
	c[u]+=v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	add(u<<1,lazy[u]);add(u<<1|1,lazy[u]);lazy[u]=0;
	return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr){add(u,v);return ;}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	c[u]=max(c[u<<1],c[u<<1|1]);
	return ;
}

int main()
{
	scanf("%d %d %d.%d",&n,&d,&x,&y);alpha=x*100+y;
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d.%d",&a[i].r,&x,&y);
		a[i].o=x*100+y;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		a[i+n]=a[i];
		a[i+n].o+=36000;
	}
	n<<=1;
	for (int r=1,l=1,i;r<=n;)
	{
		for (i=r;i<=n;i++)
		{
			if (a[i].o==a[r].o) modify(1,max(0,a[i].r-d),a[i].r+1,1,RANGE);
			else break;
		}
		while (l<r&&a[r].o-a[l].o>alpha)
		{
			modify(1,max(0,a[l].r-d),a[l].r+1,-1,RANGE);
			++l;
		}
		ans=max(ans,c[1]);r=i;
	}
	printf("%d\n",ans);
	return 0;
}