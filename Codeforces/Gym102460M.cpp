#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair((a),(b))
#define pb(x) push_back(x)
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e7;
const int MAXN=N;
inline ll mi(ll a,ll b,ll MOD)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret=ret*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return ret;
}
/*
	China Remainer Theory is an algorithm to solve linear congruent equations.Like:
	x==a1 (mod m1)
	x==a2 (mod m2)
	...
	x==an (mod mn)
	Each a is coprime.
	If not,you should use exCRT(n).
	By using CRT(n),you can get the minimum solution of the equations.
*/
long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long ret = exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - (a / b) * y;
	return ret;
}
long long a[MAXN], mo[MAXN];
inline long long CRT(int n)
{
	long long M = 1, ret = 0;
	for (int i = 1; i <= n; i++) M *= mo[i];
	for (int i = 1; i <= n; i++)
	{
		long long w = M / mo[i], x, y;
		exgcd(w, mo[i], x, y);
		x = (x % mo[i] + mo[i]) % mo[i];
		ret = (ret + x * w % M * a[i] % M) % M;
	}
	return (ret + M) % M;
}
inline ll inv(ll a,ll p)
{
	ll x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}
inline ll jie(ll a,ll p)
{
	ll ret=0;while(a){ret+=a/p;a/=p;}return ret;
}
inline ll C(ll n,ll m,ll p){return jie(n,p)-jie(m,p)-jie(n-m,p);}


ll m,n,mod,k=LLONG_MAX,fac[N],fac2[N];
ll P[N],cnt[N];int tot;
inline void Init()
{
	ll x=mod;
	for(ll i=2;i<=sqrt(x);++i)
	{
		if(x%i!=0)continue;
		P[++tot]=i;mo[tot]=1;
		while(x%i==0)cnt[tot]++,x/=i,mo[tot]*=i;
	}
	if(x>1){P[++tot]=x;mo[tot]=x;cnt[tot]=1;}
}
ll dfs(ll n,ll p1,ll p2)
{
	if(n==0)return 1;
	ll ret=mi(fac2[p2],n/p2,p2)*fac2[n%p2]%p2;
	return ret*dfs(n/p1,p1,p2)%p2;
}
inline ll cal(ll p1,ll p2)
{
	fac2[0]=1;
	for(ll i=1;i<=p2;++i)
	{
		fac2[i]=fac2[i-1]*((i%p1>0)?i:1LL)%p2;
	}
	return dfs(n,p1,p2)*inv(dfs(m,p1,p2),p2)%p2*inv(dfs(n-m,p1,p2),p2)%p2;
}

int main()
{
	scanf("%lld%lld%lld",&n,&m,&mod);
	Init();
	for(int i=1;i<=tot;++i)
	{
		fac[i]=C(n,m,P[i]);
		k=min(k,fac[i]/cnt[i]);
	}
	for(int i=1;i<=tot;++i)
	{
		a[i]=cal(P[i],mo[i])*mi(P[i],fac[i]-k*cnt[i],mo[i])%mo[i]*mi(inv(mod/mo[i],mo[i]),k,mo[i])%mo[i];
	}
	ll ans=CRT(tot);
	cout<<ans<<endl;
	return 0;
}
