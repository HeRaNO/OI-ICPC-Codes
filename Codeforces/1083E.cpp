#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define ls id<<1
#define rs id<<1|1
#define pii pair<int,ll>
#define mp(a,b) make_pair((a),(b))
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=1000050;
int n;
struct rectangle
{
	ll x,y,cost;
	bool operator < (const rectangle &c)const
	{
		return y<c.y;
	}
}a[N];
int q[N];
ll dp[N],ans;
int l,r;
inline double k(int i,int j)
{
	return (double)(1.0*dp[i]-1.0*dp[j])/(double)(1.0*a[i].y-1.0*a[j].y);
}
inline ll cal(int i,int j)
{
	return dp[j]-a[i].x*a[j].y+(a[i].x*a[i].y-a[i].cost);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].cost);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		while(l<r&&cal(i,q[l])<cal(i,q[l+1]))l++;
		dp[i]=cal(i,q[l]);
		ans=max(ans,dp[i]);
		while(l<r&&k(q[r-1],q[r])<k(i,q[r]))r--;
		q[++r]=i;
	}
	cout<<ans<<endl;
	return 0;
}
