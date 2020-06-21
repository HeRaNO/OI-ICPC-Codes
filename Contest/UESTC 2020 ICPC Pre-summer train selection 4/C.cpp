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
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const db Pi=acos(-1);

int T,n,s,f,t,ans;

int main()
{
    //freopen("03.in","r",stdin);
    //freopen("03.out","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		scanf("%d %d",&n,&s);ans=1<<31;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&f,&t);
			if (t<=s) ans=max(ans,f);
			else ans=max(ans,f-t+s);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}