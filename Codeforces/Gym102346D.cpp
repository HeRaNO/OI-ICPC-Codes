#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
using namespace std;
const int N=300050;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int n,k,dep[N],ans;
vector <int> e[N];
priority_queue <int> pq;

void dfs(int u,int fa)
{
	priority_queue <int> q;
	q.push(dep[u]);
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		q.push(dep[v]+1);
	}
	dep[u]=q.top(),q.pop();
	while(!q.empty())
	{
		pq.push(q.top()-1);
		q.pop();
	}
}

int main()
{
	cin>>n>>k;
	for(int i=2;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		e[x].push_back(i);
		e[i].push_back(x);
	}
	dfs(1,0);
	pq.push(dep[1]);
	int siz=pq.size();
	for(int i=1;i<=min(siz,k);++i)ans+=pq.top()+1,pq.pop();
	cout<<ans<<endl;
	return 0;
}
