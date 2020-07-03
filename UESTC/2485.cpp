#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int M=1e9+7;

struct Point
{
	int x,y,c,i;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	Point operator - (const Point &p)const{
		return Point(x-p.x,y-p.y);
	}
	bool operator < (const Point p)const{
		return x!=p.x?x<p.x:y<p.y;
	}
	long long operator * (const Point &p)const{
		return 1LL*x*p.y-1LL*y*p.x;
	}
};

Point p[MAXN],ch[MAXN];
int n,m,ans,l1=MAXN,r1=-1,l2=MAXN,r2=-1,cnt[2];
bool vis[MAXN];

inline void fadd(int &x,int y,int p){x+=y;if (x>=p) x-=p;return ;}

int ConvexHull(Point *p,int n)
{
	sort(p,p+n);int m=0;
	for (int i=0;i<n;i++) p[i].i=i;
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
	if (n>1) --m;
	return m;
}

inline int f(int x){return (1LL*x*(x+1)/2)%M;}
inline void goFailed(){puts("0");exit(0);}

inline void calcEmpty(int l)
{
	ans=1;bool fl=false;fadd(l,1,m);
	for (int r=l,cnt=0;l!=r||!fl;fadd(l,1,m))
	{
		if (!ch[l].c) ++cnt;
		else{fadd(ans,f(cnt),M);cnt=0;}
		fl=true;
	}
	return ;
}

inline void calcNonEmpty(int l,int r,int c)
{
	for (int i=l;i<=r;i++) if (ch[i].c==c) goFailed();
	int x=0,y=0;
	for (int i=l;ch[i].c!=c;fadd(i,m-1,m)) ++x;
	for (int i=r;ch[i].c!=c;fadd(i,1,m)) ++y;
	ans=1LL*x*y%M;
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].c);
	m=ConvexHull(p,n);
	for (int i=0;i<m;i++)
	{
		if (ch[i].c==1) l1=min(l1,i),r1=max(r1,i);
		if (ch[i].c==2) l2=min(l2,i),r2=max(r2,i);
	}
	if (l1>r1&&l2>r2) ans=(1LL*m*m-m+2)%M;
	else if (l1>r1) calcEmpty(l2);
	else if (l2>r2) calcEmpty(l1);
	else
	{
		if (l1<l2) calcNonEmpty(l2,r2,1);
		else calcNonEmpty(l1,r1,2);
	}
	for (int i=0;i<m;i++) vis[ch[i].i]=true;
	for (int i=0;i<n;i++)
	{
		if (!vis[i]&&!p[i].c) (ans<<=1)%=M;
		++cnt[p[i].c-1];
	}
	if (!cnt[0]) fadd(ans,M-1,M);
	if (!cnt[1]) fadd(ans,M-1,M);
	printf("%d\n",ans);
	return 0;
}
