#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (u<<1)
#define rs (u<<1|1)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n,k;

int get_SG(int a)
{
	if(a==0)return 0;
	if(a==1)return 1;
	if(k%2==0)
	{
		if(a==2)return 2;
		if(a&1)return 0;
		return 1;
	}
	else
	{
		if(a==3)return 1;
		if(a&1)return 0;
	}
	bool vis[3];
	memset(vis,0,sizeof(vis));
	vis[get_SG(a-1)]=1;
	vis[get_SG(a/2)]=1;
	for(int i=0;;i++)if(!vis[i])return i;
}

int Test()
{
	while(1)
	{
		int a;
		cin>>a>>k;
		cout<<get_SG(a)<<endl;
	}
}

int main()
{
	//Test();
	int ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		ans^=get_SG(a);
	}
	if(ans)puts("Kevin");
	else puts("Nicky");
	return 0;
}
