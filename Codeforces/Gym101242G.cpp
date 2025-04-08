#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

const double eps=1e-6;

struct Point
{
	double k;int p;
	Point(){}
	Point(double _,int __):k(_),p(__){}
	bool operator < (const Point &a)const{
		return k<a.k;
	}
};

Point p[MAXN<<1];
int n,l[MAXN],r[MAXN],y[MAXN],v[MAXN];
long long ans;
bool f[MAXN];

inline void check(long long x){if (ans<x) ans=x;return ;}

inline void Analyze(int X,int Y,int V)
{
	long long now=V;int t=0;check(V);
	for (int i=1;i<=n;i++)
		if (y[i]!=Y)
		{
			p[++t]=Point((double)(l[i]-X)/(y[i]-Y),i);
			p[++t]=Point((double)(r[i]-X)/(y[i]-Y),i);
			if (p[t].k>p[t-1].k) p[t].k+=eps;
			else p[t-1].k+=eps;
		}
	sort(p+1,p+t+1);
	for (int i=1;i<=t;i++)
	{
		if (f[p[i].p]^=1) now+=v[p[i].p];
		else now-=v[p[i].p];
		check(now);
	}
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&l[i],&r[i],&y[i]);
		if (l[i]>r[i]) swap(l[i],r[i]);
		v[i]=r[i]-l[i];
	}
	for (int i=1;i<=n;i++) Analyze(l[i],y[i],v[i]),Analyze(r[i],y[i],v[i]);
	printf("%lld\n",ans);
	return 0;
}
