#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
typedef long long ll;
typedef double db;
typedef pair<db,ll> pii;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n,k;
ll lc,pc,lm,pm;
ll t,d;
ll a[MAXN];
int l,r,loc;
ll p,q,ans=llINF,res;

void add(int i)
{
	p-=max(lm-a[i],0ll);
	p+=max(lc-a[i],0ll);
	q-=min(max(a[i]-lm,0ll),d);
	q+=min(max(a[i]-lc,0ll),d);
}

void add2(int i)
{
	p-=max(lm-a[i],0ll);
	q-=min(max(a[i]-lm,0ll),d);
	q+=min(max(a[i]-1,0ll),d);
}

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%lld%lld%lld%lld",&lc,&pc,&lm,&pm);
	scanf("%lld%lld",&t,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<ll>());
	for(int i=1;i<=n;i++)
	{
		if(lm-a[i]>d&&!loc)loc=i;
		p+=max(lm-a[i],0ll);
		q+=min(max(a[i]-lm,0ll),d);
	}
	l=0,r=n+1;
	if(q>=p&&!loc)ans=min(ans,p*t+n*pm);
	for(int i=0;i<n;i++)
	{
		add(++l);
		for(int j=1;j<=k-1;j++)
		{
			if(r-1>l)add2(--r);
			else break;
		}
		if(p>q)continue;
		if((l>=loc||r>loc)&&loc)continue;
		res=l*pc+max(0,r-l-1)*pm+p*t;
		ans=min(ans,res);
	}
	if(ans==llINF)puts("-1");
	else printf("%lld",ans);
	return 0;
}