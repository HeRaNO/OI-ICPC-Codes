#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

const long long M=1e9+7;

struct Point
{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	Point operator - (const Point &a)const{
		return Point(x-a.x,y-a.y);
	}
	long long operator * (const Point &a)const{
		return 1LL*x*a.y-1LL*y*a.x;
	}
};

Point a[MAXN],p;
int n,s,ans,cnt;
long long S,now;

inline void add(int &a,int b){a+=b;if (a>=M) a-=M;return ;}
inline void dec(int &a,int b){a-=b;if (a< 0) a+=M;return ;}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d %d",&a[i].x,&a[i].y);
	for (int i=2;i<n;i++) S+=(a[i]-a[0])*(a[i-1]-a[0]);
	for (int i=0,j=0,k;i<n;i++)
	{
		while (true)
		{
			k=(j+1)%n;
			long long nxtS=(a[k]-a[i])*(a[j]-a[i]);
			if (2ULL*(nxtS+now)>=S)
			{
				if (2ULL*(nxtS+now)==S) ++cnt;
				break;
			}
			now+=nxtS;add(s,now%M);
			Point df=a[k]-a[i];
			while (df.x<0) df.x+=M;if (df.x>=M) df.x-=M;
			while (df.y<0) df.y+=M;if (df.y>=M) df.y-=M;
			add(p.x,df.x);add(p.y,df.y);j=k;
		}
		add(ans,s);k=(i+1)%n;now-=(a[j]-a[i])*(a[k]-a[i]);
		dec(s,(p*(a[k]-a[i])%M+M)%M);
		Point df=a[k]-a[i];
		while (df.x<0) df.x+=M;if (df.x>=M) df.x-=M;
		while (df.y<0) df.y+=M;if (df.y>=M) df.y-=M;
		df.x=(1LL*((j-i+n)%n)*df.x)%M;
		df.y=(1LL*((j-i+n)%n)*df.y)%M;
		dec(p.x,df.x);dec(p.y,df.y);
	}
	(ans<<=1)%=M;ans=1LL*((1LL*n*(n-3)-cnt)/2)%M*(S%M)%M-ans;
	if (ans<0) ans+=M;
	printf("%d\n",ans);
	return 0;
}