#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=2e5+10;
const int MOD=1e9+7;
const ll llINF=~(1ll<<63);

struct Node
{
	int x,y,z,r,id;
}e[105];

bool cmp(Node a,Node b)
{
	return a.r>b.r;
}

vector<int> v[105];

bool cross(Node a,Node b)
{
	ll tmp=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
	if(tmp<(a.r+b.r)*(a.r+b.r))return true;
	return false;
}

bool vis[105];
int p[105];

void dfs(int u)
{
	vis[u]=1;
	if(p[u]==-1)
	{
		for(int i=0;i<v[u].size();i++)if(!vis[v[u][i]])dfs(v[u][i]);
		return;
	}
	int maxn=e[u].r,mx=u;
	for(int i=0;i<v[u].size();i++)
	{
		if(e[v[u][i]].r>maxn&&p[v[u][i]]!=-1)
		{
			maxn=e[v[u][i]].r;
			mx=v[u][i];
		}
	}
	for(int i=0;i<v[u].size();i++)
		if(e[v[u][i]].r==maxn&&p[v[u][i]]==1)mx=v[u][i];
	p[mx]=1;
	for(int i=0;i<v[u].size();i++)if(!p[v[u][i]])p[v[u][i]]=-1;
	for(int i=0;i<v[u].size();i++)if(!vis[v[u][i]])dfs(v[u][i]);
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].z,&e[i].r);
		e[i].id=i;
	}
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(cross(e[i],e[j]))
			{
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(p[i]==1)cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(p[i]==1)cout<<e[i].id<<" ";
	return 0;
}