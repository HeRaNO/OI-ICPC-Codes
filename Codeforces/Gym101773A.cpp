#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=3e5+10,INF=~(1<<31),MOD=1e9+7,mod=998244353;
const ll llINF=~(1ll<<63);
#define lowbit(x) x&-x

int dfs(int n,int dep)
{
	if(!n)return dep;
	int ans=dep;
	for(int i=32;i;i--)
	{
		ll m=(1ll<<i);
		if(n%m>m/2)
		{
			ans=max(ans,dfs(n/m,dep+1));
		}
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int ans=0;
	printf("%d\n",dfs(n,0));
	return 0;
}