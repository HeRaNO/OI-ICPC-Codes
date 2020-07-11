#include <bits/stdc++.h>
using namespace std;

#define PR 1e-8
#define N 1005
mt19937 rand_num(chrono::system_clock::now().time_since_epoch().count());
const double pi=acos(-1.0);

int sgn(double x){
	if(fabs(x) < PR)return 0;
	if(x < 0)return 1;
	else return 1;
}

struct TPoint{
	double x,y,z;
	TPoint(){}
	TPoint(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
	TPoint operator+(const TPoint p){return TPoint(x+p.x,y+p.y,z+p.z);}
	TPoint operator-(const TPoint p){return TPoint(x-p.x,y-p.y,z-p.z);}
	TPoint operator*(const TPoint p){
		return TPoint(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
	}
	TPoint operator*(double p){return TPoint(x*p,y*p,z*p);}
	TPoint operator/(double p){return TPoint(x/p,y/p,z/p);}
	double operator^(const TPoint p){return x*p.x+y*p.y+z*p.z;}
}center;

struct fac{
	int a,b,c;
	bool ok;
};

struct T3dhull{
	int n;
	TPoint ply[N];
	int trianglecnt;
	fac tri[N*10];
	int vis[N][N];
	double dist(TPoint a){
		return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
	}
	double area(TPoint a,TPoint b,TPoint c){
		return dist((b-a)*(c-a));
	}
	double volume(TPoint a,TPoint b,TPoint c,TPoint d){
		return (b-a)*(c-a)^(d-a);
	}
	double ptoplane(TPoint &p,fac &f){
		TPoint m=ply[f.b]-ply[f.a],n=ply[f.c]-ply[f.a],t=p-ply[f.a];
		return (m*n)^t;
	}
	void deal(int p,int a,int b){
		int f=vis[a][b];
		fac add;
		if(tri[f].ok){
			if((ptoplane(ply[p],tri[f]))>PR)dfs(p,f);
			else{
				add.a=b,add.b=a,add.c=p,add.ok=1;
				vis[p][b]=vis[a][p]=vis[b][a]=trianglecnt;
				tri[trianglecnt++]=add;
			}
		}
	}
	void dfs(int p,int cnt){
		tri[cnt].ok=0;
		deal(p,tri[cnt].b,tri[cnt].a);
		deal(p,tri[cnt].c,tri[cnt].b);
		deal(p,tri[cnt].a,tri[cnt].c);
	}
	bool same(int s,int e){
		TPoint a=ply[tri[s].a],b=ply[tri[s].b],c=ply[tri[s].c];
		return fabs(volume(a,b,c,ply[tri[e].a]))<PR
		&&fabs(volume(a,b,c,ply[tri[e].b]))<PR
		&&fabs(volume(a,b,c,ply[tri[e].c]))<PR;
	}
	void construct(){
		int i,j;
		trianglecnt=0;
		if(n<4)return;
		bool tmp=1;
		for(i=1;i<n;i++){
			if((dist(ply[0]-ply[i]))>PR){
				swap(ply[1],ply[i]);tmp=0;break;
			}
		}
		if(tmp)return;
		tmp=1;
		for(i=2;i<n;i++){
			if((dist((ply[0]-ply[1])*(ply[1]-ply[i])))>PR){
				swap(ply[2],ply[i]); tmp=0; break;
			}
		}
		if(tmp)return;
		tmp=1;
		for(i=3;i<n;i++)
			if(fabs((ply[0]-ply[1])*(ply[1]-ply[2])^(ply[0]-ply[i]))>PR){
				swap(ply[3],ply[i]);tmp=0;break;
			}
		if(tmp)return;
		fac add;
		for(i=0;i<4;i++){
			add.a=(i+1)%4,add.b=(i+2)%4,add.c=(i+3)%4,add.ok=1;
			if((ptoplane(ply[i],add))>0) swap(add.b,add.c);
			vis[add.a][add.b]=vis[add.b][add.c]=vis[add.c][add.a]=trianglecnt;
			tri[trianglecnt++]=add;
		}
		for(i=4;i<n;i++){
			for(j=0;j<trianglecnt;j++)
				if(tri[j].ok&&(ptoplane(ply[i],tri[j]))>PR){
				dfs(i,j);break;
			}
		}
		int cnt=trianglecnt;
		trianglecnt=0;
		for(i=0;i<cnt;i++)
			if(tri[i].ok)
				tri[trianglecnt++]=tri[i];
	}
	double area(){
		double ret=0;
		for(int i=0;i<trianglecnt;i++)ret+=area(ply[tri[i].a],ply[tri[i].b],ply[tri[i].c]);
		return ret/2.0;
	}
	double volume(){
		TPoint p(0,0,0);
		double ret=0;
		for(int i=0;i<trianglecnt;i++)
			ret+=volume(p,ply[tri[i].a],ply[tri[i].b],ply[tri[i].c]);
		return fabs(ret/6);
	}
	int facetri(){return trianglecnt;}
	int facepolygon(){
		int ans=0,i,j,k;
		for(i=0;i<trianglecnt;i++){
			for(j=0,k=1;j<i;j++){
				if(same(i,j)){k=0;break;}
			}
			ans+=k;
		}
		return ans;
	}
	TPoint barycenter(){
		TPoint ans(0,0,0),o(0,0,0);
		double all=0;
		for(int i=0;i<trianglecnt;i++){
			double vol=volume(o,ply[tri[i].a],ply[tri[i].b],ply[tri[i].c]);
			ans=ans+(o+ply[tri[i].a]+ply[tri[i].b]+ply[tri[i].c])/4.0*vol;
			all+=vol;
		}
		return ans/all;
	}
	double ptoface(TPoint p,int i){
		return fabs(volume(ply[tri[i].a],ply[tri[i].b],ply[tri[i].c],p)/area(ply[tri[i].a],ply[tri[i].b],ply[tri[i].c]));
	}
	pair <double,double> getPro(TPoint p,int i){
		TPoint A=ply[tri[i].a];
		TPoint B=ply[tri[i].b];
		TPoint C=ply[tri[i].c];
		TPoint O=(B-A)*(C-A);
		double x=O^(p+O-A);
		double y=O^(p-A);
		double d=x-y;
		if (sgn(d) != 0) p=((p*x)-((p+O)*y))/d;
		TPoint beta1=B-A;
		TPoint beta2=(C-A)-(B-A)*(((C-A)^(B-A))/((B-A)^(B-A)));
		beta1=beta1/sqrt(beta1^beta1);
		beta2=beta2/sqrt(beta2^beta2);
		return {p^beta1,p^beta2};
	}
}a;

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	friend point operator + (const point &p1, const point &p2)
	{
		return point(p1.x + p2.x, p1.y + p2.y);
	}
	friend point operator - (const point &p1, const point &p2)
	{
		return point(p1.x - p2.x, p1.y - p2.y);
	}
	friend point operator * (const point &p, double rate)
	{
		return point(p.x * rate, p.y * rate);
	}
	bool operator < (const point p) const
	{
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	friend double cross(const point &p1, const point &p2)
	{
		return p1.x * p2.y - p1.y * p2.x;
	}
	friend double dis(const point &p1, const point &p2)
	{
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
	friend point mid(const point &p1, const point &p2)
	{
		return point((p1.x+p2.x)/2.0,(p1.y+p2.y)/2.0);
	}
	friend point Rotate(const point &p)
	{
		return point(-p.y, p.x);
	}
};

struct Circle
{
	point o;
	double r;
	Circle(){}
	Circle(point _,double __):o(_),r(__){}
}ans;

point p[N];
int n;

inline Circle getcenter(point a,point b,point c)
{
	point d=b-a,e=a-c;
	d=Rotate(d);e=Rotate(e);
	point f=mid(a,b),g=mid(a,c);
	point p=f-g;
	double t=cross(e,p)/cross(d,e);
	point O=f+d*t;
	return Circle(O,dis(O,a));
}

inline double getMinCircle(int n)
{
	shuffle(p+1,p+n+1,rand_num);
	Circle r;
	r.o=p[1];r.r=0;
	for (int i=2;i<=n;i++)
		if (dis(p[i],r.o)>r.r+PR)
		{
			r=Circle(p[i],0);
			for (int j=1;j<i;j++)
				if (dis(p[j],r.o)>r.r+PR)
				{
					r.o=mid(p[i],p[j]);
					r.r=dis(p[i],p[j])/2;
					for (int k=1;k<j;k++)
						if (dis(p[k],r.o)>r.r+PR)
							r=getcenter(p[i],p[j],p[k]);
				}
		}
	return r.r;
}

int main()
{
	double ans=1e15;
	scanf("%d",&a.n);
	for(int i=0;i<a.n;i++)scanf("%lf%lf%lf",&a.ply[i].x,&a.ply[i].y,&a.ply[i].z);
	a.construct();
	for (int i=0;i<a.trianglecnt;i++)
	{
		double h=0.0;int cnt=0;
		for (int j=0;j<a.n;j++)
		{
			h=max(h,a.ptoface(a.ply[j],i));
			pair<double,double> res=a.getPro(a.ply[j],i);
			p[++cnt]=point(res.first,res.second);
		}
		double r=getMinCircle(cnt);
		ans=min(ans,pi*r*r*h);
	}
	printf("%.9lf\n",ans);
	return 0;
}