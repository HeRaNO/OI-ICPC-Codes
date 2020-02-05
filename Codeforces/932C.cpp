#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=998244353,mod=119;
const int Lim=1<<20;

int a[MAXM];

ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	ll gcd=exgcd(b,a%b,x,y);
	ll p=x;
	x=y;
	y=p-(a/b)*y;
	return gcd;
}

int main()
{
	ll n,A,B,x,y;
	scanf("%lld%lld%lld",&n,&A,&B);
	int g=exgcd(A,B,x,y);
	if(n%g)return puts("-1");
	x*=n/g,y*=n/g;
	while(y<0)
	{
		x-=B/g;
		y+=A/g;
	}
	while(x<0)
	{
		x+=B/g;
		y-=A/g;
	}
	if(y<0)return puts("-1"),0;
	for(int i=1;i<=x;i++)
	{
		int l=(i-1)*A+1,r=i*A;
		for(int j=l;j<r;j++)
		{
			a[j]=j+1;
		}
		a[r]=l;
	}
	for(int i=1;i<=y;i++)
	{
		int l=(i-1)*B+1+x*A,r=i*B+x*A;
		for(int j=l;j<r;j++)
		{
			a[j]=j+1;
		}
		a[r]=l;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
