#include <bits/stdc++.h>
#define MAXN 200005
#define MAXX 10005
using namespace std;

struct point
{
	int x,y;
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	point operator - (const point &p)const{
		return point(x-p.x,y-p.y);
	}
	bool operator < (const point &p) const{
		if (p.x!=x) return x>p.x;
		return y>p.y;
	}
	bool operator == (const point &p)const{
		return x==p.x&&y==p.y;
	}
	int operator * (const point &p)const{
		return x*p.y-y*p.x;
	}
};

int n,m,X,cnt,las,top[MAXX];
point p[MAXN],q[MAXX],ch[MAXX];
bool ans[MAXX],fi=true;

inline bool judge(point A,point B,point C)
{
	point p=C-B,q=B-A;
	return 1LL*A.x*C.y*q.y*p.x>1LL*A.y*C.x*p.y*q.x;
}

inline int ConvexHull(point p[],int n)
{
	int m=0;
	for (int i=1;i<=n;i++)
	{
		while (m>1&&judge(ch[m-1],ch[m],p[i])) --m;
		ch[++m]=p[i];
	}
	return m;
}

void out(int x)
{
	fi?fi=false:printf(" ");
	printf("%d",x);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		X=max(X,p[i].x);top[p[i].x]=max(top[p[i].x],p[i].y);
	}
	for (int i=X;i;i--) if (top[i]>las) q[++cnt]=point(i,las=top[i]);
	m=ConvexHull(q,cnt);
	for (int i=1;i<=m;i++) ans[ch[i].x]=true;
	for (int i=1;i<=n;i++) if (ans[p[i].x]&&top[p[i].x]==p[i].y) out(i);
	puts("");
	return 0;
}