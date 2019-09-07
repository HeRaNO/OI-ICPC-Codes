#include <map>
#include <cstdio>
#include <algorithm>
#define MAXN 1005
using namespace std;

struct Point
{
	long long x,y;
	Point(long long _x=0,long long _y=0){
		x=_x;y=_y;
	}
	Point operator + (const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator / (const long long &b)const{
		return Point(x/b, y/b);
	}
};

int n,m;
Point p[MAXN],a[MAXN];
map <pair<int,int>,int> cnt,mp;
map <pair<int,int>,int> :: iterator it;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&p[i].x,&p[i].y);p[i].x*=2;p[i].y*=2;
		pair <int,int> pp=make_pair(p[i].x,p[i].y);
		if (!cnt.count(pp)) a[++m]=p[i];
		++cnt[pp];
	}
	int ans=m-1;
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
		{
			Point t=(a[i]+a[j])/2;
			mp[make_pair(t.x,t.y)]++;
		}
	for(it=mp.begin();it!=mp.end();it++)
	{
		pair<int,int> tp=it->first;
		int cur=m-2*it->second;
		if (cnt.count(tp)) cur-=cnt[tp];
		if (cur<0) cur=0;
		ans=min(ans,cur);
	}
	printf("%d\n",ans);
	return 0;
}