#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=1e5+10,MAXM=1e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

int n,lst[MAXN],p[MAXN],cnt[MAXN],ans=1;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),cnt[i]=1;
	for(int i=1;i<=n;i++)
	{
		if(lst[p[i]-1])
		{
			cnt[p[i]]=cnt[p[i]-1]+1;
		}
		ans=max(ans,cnt[p[i]]);
		lst[p[i]]=i;
	}
	printf("%d\n",n-ans);
	return 0;
}
