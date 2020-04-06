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
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

char s[MAXN];
int a[MAXN],b[MAXN];
int n;
vector<string> v;

void dfs(int u)
{
	if(u==n)
	{
		for(int i=n;i<n*2;i++)
		{
			int ans=0;
			for(int j=i-n+1;j<n;j++)ans+=b[j]*b[i-j];
			if(ans%10!=a[i])return;
		}
		string s;
		s.clear();
		for(int i=n-1;~i;i--)s+=b[i]+'0';
		v.push_back(s);
		return;
	}
	int ans=0;
	for(int i=1;i<u;i++)ans+=b[i]*b[u-i];
	ans%=10;
	for(int i=0;i<=9;i++)
	{
		b[u]=i;
		if(u==0)
		{
			if((ans+i*i)%10==a[u])
			dfs(u+1);
		}
		else if((ans+i*b[0]*2)%10==a[u])dfs(u+1);
	}
	return;
}

int main()
{
	scanf("%s",s);
	n=strlen(s);
	if(n%2==0)return puts("-1"),0;
	reverse(s,s+n);
	for(int i=0;i<n;i++)a[i]=s[i]-'0';
	n=n/2+1;
	dfs(0);
	if(!SZ(v))cout<<"-1";
	else cout<<*min_element(ALL(v));
	return 0;
}
