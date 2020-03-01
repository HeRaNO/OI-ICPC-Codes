#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e5+10,MAXM=2e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

ll mxl=0;
ll ans;
int n;

struct Node
{
	ll w,l;
	bool operator < (const Node &rhs)const
	{
		return w^rhs.w?w>rhs.w:l>rhs.l;
	}
}e[MAXN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&e[i].w,&e[i].l);
		if(e[i].w<e[i].l)swap(e[i].w,e[i].l);
		ans=max(ans,e[i].w*e[i].l);
	}
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,e[i].w*min(mxl,e[i].l)*2);
		mxl=max(mxl,e[i].l);
	}
	printf("%lld",ans/2);
	if(ans&1)puts(".5");
	else puts(".0");
	return 0;
}
