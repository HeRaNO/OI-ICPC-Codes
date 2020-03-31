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
typedef double db;
typedef pair<db,ll> pii;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n;
multiset<int> s;
vector<int> ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*n;i++)
	{
		int j;scanf("%d",&j);s.insert(j);
	}
	for(int i=1;i<=n;i++)
	{
		int p=*s.rbegin();
		s.erase(s.find(p));
		for(auto j:ans)
		{
			s.erase(s.find(__gcd(p,j)));
			s.erase(s.find(__gcd(p,j)));
		}
		ans.pb(p);
	}
	for(auto j:ans)cout<<j<<" ";
	return 0;
}
