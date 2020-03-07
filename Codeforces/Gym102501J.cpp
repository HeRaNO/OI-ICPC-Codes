#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e6+10,MAXM=1e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

ll fac[MAXN],inc[MAXN];

ll c(ll di,ll gao)
{
	return fac[di]*inc[gao]%MOD*inc[di-gao]%MOD;
}

ll ksm(ll x,ll v)
{
	ll ans=1;
	for(;v;v>>=1,x=x*x%MOD)if(v&1)ans=ans*x%MOD;
	return ans;
}

ll catalan(ll x)
{
	return (c(2*x,x)-c(2*x,x-1)+MOD)%MOD;
}

int n;
int a[MAXN];
ll maxn=2e6,ans=1;
stack<int> s;
void solve(ll x)
{
	int cnt=0,cur=x;
	while(SZ(s)&&x<s.top())
	{
		if(s.top()==cur)cnt++;
		else
		{
			ans=ans*catalan(cnt)%MOD;
			cnt=1;
			cur=s.top();
		}
		s.pop();
	}
	ans=ans*catalan(cnt)%MOD;
}

int main()
{
	fac[0]=1;
	for(int i=1;i<=maxn;i++)fac[i]=fac[i-1]*i%MOD;
	inc[maxn]=ksm(fac[maxn],MOD-2);
	for(int i=maxn-1;i>=0;i--)inc[i]=inc[i+1]*(i+1)%MOD;
	scanf("%d",&n);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		solve(a[i]);
		s.push(a[i]);
	}
	solve(-1);
	cout<<ans;
	return 0;
}
