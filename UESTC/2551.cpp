#include <bits/stdc++.h>
#define MAXN 3000
#define MAXM 4498500
using namespace std;

const int MSK=4095;

struct point
{
	int x,y;
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	point operator - (const point &p)const{
		return point(x-p.x,y-p.y);
	}
	bool operator < (const point &p)const{
		if (p.x!=x) return p.x>x;
		return p.y>y;
	}
	bool operator == (const point &p)const{
		return x==p.x&&y==p.y;
	}
	long long operator * (const point &p)const{
		return 1LL*x*p.y-1LL*y*p.x;
	}
	void norm(){
		x=-x;y=-y;return ;
	}
};

point p[MAXN],ch[MAXN];
int n,id[MAXN],a[MAXN],v[MAXM];

inline long long S(point &x,point &y,point &z){return abs((z-x)*(y-x));}
inline bool OK(point &a,point &b,point &c,point &d){return S(a,b,c)<S(a,b,d);}
inline int fadd(int x,int m){return x==m-1?0:x+1;}
inline void goNext(int &x,int m){x=fadd(x,m);return ;}

int ConvexHull(point *p,int n)
{
	int m=0;
	for (int i=0;i<n;i++)
	{
		while (m>1&&(ch[m-1]-ch[m-2])*(p[i]-ch[m-2])<=0) --m;
		ch[m++]=p[i];
	}
	int k=m;
	for (int i=n-2;~i;i--)
	{
		while (m>k&&(ch[m-1]-ch[m-2])*(p[i]-ch[m-2])<=0) --m;
		ch[m++]=p[i];
	}
	if (n>1) m--;
	return m;
}

bool cmp(int A,int B)
{
	point x=p[A&MSK]-p[A>>12],y=p[B&MSK]-p[B>>12];
	if (x.x<0) x.norm();
	if (y.x<0) y.norm();
	return y*x<0;
}

inline void getMinTri(int n)
{
	if (n<3) return puts("0"),void();
	long long ans=~(1LL<<63);
	int m=0;
	for (int i=0;i<n;i++) id[i]=a[i]=i;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			v[m++]=i<<12|j;
	sort(v,v+m,cmp);
	for (int i=0;i<m;i++)
	{
		int x=v[i]>>12,y=v[i]&MSK;
		if (id[x]>id[y]) swap(x,y);
		if (id[x]>0) ans=min(ans,S(p[a[id[x]-1]],p[x],p[y]));
		if (id[y]<n-1) ans=min(ans,S(p[a[id[y]+1]],p[x],p[y]));
		swap(id[x],id[y]);
		swap(a[id[x]],a[id[y]]);
	}
	printf("%lld\n",ans);
	return ;
}

inline void getMaxTri(int n)
{
	long long ans=0;
	int m=ConvexHull(p,n);
	if (m<3) return puts("0"),void();
	for (int i=0;i<m;i++)
	{
		int x=fadd(i,m);
		for (int j=x;j!=i;goNext(j,m))
		{
			while (x!=j&&OK(ch[i],ch[j],ch[x],ch[x+1])) goNext(x,m);
			long long now=S(ch[x],ch[i],ch[j]);
			if (now>ans) ans=now;
		}
	}
	printf("%lld\n",ans);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&p[i].x);
	for (int i=0;i<n;i++) scanf("%d",&p[i].y);
	sort(p,p+n);
	int m=unique(p,p+n)-p;
	if (m<n) puts("0");
	else getMinTri(m);
	getMaxTri(m);
	return 0;
}
