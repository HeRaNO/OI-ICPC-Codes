#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct A
{
	int l,r,ans,siz,lz,rz;
	A(){}
	A(int _l,int _r,int _x):
		l(_l),r(_r),lz(_x),rz(_x),ans(0),siz(1){}
	A operator + (const A &a)const{
		A res;res.l=l;res.r=a.r;res.siz=siz+a.siz;
		res.lz=lz;res.rz=a.rz;res.ans=ans+a.ans;
		if ((r==1&&a.l==-1)||(r==-1&&a.l==1))
		{
			if (lz==siz) res.lz+=a.lz;
			if (a.rz==a.siz) res.rz+=rz;
			res.ans-=(rz>>1)+(a.lz>>1)-((rz+a.lz)>>1);
		}
		return res;
	}
};

A x[1<<19];
int n,m,a[MAXN],p[MAXN],resp;
vector <int> v[MAXN];

inline void modify(int u,int p,int v,int pl,int pr)
{
	if (pl+1==pr)
	{
		x[u]=A(v,v,abs(v));
		return ;
	}
	int m=pl+pr>>1;
	if (p<m) modify(u<<1,p,v,pl,m);
	else modify(u<<1|1,p,v,m,pr);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		modify(1,i,a[i]>1,0,n);
		v[a[i]].push_back(i);
	}
	for (int i=1;i<=m;i++)
	{
		if (!v[i].size()) printf("-1");
		else
		{
			for (auto j:v[i]) modify(1,j,0,0,n);
			A res=x[1];
			if ((res.l==1&&res.r==-1)||(res.l==-1&&res.r==1))
				res.ans-=(res.lz>>1)+(res.rz>>1)-((res.lz+res.rz)>>1);
			printf("%d",n-v[i].size()+res.ans);
			for (auto j:v[i]) modify(1,j,-1,0,n);
		}
		printf("%c",i==m?'\n':' ');
	}
	return 0;
}
