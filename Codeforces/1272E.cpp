#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=3e6+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;

int a[MAXN];

vector<int> g[MAXN];
vector<int> v[MAXN];

int val[MAXN],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]+i<=n)
		{
			g[a[i]+i].push_back(i);
			if((a[i+a[i]]&1)!=(a[i]&1))
			val[i]=1;
		}
		if(i-a[i]>0)
		{
			g[i-a[i]].push_back(i);
			if((a[i-a[i]]&1)!=(a[i]&1))
			val[i]=1;
		}
	}
	for(int i=1;i<=n;i++)if(val[i])v[1].push_back(i);
	for(int i=1;i<=n+5;i++)
	{
		for(auto j:v[i])
		{
			for(auto k:g[j])
			{
				if(!val[k])val[k]=i+1;
				if(val[k]==i+1)v[i+1].push_back(k);
			}
		}
	}
	for(int i=1;i<=n;i++)if(!val[i])val[i]=-1;
	for(int i=1;i<=n;i++)
		printf("%d ",val[i]);
	return 0;
}
