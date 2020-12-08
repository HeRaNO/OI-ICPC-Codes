#include <bits/stdc++.h>
#define MAXN 1000
#define MAXM 499500
using namespace std;

const int MSK=1023;

struct point
{
	int x,y;
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	point operator - (const point &a)const{
		return point(x-a.x,y-a.y);
	}
	bool operator < (const point &a)const{
		return x<a.x;
	}
	long long operator * (const point &a)const{
		return 1LL*x*a.y-1LL*y*a.x;
	}
	void norm(){
		x=-x;y=-y;return ;
	}
}p[MAXN];

int n,id[MAXN],a[MAXN];
int v[MAXM],cnt;
long long ans=~(1LL<<63);

bool cmp(int A,int B)
{
	point x=p[A&MSK]-p[A>>10],y=p[B&MSK]-p[B>>10];
	if (x.x<0) x.norm();
	if (y.x<0) y.norm();
	return y*x<0;
}

inline long long S(int x,int y,int z)
{
	return abs((p[z]-p[x])*(p[y]-p[x]));
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y),id[i]=a[i]=i;
	sort(p,p+n);
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			v[cnt++]=i<<10|j;
	sort(v,v+cnt,cmp);
	for (int i=0;i<cnt;i++)
	{
		int x=v[i]>>10,y=v[i]&MSK;
		if (id[x]>id[y]) swap(x,y);
		if (id[x]>0) ans=min(ans,S(a[id[x]-1],x,y));
		if (id[y]<n-1) ans=min(ans,S(a[id[y]+1],x,y));
		swap(id[x],id[y]);
		swap(a[id[x]],a[id[y]]);
	}
	if (ans&1) printf("%lld.50\n",ans>>1);
	else printf("%lld.00\n",ans>>1);
	return 0;
}