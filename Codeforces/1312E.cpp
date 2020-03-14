#include <bits/stdc++.h>
#define MAXN 505
#define MAXM 1505
#define fi first
#define se second
using namespace std;

int n,a[MAXN],dp[MAXN];
vector <pair<int,int> > v[MAXM],w;

int main()
{
	scanf("%d",&n);memset(dp,0x3f,sizeof dp);dp[0]=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]].push_back({i,i});
	for (int i=1;i<=1500;i++)
	{
		sort(v[i].begin(),v[i].end());
		for (auto j:v[i])
		{
			pair <int,int> l={j.se+1,-1};
			auto it=lower_bound(v[i].begin(),v[i].end(),l);
			if (it==v[i].end())continue;
			pair <int,int> k=*it;
			if(k.fi==j.se+1) v[i+1].push_back({j.fi,k.se});
		}
	}
	for (int i=1;i<=1500;i++)
		for (auto j:v[i]) w.push_back(j);
	sort(w.begin(),w.end());
	for (auto j:w) dp[j.se]=min(dp[j.se],dp[j.fi-1]+1);
	printf("%d\n",dp[n]);
	return 0;
}