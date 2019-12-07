#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,MOD=1e9+7;
const ll llINF=~(1ll<<63);

int n,m;
int a[105][105];
int tmp[105];
int cnt[105];
vector<pii> t;
vector<int> ans;
bool vis[105];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j][i]);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
			tmp[j]=a[n][j]-a[i][j];
		sort(tmp+1,tmp+m+1);
		int ans=0;
		for(int j=1;j<=m;j++)
		{
			if(ans+tmp[j]>0)break;
			cnt[i]++;
			ans+=tmp[j];
		}
	}
	int id=0,res=0;
	for(int i=1;i<n;i++)
		if(cnt[i]>cnt[id])id=i;
	for(int i=1;i<=m;i++)
		t.push_back({a[n][i]-a[id][i],i});
	sort(t.begin(),t.end());
	for(auto j:t)
	{
		if(res+j.first>0)break;
		ans.push_back(j.second);
		res+=j.first;
	}
	for(auto j:ans)
		vis[j]=1;
	cout<<m-ans.size()<<endl;
	for(int i=1;i<=m;i++)
		if(!vis[i])printf("%d ",i);
	return 0;
}