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
const double Pi=acos(-1);

int n;
map<char,int>mp;

int solve()
{
	int ans=0,p=0,m=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char s[2];
		scanf("%s",s);
		if(s[0]=='B')m=1;
		if(s[0]=='C')p=1;
		ans+=mp[s[0]];
	}
	if(!m||!p)ans--;
	return max(1,ans);
}

int main()
{
	mp['A']=16;
	mp['B']=7;
	mp['C']=8;
	mp['D']=1;
	mp['E']=1;
	mp['F']=2;
	mp['G']=3;
	int t,kase=0;
	scanf("%d",&t);
	while(t--)
	{
		int a=solve(),b=solve();
		if(a==b)puts("tie");
		else if(a>b)puts("red");
		else puts("black");
	}
	return 0;
}