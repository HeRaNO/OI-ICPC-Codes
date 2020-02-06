#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=119;
const int Lim=1<<20;

char s[MAXN],t[MAXN];
int a[MAXN],n,m;
bool ok[MAXN];

bool check(int u)
{
	memset(ok,0,sizeof(ok));
	for(int i=u+1;i<=n;i++)ok[a[i]]=1;
	int p=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==t[p]&&ok[i])p++;
	}
	return p>m;
}

int main()
{
	scanf("%s%s",s+1,t+1);n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
