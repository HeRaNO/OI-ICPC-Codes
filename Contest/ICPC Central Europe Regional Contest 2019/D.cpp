#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

const double eps=1e-4;

int n,ans,s;
long long r,a,b,x,y;
vector <pair<double,int> > v;

double sqr(double x){return x*x;}

bool cmp(pair<double,int> x,pair<double,int> y)
{
	if (fabs(x.first-y.first)>eps) return x.first<y.first;
	return x.second>y.second;
}

int main()
{
	scanf("%d %lld %lld %lld",&n,&r,&a,&b);
	bool f1=0,f2=0;
	if (a<0) a=-a,f1=1;
	if (b<0) b=-b,f2=1;
	double r2=r*r;
	if (a==0&&b==0)
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%lld %lld",&x,&y);
			if (x*x+y*y<=r*r) ++ans;
		}
		return printf("%d\n",ans),0;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&x,&y);
		if (f1) x=-x;if (f2) y=-y;
		double f2=x*x+y*y;
		double d2=sqr(b*x-a*y)/(a*a+b*b);
		if (r2<d2) continue;
		double fd=sqrt(f2-d2);if (y<-x) fd=-fd;
		double rd=sqrt(r2-d2);
		v.push_back({fd-rd, 1});
		v.push_back({fd+rd,-1});
	}
	sort(v.begin(),v.end(),cmp);
	for (auto p:v)
	{
		s+=p.second;
		ans=max(ans,abs(s));
	}
	printf("%d\n",ans);
	return 0;
}