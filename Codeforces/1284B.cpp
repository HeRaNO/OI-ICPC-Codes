#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define lowbit(x) x&-x
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int mx[MAXN],mi[MAXN];
int q[MAXN];
ll cnt=0;

int main()
{
	int n;
	memset(mi,0x3f,sizeof(mi));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int l,m=INF;
		scanf("%d",&l);
		for(int j=1;j<=l;j++)
		{
			int x;
			scanf("%d",&x);
			x++;
			m=min(m,x);
			if(x>m)m=-1;
			mx[i]=max(mx[i],x);
			mi[i]=min(mi[i],x);
		}
		if(m==-1)
		{
			mi[i]=1e6+5;
			cnt++;
			mx[i]=0;
		}
	}
	for(int i=1;i<=n;i++)q[mi[i]]++;
	for(int i=1;i<=1e6+2;i++)q[i]+=q[i-1];
	ll ans=0;
	for(int i=1;i<=cnt;i++)ans+=(n-i+1);
	ans<<=1;
	ans-=cnt;
	for(int i=1;i<=n;i++)
	{
		if(mx[i])ans+=q[mx[i]-1];
	}
	cout<<ans;
	return 0;
}