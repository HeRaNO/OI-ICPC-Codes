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
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=3e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int a[MAXN];
int n,b,c;
bool vis[MAXN];

int main()
{
	scanf("%d%d%d",&n,&b,&c);
	for(int i=1;i<=c;i++)
	{
		int p;
		scanf("%d",&p);
		vis[p]=1;
	}
	a[1]=b&1;
	b-=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]==0&&a[i+1]==0&&!vis[i])a[i]=1,b-=2;
		if(!b)break;
	}
	for(int i=1;i<=n;i++)printf("%d",a[i]);
	return 0;
}
