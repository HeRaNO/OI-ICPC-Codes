#include <bits/stdc++.h>
#define MAXN 300005
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
	vector <point> up,down;
	pair<double,double> readCircle()
	{
		scanf("%lf %lf %lf",&x,&y,&r);type=0;
		return {x-r,x+r};
	}
	pair<double,double> readPolygon()
	{
		vector <point> t;type=1;
		int n,mx,mn;double mxx=-1e18,mnx=1e18;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%lf %lf",&x,&y);t.push_back(point(x,y));
			if (x>mxx) mxx=x,mx=i;if (x<mnx) mnx=x,mn=i;
		}
		if (mn<mx)
		{
			for (int i=mn;i<=mx;i++) up.push_back(t[i]);
			for (int i=mn;~i;i--) down.push_back(t[i]);
			for (int i=n-1;i>=mx;i--) down.push_back(t[i]);
		}
		else
		{
			for (int i=mn;i>=mx;i--) down.push_back(t[i]);
			for (int i=mn;i<n;i++) up.push_back(t[i]);
			for (int i=0;i<=mx;i++) up.push_back(t[i]);
		}
		return {mnx,mxx};
	}
	double calcY(point A,point B,double x)
	{
		assert(fabs(B.x-A.x)>eps);
		return A.y+(x-A.x)/(B.x-A.x)*(B.y-A.y);
	}
	double calc(vector <point> &a,double x)
	{
		for (int i=0;i+1<a.size();i++)
			if (a[i].x<=x&&x<=a[i+1].x)
				return calcY(a[i],a[i+1],x);
		assert(false);
		return -1;
	}
	double getY(double X,bool dir)
	{
		if (!type)
		{
			if (fabs(X-(x-r))<=eps||fabs(X-(x+r))<=eps) return y;
			assert(x-r+eps<=X&&X<=x+r-eps);
			if (dir) return y+sqrt(r*r-(x-X)*(x-X));
			else return y-sqrt(r*r-(x-X)*(x-X));
		}
		if (fabs(X-up[0].x)<=eps||fabs(X-up.back().x)<=eps)
		{
			double mxx=-1e18,mnx=1e18;
			for (auto p:up) if(fabs(X-p.x)<=eps) mxx=max(mxx,p.y);
			for (auto p:down) if(fabs(X-p.x)<=eps) mnx=min(mnx,p.y);
			return !dir?mnx:mxx;
		}
		return calc(!dir?down:up,X);
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
int n,m,cntP,v[MAXN];
char s[3];
vector <Shape> a;
vector <Event> Q;
vector <point> P;

struct HLD
{
	int n,R=1;
	vector <int> g[MAXN];
	int in[MAXN],dep[MAXN],siz[MAXN],mx[MAXN],fa[MAXN],top[MAXN];
	int c[MAXN],rev[MAXN],val[MAXN];

	inline int lowbit(int x){return x&-x;}
	inline void modify(int x,int v){for (;x<=n;x+=lowbit(x)) c[x]^=v;return ;}
	inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r^=c[x];return r;}
	inline int query(int l,int r){return query(r)^query(l-1);}

	inline void add(int u,int v){g[u].push_back(v);return ;}

	inline void dfs1(int x)
	{
		siz[x]=1;mx[x]=-1;
		for (auto v:g[x])
			if (v!=fa[x])
			{
				dep[v]=dep[x]+1;fa[v]=x;
				dfs1(v);
				siz[x]+=siz[v];
				if (!~mx[x]||siz[v]>siz[mx[x]]) mx[x]=v;
			}
		return ;
	}

	inline void dfs2(int x,int t)
	{
		top[x]=t;rev[R]=x;in[x]=R++;
		if (~mx[x]) dfs2(mx[x],t);
		for (auto v:g[x]) if (v!=mx[x]&&v!=fa[x]) dfs2(v,v);
		return ;
	}

	inline void Change(int u,int v)
	{
		modify(in[u],val[in[u]]);
		val[in[u]]=v;modify(in[u],val[in[u]]);
		return ;
	}

	inline int Query(int l,int r)
	{
		int res=0;
		for (;top[l]!=top[r];l=fa[top[l]])
		{
			if (dep[top[l]]<dep[top[r]]) swap(l,r);
			res^=query(in[top[l]],in[l]);
		}
		if (in[l]>in[r]) swap(l,r);
		return res^query(in[l],in[r])^val[in[l]];
	}

	void init(int _n)
	{
		n=_n;dfs1(0);dfs2(0,0);
		for (int i=1;i<=n;i++) Change(i,::v[i]);
		return ;
	}
}hld;

double nowX;
struct sweepLine
{
	int x,f,dir;
	sweepLine(){}
	sweepLine(int _,int __,int ___):x(_),f(__),dir(___){}
	bool operator < (const sweepLine &A)const{
		if (x==A.x) return dir<A.dir;
		double y1=x>n?P[x-n].y:a[x].getY(nowX,dir);
		double y2=A.x>n?P[A.x-n].y:a[A.x].getY(nowX,A.dir);
		return y1<y2;
	}
}u[MAXN],d[MAXN];

set <sweepLine> S;

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
			hld.add(fa,e.id);
		}
		else if (e.f==1)
		{
			S.erase(u[e.id]);S.erase(d[e.id]);
		}
		else
		{
			auto it=S.lower_bound(sweepLine(e.id,0,1));
			if (it==S.end()) hld.add(0,e.id);
			else hld.add(it->f,e.id);
		}
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);a.emplace_back();P.emplace_back();
	for (int i=1;i<=n;i++)
	{
		pair <double,double> r;
		scanf("%s",s); 
		if (s[0]=='C') a.emplace_back(),r=a.back().readCircle();
		else a.emplace_back(),r=a.back().readPolygon();
		Q.emplace_back(Event(r.first,a.size()-1,-1));
		Q.emplace_back(Event(r.second,a.size()-1,1));
		scanf("%d",&v[i]);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%s",s);
		if (s[0]=='C') scanf("%d %d",&q[i].x,&q[i].y);
		else
		{
			q[i].type=1;
			double x,y;scanf("%lf %lf",&x,&y);
			P.emplace_back(point(x,y));
			Q.emplace_back(Event(x,P.size()+n-1,0));
			scanf("%lf %lf",&x,&y);
			P.emplace_back(point(x,y));
			Q.emplace_back(Event(x,P.size()+n-1,0));
			q[i].x=P.size()+n-2;q[i].y=P.size()+n-1;
		}
	}
	BuildTree();hld.init(n+P.size()-1);
	for (int i=1,ans=0;i<=m;i++)
	{
		if (!q[i].type) hld.Change(q[i].x,q[i].y);
		else printf("%d\n",ans^=hld.Query(q[i].x,q[i].y));
	}
	return 0;
}