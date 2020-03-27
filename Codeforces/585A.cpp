#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n;
ll v[MAXN],d[MAXN],p[MAXN],sum;
priority_queue<int,vector<int>,greater<int> >pq;
vector<int> ans;
bool vis[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&v[i],&d[i],&p[i]);
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		ans.pb(i);
		int cnt=v[i];
		for(int j=i+1;j<=n&&cnt>0;j++)
		{
			if(vis[j])continue;
			p[j]-=cnt--;
		}
		sum=0;
		for(int j=i+1;j<=n;j++)
		{
			p[j]-=sum;
			if(p[j]<0&&!vis[j])
			sum+=d[j],vis[j]=1;
		}
	}
	printf("%d\n",SZ(ans));
	for(auto j:ans)cout<<j<<" ";
	return 0;
}
