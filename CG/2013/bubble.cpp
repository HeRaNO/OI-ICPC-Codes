#include <bits/stdc++.h>
#define MAXN 100015
using namespace std;

const double eps=1e-6;
const double pi=acos(-1.0);

struct point
{
	double x, y;
	int c;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	bool operator < (const point &p) const {
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	double length() const {
		return x * x + y * y;
	}
};

point p[MAXN];
double w,h,ori[MAXN];
int n,m,Q;
long long ans;
bool del[MAXN],vis[MAXN];
set <pair<double,int> > s[MAXN];
vector <int> v[MAXN];
queue <int> q;

inline double sqr(double x){return x*x;}
inline long long sqr(int x){return 1LL*x*x;}

inline void add(int x,int y)
{
	v[x].push_back(y);v[y].push_back(x);
	return ;
}

inline void addPoint(double t,double alpha,int c)
{
	p[++n]=point(t*cos(alpha),t*sin(alpha));
	p[n].c=c;return ;
}

inline void BFS()
{
	int cnt=0;
	memset(vis,false,n);
	q.push(n);vis[n]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (auto y:v[x])
		{
			if (del[y]||vis[y]||p[x].c!=p[y].c) continue;
			vis[y]=true;q.push(y);
		}
	}
	for (int i=1;i<=n;i++) if (vis[i]) ++cnt;
	if (cnt>=3)
	{
		ans+=sqr(cnt);
		for (int i=1;i<=n;i++) if (vis[i]) del[i]=true;
	}
	return ;
}

int main()
{
	scanf("%lf %lf",&w,&h);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lf %lf %d",&p[i].x,&p[i].y,&p[i].c);
	sort(p+1,p+n+1);p[0]=point(-w-1,-h-1);
	for (int i=1;i<=n;i++)
	{
		if (fabs(p[i].x-p[i-1].x)>eps) ori[++m]=p[i].x;
		else if (fabs(p[i].y-p[i-1].y-2)<=eps)
			add(i-1,i);
		s[m].insert({p[i].y,i});
	}
	for (int i=1;i<m;i++)
		for (auto j:s[i])
		{
			double y=j.first;int c=j.second;
			for (int p=i+1;p<=i+2;p++)
			{
				if (ori[p]>2+ori[i]) break;
				auto t=s[p].insert({y,-1});
				auto it=t.first;
				if (it!=s[p].begin())
				{
					--it;
					if (fabs(sqr(ori[p]-ori[i])+sqr((*it).first-y)-4)<=eps)
						add((*it).second,c);
					++it;
				}
				++it;
				if (it!=s[p].end())
				{
					if (fabs(sqr(ori[p]-ori[i])+sqr((*it).first-y)-4)<=eps)
						add((*it).second,c);
				}
				--it;
				s[p].erase(it);
			}
		}
	scanf("%d",&Q);
	while (Q--)
	{
		double alpha,t;int c;
		scanf("%lf %d",&alpha,&c);
		alpha=alpha/180.0*pi;
		if (fabs(alpha*2-pi)<=eps) t=h-1;
		else if (alpha*2-pi>0)
			t=min((1-w)/cos(alpha),(h-1)/sin(alpha));
		else
			t=min((w-1)/cos(alpha),(h-1)/sin(alpha));
		for (int i=1;i<=n;i++)
			if (!del[i])
			{
				double d=p[i].x*cos(alpha)+p[i].y*sin(alpha);
				double l=sqr(p[i].x)+sqr(p[i].y)-4;
				if (d*d<l) continue;
				t=min(t,d-sqrt(d*d-l));
			}
		addPoint(t,alpha,c);
		for (int i=1;i<n;i++)
			if (!del[i]&&fabs((p[n]-p[i]).length()-4)<=eps)
				add(n,i);
		BFS();
	}
	printf("%lld\n",ans);
	return 0;
}