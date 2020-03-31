#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

const double _s2=sqrt(2.0);
const double pi=acos(-1.0);
const double pi2=pi/2.0;
const double pi4=pi/4.0;

int n,x[MAXN],y[MAXN];
long long mnd=~(1LL<<63),D;
double d[MAXN],ang[MAXN];
vector <pair<double,int> > v;

inline void norm(double &a)
{
	while (a<0) a+=pi2;
	while (a>=pi2) a-=pi2;
	return ;
}

inline bool check(double x)
{
	double dig=x/_s2;int cnt=0;v.clear();
	for (int i=1;i<=n;i++)
	{
		if (d[i]>dig) continue;
		if (d[i]*2>x)
		{
			double alpha=asin(x/(2.0*d[i]))-pi4;
			double out=ang[i]-alpha,in=ang[i]+alpha;
			norm(in);norm(out);
			if (!(in<out)) ++cnt;
			v.push_back({in,1});
			v.push_back({out,-1});
		}
		else return false;
	}
	int m=v.size()>>1;
	if (cnt==m) return true;
	sort(v.begin(),v.end());
	for (auto p:v)
	{
		cnt+=p.second;
		if (cnt==m) return true;
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		D=1LL*x[i]*x[i]+1LL*y[i]*y[i];
		mnd=min(mnd,D);
		d[i]=sqrt(D);ang[i]=atan2(y[i],x[i]);
	}
	double l=_s2*sqrt(mnd),r=2.0*sqrt(mnd);
	for (int i=1;i<=50;i++)
	{
		double mid=(l+r)/2.0;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%.4lf\n",l*4.0);
	return 0;
}