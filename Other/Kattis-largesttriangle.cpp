#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

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
	long long operator * (const point &p)const{
		return 1LL*x*p.y-1LL*y*p.x;
	}
};

int n,m;
point p[MAXN],ch[MAXN];
long long ans;

int ConvexHull(point *p,int n)
{
	sort(p,p+n);
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

inline bool OK(point a,point b,point c,point d)
{
	return abs((b-a)*(c-a))<abs((b-a)*(d-a));
}

inline int fadd(int x){return x==m-1?0:x+1;}

inline void goNext(int &x){x=fadd(x);return ;}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
	m=ConvexHull(p,n);
	for (int i=0;i<m;i++)
	{
		int x=fadd(i);
		for (int j=x;j!=i;goNext(j))
		{
			while (x!=j&&OK(ch[i],ch[j],ch[x],ch[x+1])) goNext(x);
			long long now=abs((ch[x]-ch[i])*(ch[j]-ch[i]));
			if (now>ans) ans=now;
		}
	}
	if (ans&1) printf("%lld.5\n",ans>>1);
	else printf("%lld\n",ans>>1);
	return 0;
}