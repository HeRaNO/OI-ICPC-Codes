#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const double eps=1e-6;

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
};

struct Shape
{
	double x,y,r;int type;
	pair<double,double> readCircle()
	{
		scanf("%lf %lf %lf",&x,&y,&r);type=0;
		return {x-r,x+r};
	}
	double getY(double X,bool dir)
	{
		if (fabs(X-(x-r))<=eps||fabs(X-(x+r))<=eps) return y;
		assert(x-r+eps<=X&&X<=x+r-eps);
		if (dir) return y+sqrt(r*r-(x-X)*(x-X));
		else return y-sqrt(r*r-(x-X)*(x-X));
	}
};

struct Event
{
	double x;int id,f;
	Event(){}
	Event(double _,int __,int ___):x(_),id(__),f(___){}
	bool operator < (const Event &e)const{
		return fabs(x-e.x)<=eps?f<e.f:x<e.x;
	}
};

struct Query
{
	int type,x,y;
	Query(){}
	Query(int _,int __,int ___):type(_),x(__),y(___){}
};

Query q[MAXN];
int n,m,cntP;
vector <Shape> a,b;
vector <Event> Q;
vector <point> P;

double nowX;
struct sweepLine
{
	int x,f,dir;
	sweepLine(){}
	sweepLine(int _,int __,int ___):x(_),f(__),dir(___){}
	bool operator < (const sweepLine &A)const{
		if (x==A.x) return dir<A.dir;
		double y1=a[x].getY(nowX,dir);
		double y2=a[A.x].getY(nowX,A.dir);
		return y1<y2;
	}
}u[MAXN],d[MAXN];

set <sweepLine> S;
int ans[MAXN];
int dp[MAXN][2];
vector <int> g[MAXN];

inline void BuildTree()
{
	sort(Q.begin(),Q.end());
	for (auto e:Q)
	{
		nowX=e.x;
		if (e.f==-1)
		{
			u[e.id]=sweepLine(e.id,e.id,1);S.insert(u[e.id]);
			auto it=S.find(u[e.id]);++it;
			int fa=it==S.end()?0:it->f;
			d[e.id]=sweepLine(e.id,fa,0);S.insert(d[e.id]);
			g[fa].push_back(e.id);
		}
		else if (e.f==1)
		{
			S.erase(u[e.id]);S.erase(d[e.id]);
		}
	}
	return ;
}

void TreeDP(int u)
{
	dp[u][1]=1;
	for(auto v:g[u])
	{
		TreeDP(v);
		if(v>n)
		{
			dp[u][0]+=dp[v][0];
			dp[u][1]+=dp[v][1]-1;
		}
		else
		{
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
		}
	}
	if(u>n)ans[u-n]=max(dp[u][0],dp[u][1]);
}

int main()
{
	scanf("%d %d",&n,&m);a.emplace_back();P.emplace_back();
	for (int i=1;i<=n;i++)
	{
		pair <double,double> r;
		a.emplace_back(),r=a.back().readCircle();
		Q.emplace_back(Event(r.first,a.size()-1,-1));
		Q.emplace_back(Event(r.second,a.size()-1,1));
	}
	for (int i=1;i<=m;i++)
	{
		pair <double,double> r;
		a.emplace_back(),r=a.back().readCircle();
		Q.emplace_back(Event(r.first,a.size()-1,-1));
		Q.emplace_back(Event(r.second,a.size()-1,1));
	}
	BuildTree();
	TreeDP(0);
	//for (int i=1;i<=n+m;i++) printf("%d: %d %d\n",i,dp[i][0],dp[i][1]);
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}