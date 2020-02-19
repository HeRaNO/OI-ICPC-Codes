#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int n;
int x[MAXM],y[MAXM];
ll a[MAXM],b[MAXM];
vector<int> aa,bb;
ll ans=0;
map<pii,int>mp;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		aa.push_back(x[i]);
		bb.push_back(y[i]);
		ans-=mp[{x[i],y[i]}];
		mp[{x[i],y[i]}]++;
	}
	sort(aa.begin(),aa.end());
	sort(bb.begin(),bb.end());
	aa.resize(unique(aa.begin(),aa.end())-aa.begin());
	bb.resize(unique(bb.begin(),bb.end())-bb.begin());
	for(int i=1;i<=n;i++)
	{
		a[lower_bound(aa.begin(),aa.end(),x[i])-aa.begin()]++;
		b[lower_bound(bb.begin(),bb.end(),y[i])-bb.begin()]++;
	}
	for(int i=0;i<SZ(aa);i++)ans+=a[i]*(a[i]-1)/2;
	for(int i=0;i<SZ(bb);i++)ans+=b[i]*(b[i]-1)/2;
	cout<<ans;
	return 0;
}
