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
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=3e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const double Pi=acos(-1);

struct Node
{
	int a,b;
	bool operator < (const Node &rhs)const
	{
		return a<rhs.a;
	}
}e[MAXN];
int kase;
void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&e[i].a);
	for(int i=1;i<=n;i++)scanf("%d",&e[i].b);
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)
	{
		if(m-e[i].b<0)break;
		m-=e[i].b;
		ans++;
	}
	printf("Case %d: %d\n",++kase,ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
