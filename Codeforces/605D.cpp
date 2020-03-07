#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e5+10,MAXM=1e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

vector<int> vec,tmp;
map<int,int>mp;
int n,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int dis[MAXN],pre[MAXN];
queue<int> q;
stack<int>ans;
set<pii> tr[MAXN];

void add(int u,int x)
{
	for(;u<=SZ(vec);u+=lowbit(u))
		tr[u].insert({b[x],x});
}

void query(int u,int x)
{
	for(;u;u-=lowbit(u))
	{
		while(!tr[u].empty())
		{
			pii j=*tr[u].begin();
			if(j.fi>d[x])break;
			tmp.push_back(j.se);
			tr[u].erase(tr[u].begin());
		}
	}
}


void bfs()
{
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int sz=mp[c[u]];
		tmp.clear();
		query(sz,u);
		for(auto j:tmp)
		{
			if(!dis[j])
			{
				dis[j]=dis[u]+1;
				pre[j]=u;
				q.push(j);
			}
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	for(int i=1;i<=n;i++)vec.push_back(a[i]),vec.push_back(c[i]);
	vec.push_back(0);
	sort(ALL(vec));
	vec.resize(unique(ALL(vec))-vec.begin());
	for(int i=0;i<SZ(vec);i++)mp[vec[i]]=i+1;
	for(int i=1;i<=n;i++)
	{
		int q=mp[a[i]];
		add(q,i);
	}
	bfs();
	if(!dis[n])return puts("-1"),0;
	printf("%d\n",dis[n]);
	for(int i=n;i;i=pre[i])ans.push(i);
	while(!ans.empty())printf("%d ",ans.top()),ans.pop();
	return 0;
}
