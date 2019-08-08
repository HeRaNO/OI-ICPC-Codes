#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct frac
{
	long long x,y;
	frac(){x=0;y=1;}
	frac(long long a,long long b){
		int p=(a<0)+(b<0);
		a=abs(a);b=abs(b);
		long long t=__gcd(a,b);
		x=a/t;y=b/t;if (p&1) x=-x;
	}
	frac operator + (const frac &a)const{
		return frac(x*a.y+y*a.x,y*a.y);
	}
	frac operator - (const frac &a)const{
		return frac(x*a.y-y*a.x,y*a.y);
	}
	frac operator * (long long a)const{
		return frac(x*a,y);
	}
	frac operator * (frac a)const{
		return frac(x*a.x,y*a.y);
	}
	frac operator / (long long a)const{
		return frac(x,y*a);
	}
};

frac lambda[MAXN],a[MAXN],ny,sum;
int n,x[MAXN],y[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n+1;i++) scanf("%d %d",&x[i],&y[i]);
	for (int i=2;i<=n;i++)
	{
		frac kl=frac(y[i-1]-y[i],x[i-1]-x[i]);
		frac kr=frac(y[i+1]-y[i],x[i+1]-x[i]);
		lambda[i]=(kr-kl)/2;
		a[i]=frac(x[i],1);
	}
	ny=frac(0,1);
	for (int i=2;i<=n;i++) ny=ny+lambda[i]*(frac(x[n+1],1)-a[i]);
	if (!(ny.x==y[n+1]&&ny.y==1)) return puts("No"),0;
	ny=frac(0,1);sum=frac(0,1);
	for (int i=2;i<=n;i++) ny=ny+lambda[i]*(a[i]-frac(x[1],1)),sum=sum-lambda[i];
	if (!(ny.x==y[1]&&ny.y==1)) return puts("No"),0;
	for (int i=2;i<=n;i++)
	{
		frac delta=lambda[i]*(x[i-1]-x[i]);
		ny=ny+sum*(x[i]-x[i-1]);
		sum=sum+lambda[i]*2;
		if (!(ny.x==y[i]&&ny.y==1)) return puts("No"),0;
	}
	puts("Yes");
	return 0;
}