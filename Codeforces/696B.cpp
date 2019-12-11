#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e5+10,MAXM=2e6+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;

int cnt[MAXN];
vector<int>son[MAXN];
double e[MAXN];

int dfs(int cur)
{
	cnt[cur]=1;
	for(auto j:son[cur])
	{
		cnt[cur]+=dfs(j);
	}
	return cnt[cur];
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int pa;
		scanf("%d",&pa);
		son[pa].push_back(i);
	}
	dfs(1);
	e[1]=1;
	for(int i=1;i<=n;i++)
	{
		for(auto j:son[i])
		{
			e[j]=((double)cnt[i]-cnt[j]-1)/2.0+e[i]+1;
		}
		printf("%.6lf ",e[i]);
	}
}