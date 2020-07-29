#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const double eps = 1e-7;

struct point
{
	int x, y;
	point() {}
	point(int _x, int _y):
		x(_x), y(_y) {}
	point operator + (const point &p) const {
		return point(x + p.x, y + p.y);
	}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	long long operator * (const point &p) const {
		return 1LL * x * p.y - 1LL * y * p.x;
	}
};

struct segment
{
	point a,b;
	segment() {}
	segment(point _x, point _y): a(_x), b(_y) {}
};

point a[MAXN];
int w,p,x,y,u[MAXN],f[MAXN];
segment l[MAXN];
int c[MAXN];

inline bool isIntersection(point a,point b,point c,point d)
{
	if (max(a.x,b.x)<min(c.x,d.x)) return false;
	if (max(a.y,b.y)<min(c.y,d.y)) return false;
	if (max(c.x,d.x)<min(a.x,b.x)) return false;
	if (max(c.y,d.y)<min(a.y,b.y)) return false;
	long long p=(b-a)*(b-c);
	long long q=(b-a)*(b-d);
	long long r=(d-c)*(d-a);
	long long s=(d-c)*(d-b);
	return (p*q<=0)&&(r*s<=0);
}

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
bool intersect(segment i,segment j)
{
	return isIntersection(i.a,i.b,j.a,j.b);
}

bool llll[MAXN];

int main()
{
	memset(c,-1,sizeof c);
	scanf("%d %d",&w,&p);
	for (int i=1;i<=w;i++)
	{
		scanf("%d %d",&x,&y);
		a[i]=point(x,y);
	}
	for (int i=1;i<=p;i++)
	{
		scanf("%d %d %d",&u[i],&x,&y);
		l[i]=segment(a[u[i]],point(x,y));
		f[i]=i;
	}
	for (int i=1;i<=p;i++)
		for (int j=i+1;j<=p;j++)
		{
			if (u[i]==u[j]) continue;
			if (!intersect(l[i],l[j])) continue;
			int fx=getf(i),fy=getf(j);
			if (fx!=fy) f[fy]=fx;
		}
	queue<int> q;
	for(int i=1;i<=p;i++)if(getf(i)==i)
	{
		q.push(getf(i));
		c[getf(i)]=0;
	}
	while(!q.empty())
	{
		int i=q.front();q.pop();
		llll[i]=1;
		for (int j=1;j<=p;j++)
		{
			if (!intersect(l[i],l[j])) continue;
			if (u[i]==u[j]) continue;
			if (c[j]==c[i]) return puts("impossible"),0;
			if(llll[j])continue;
			llll[j]=1;
			c[j]=c[i]^1;
			q.push(j);
		}
	}
	puts("possible");
	return 0;
}