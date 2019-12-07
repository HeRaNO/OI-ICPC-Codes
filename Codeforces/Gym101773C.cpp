#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=3e5+10,INF=~(1<<31),MOD=1e9+7,mod=998244353;
const ll llINF=~(1ll<<63);
#define lowbit(x) x&-x

vector<int> v1,v2;
int a[2];

int main()
{
	ll n,h;
	scanf("%lld%lld",&n,&h);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v1.push_back(x+y);
		v2.push_back(x-y);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	v1.resize(unique(v1.begin(),v1.end())-v1.begin());
	v2.resize(unique(v2.begin(),v2.end())-v2.begin());
	ll ans=h*(v1.size()+v2.size());
	int l=0,r=-1;
	for(auto i:v1)
	{
		while(r+1<v2.size()&&v2[r+1]<=i)
		{
			r++;
			a[v2[r]&1]++;
		}
		while(l<v2.size()&&v2[l]<=i-h*2+1)
		{
			a[v2[l]&1]--;
			l++;
		}
		ans-=a[i&1];
	}
	cout<<ans-n;
	return 0;
}