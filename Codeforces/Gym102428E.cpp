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
int n;
ll ans;

int main()
{
	int r=0;
	scanf("%s",s+1);
	scanf("%d",&n);
	int sz=strlen(s+1);
	for(int i=1;i<=sz;i++)s[i+sz]=s[i];
	for(int i=1;i<=sz*2;i++)
	{
		if(s[i]=='E')r=max(r,i);
		if(i>=n&&i<n+sz)
		{
			ans+=max(n-i+r,0);
		}
	}
	cout<<ans;
	return 0;
}
