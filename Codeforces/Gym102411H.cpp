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
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int sum[MAXN],pos[MAXN],cnt[MAXN],n,a[MAXN],mx;

int solve(int p)
{
	if(cnt[p])return cnt[p];
	if(p<mx)return 0;
	int now=0;
	while(now<n)
	{
		int q=sum[now]+p;
		now=pos[q];
		cnt[p]++;
	}
	return cnt[p];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		sum[i]=sum[i-1]+a[i];
		for(int j=sum[i-1];j<sum[i];j++)pos[j]=i-1;
	}
	for(int i=sum[n];i<=1e6+sum[n];i++)pos[i]=n;
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int q;scanf("%d",&q);
		int p=solve(q);
		if(p)printf("%d\n",p);
		else puts("Impossible");
	}
	return 0;
}
