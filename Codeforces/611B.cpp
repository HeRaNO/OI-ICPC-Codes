#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=8e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=998244353,mod=119;
const int Lim=1<<20;

int a[MAXN];
vector<ll>g;

int main()
{
	for(int i=1;i<63;i++)
	{
		ll p=0;
		for(int j=0;j<=i;j++)
		{
			p|=(1ll<<j);
		}
		for(int j=0;j<i;j++)
		{
			p^=(1ll<<j);
			g.push_back(p);
			p^=(1ll<<j);
		}
	}
	sort(g.begin(),g.end());
	ll a,b;
	cin>>a>>b;
	printf("%d\n",(int)(upper_bound(g.begin(),g.end(),b)-lower_bound(g.begin(),g.end(),a)));
	return 0;
}
