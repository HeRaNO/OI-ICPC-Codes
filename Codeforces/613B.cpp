#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100050;
const ll mod=1e9+7;
int n;
ll A,cf,cm,m;
ll b[N],sum[N],mn=inf;
ll ans=-1;
int pos1=200000,pos2;
vector <int> v;
struct number
{
	ll num;
	int pos;
}a[N];
bool cmp1(const number &x,const number &y){return x.num<y.num;}
bool cmp2(const number &x,const number &y){return x.pos<y.pos;}

inline int check2(ll x,ll used)
{
	int L2=1,R2=n-used,ret2=0;
	while(L2<=R2)
	{
		int mid2=(L2+R2)>>1;
		if(a[mid2].num<=x)ret2=mid2,L2=mid2+1;
		else R2=mid2-1;
	}
	return ret2;
}

inline bool check(ll x,ll used)
{
	pos2=check2(x,used);
	if(x*pos2-sum[pos2]<=m-(A*used-(sum[n]-sum[n-used])))
		return true;
	else return false;
}

inline ll Search(ll used)
{
	if(A*used-(sum[n]-sum[n-used])>m)return -1;
	ll L=a[1].num,R=A,ret=0;
	while(L<=R)
	{
		ll mid=(L+R)>>1;
		if(check(mid,used))L=mid+1,ret=mid;
		else R=mid-1;
	}
	return ret;
}

int main()
{
	cin>>n>>A>>cf>>cm>>m;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i].num),a[i].pos=i;
	sort(a+1,a+n+1,cmp1);mn=a[1].num;
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i].num;
	a[n+1].num=-1;
	for(int i=1;i<=n;++i)if(a[i].num!=a[i+1].num)v.push_back(i);
	for(ll i=0;i<=n;++i)
	{
		ll t=Search(i);
		ll tmp=t*cm+cf*i;
		if(t==-1)continue;
		if(tmp>ans)
		{
			ans=tmp;
			mn=t;
			pos1=i;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(i>=n-pos1+1)a[i].num=A;
		else if(a[i].num<=mn)a[i].num=mn;
	}
	ans=0;pos1=pos2=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i].num==A)pos1++;
		if(a[i].num==mn)pos2++;
	}
	ans=pos1*cf+mn*cm;
	printf("%lld\n",ans);
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;++i)printf("%lld ",a[i].num);
	return 0;
}