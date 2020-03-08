#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e6+10,MAXM=1e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;
#define pb push_back

int fa[MAXN],n;
int _find(int x)
{
	return x^fa[x]?fa[x]=_find(fa[x]):fa[x];
}
vector<int> vec,a[MAXN];

struct Node
{
	int a,b,c;
};
vector<Node> ans;
vector<int> b[MAXN];

void _union(int u,int v,int w)
{
	int xu=_find(u),xv=_find(v);
	if(xu!=xv)
	{
		fa[xu]=xv;
		ans.push_back({u,v,w});
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int p;
			scanf("%d",&p);
			a[i].push_back(p);
			vec.push_back(p);
		}
	}
	sort(ALL(vec));
	vec.resize(unique(ALL(vec))-vec.begin());
	for(int i=1;i<=n;i++)
	{
		for(auto j:a[i])
		{
			int p=lower_bound(ALL(vec),j)-vec.begin();
			b[p].push_back(i);
		}
	}
	for(int i=0;i<SZ(vec);i++)
	{
		for(int j=1;j<SZ(b[i]);j++)
		{
			_union(b[i][j],b[i][0],vec[i]);
		}
	}
	if(SZ(ans)==n-1)
	{
		for(auto j:ans)printf("%d %d %d\n",j.a,j.b,j.c);
	}
	else puts("impossible");
	return 0;
}
