#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1004535809,mod=998244353;
const int Lim=1<<15;
const int MAXN=4e5+10,INF=INT_MAX;

int n,m,k;
int x[MAXN],y[MAXN];
ll ans[MAXN];
set<int> s1[MAXN],s2[MAXN];

int main()
{
	memset(ans,-1,sizeof(ans));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		s1[(x[i]+y[i]+200000)].insert(i);
		s2[(x[i]-y[i]+200000)].insert(i);
	}
	ll t=0,nx=0,ny=0;
	int d=1;
	while(1)
	{
		if(d==1)
		{
			for(auto j:s2[nx-ny+200000])
			{
				s1[x[j]+y[j]+200000].erase(j);
				ans[j]=t+abs(x[j]-nx);
			}
			s2[nx-ny+200000].clear();
			int p=min(n-nx,m-ny);
			if(p==n-nx)d=2;
			else d=4;
			nx+=p;
			ny+=p;
			t+=p;
		}
		else if(d==2)
		{
			for(auto j:s1[nx+ny+200000])
			{
				s2[x[j]-y[j]+200000].erase(j);
				ans[j]=t+abs(x[j]-nx);
			}
			s1[nx+ny+200000].clear();
			int p=min(nx,m-ny);
			if(p==nx)d=1;
			else d=3;
			nx-=p;
			ny+=p;
			t+=p;
		}
		else if(d==3)
		{
			for(auto j:s2[nx-ny+200000])
			{
				s1[x[j]+y[j]+200000].erase(j);
				ans[j]=t+abs(x[j]-nx);
			}
			s2[nx-ny+200000].clear();
			int p=min(nx,ny);
			if(p==nx)d=4;
			else d=2;
			nx-=p;
			ny-=p;
			t+=p;
		}
		else if(d==4)
		{
			for(auto j:s1[nx+ny+200000])
			{
				s2[x[j]-y[j]+200000].erase(j);
				ans[j]=t+abs(x[j]-nx);
			}
			s1[nx+ny+200000].clear();
			int p=min(n-nx,ny);
			if(p==n-nx)d=3;
			else d=1;
			nx+=p;
			ny-=p;
			t+=p;
		}
		if(nx==n&&ny==m)break;
		if(nx==0&&ny==m)break;
		if(nx==n&&ny==0)break;
		if(nx==0&&ny==0)break;
	}
	for(int i=1;i<=k;i++)printf("%lld\n",ans[i]);
	return 0;
}
