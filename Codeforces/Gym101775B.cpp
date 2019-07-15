#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int T,n,m,s,a[MAXN];
double ans,avg;

struct Scapegoat
{
	int x,cnt;double avg,dta;
	Scapegoat(){}
	Scapegoat(int id,int n,double navg){
		x=id;cnt=n;avg=navg;
		double p=(::avg-navg)*(::avg-navg)*n;
		double q=((double)a[x]/(double)(n+1)-::avg)*((double)a[x]/(double)(n+1)-::avg)*(n+1);
		dta=p-q;
		return ;
	}
	bool operator < (const Scapegoat &a)const{
		return dta<a.dta;
	}
};

priority_queue <Scapegoat> q;

int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%d %d",&n,&m);s=0;ans=0.0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
		avg=(double)s/(double)m;
		for (int i=1;i<=n;i++) q.push(Scapegoat(i,1,a[i]));
		for (int i=1;i<=m-n;i++)
		{
			Scapegoat p=q.top();q.pop();
			q.push(Scapegoat(p.x,p.cnt+1,(double)a[p.x]/(double)(p.cnt+1)));
		}
		while (!q.empty())
		{
			Scapegoat p=q.top();q.pop();
			ans+=(p.avg-avg)*(p.avg-avg)*(double)p.cnt;
		}
		ans/=(double)m;
		printf("Case #%d: %.12lf\n",TT,ans);
	}
	return 0;
}
