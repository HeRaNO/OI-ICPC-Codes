#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const int M=998244353;

inline int sgn(__int128 x)
{
	if (!x) return x;
	return x<0?-1:1;
}

struct point
{
	long long x,y;
	point(){}
	point(long long _x,long long _y):x(_x),y(_y){}
	__int128 operator * (const point &p)const{
		return (__int128)x*(__int128)p.y-(__int128)y*(__int128)p.x;
	}
	__int128 length()const{
		return (__int128)x*x+(__int128)y*y;
	}
	point operator - (const point &p)const{
		return point(x-p.x,y-p.y);
	}
	int quadrant() const {
		int xs = sgn(x), ys = sgn(y);
		return xs == 0 && ys == 0 ? -1 : ((ys < 0 || ys == 0 && xs > 0) ? 0 : 1);
	}
	bool operator < (const point &p)const{
		int lq = quadrant(), rq = p.quadrant();
		if (lq != rq) return lq < rq;
		int s = sgn(*this * p);
		return s ? s > 0 : sgn(length() - p.length()) < 0;
	}
};

int n,ans;
point p[MAXN];
vector <point> v;

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}
inline int nxt(int x,int m){++x;if (x==m) x=0;return x;}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld %lld",&p[i].x,&p[i].y);
	sort(p,p+n);
	v.push_back(p[0]);
	for (int i=1;i<n;i++)
	{
		if (p[i]*p[i-1]==0) v.pop_back();
		v.push_back(p[i]); 
	}
	int m=v.size();
	for (int i=0;i<m;i++) fadd(ans,(v[i]-v[nxt(i,m)]).length()%M);
	printf("%d\n",ans);
	return 0;
}
