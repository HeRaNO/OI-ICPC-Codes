#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=1e6+10,MAXM=1e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

map<string,int> mp;
string ans;

int main()
{
	std::ios::sync_with_stdio(false);
	string tmp;
	ans="NONE";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		mp[tmp]++;
		int val=mp[tmp];
		if(val>n/2)ans=tmp;
	}
	cout<<ans<<endl;
	return 0;
}
