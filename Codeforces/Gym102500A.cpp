#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=2e6+10,MAXM=1e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n,w;

vector<ll> tmp;
ll val[MAXN],rk[MAXN];

set<ll,greater<ll> >score;
set<pii> id[MAXN];
double ans[MAXN];
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		score.insert(0);
		id[0].insert({i,0});
	}
	for(int i=1;i<=w;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int p;
			scanf("%d",&p);
			auto it=id[val[p]].upper_bound({p,-1});
			id[val[p]+1].insert({p,it->se+rk[val[p]]-rk[val[p]+1]});
			id[val[p]].erase(it);
			if(!SZ(id[val[p]]))score.erase(val[p]);
			score.insert(val[p]+1);
			val[p]++;
		}
		ll now=1;
		for(auto j:score)
		{
			rk[j]+=now;
			now+=SZ(id[j]);
		}
	}
	for(auto j:score)
	{
		for(auto k:id[j])ans[k.fi]=(db)(k.se+rk[j])/w;
	}
	for(int i=1;i<=n;i++)printf("%.12lf\n",ans[i]);
	return 0;
}
