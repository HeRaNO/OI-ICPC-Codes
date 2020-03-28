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
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

vector<int> v;
int a[MAXN],cnt[MAXN];

int low(int u)
{
	auto it=lower_bound(ALL(v),u);
	if(it==v.end())return -1;
	if(*it!=u)return -1;
	return it-v.begin();
}

void solve()
{
	int n;
	scanf("%d",&n);
	memset(cnt,0,(n+5)*sizeof(int));
	v.resize(0);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.pb(a[i]);
	sort(ALL(v));
	v.resize(unique(ALL(v))-v.begin());
	cnt[low(a[1])]++;
	ll ans=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int p=low(a[i]*2-a[j]);
			if(p!=-1)
			ans+=cnt[p];
		}
		cnt[low(a[i])]++;
	}
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
