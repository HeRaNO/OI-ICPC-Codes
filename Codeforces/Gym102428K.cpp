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

char s[MAXN];
vector<int> v;
ll ans[MAXN];

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=2;i<=n;i++)
	{
		if(s[i]!=s[i-1])v.pb(i*2-1);
	}
	printf("%d\n",SZ(v));
	ans[0]=1;
	if(s[n]=='A')ans[0]=-1;
	for(int i=0;i<SZ(v);i++)
	{
		for(int j=i+1;~j;j--)ans[j]=ans[j-1]-ans[j]*v[i];
	}
	for(int i=SZ(v);~i;i--)printf("%lld ",ans[i]);
	return 0;
}
