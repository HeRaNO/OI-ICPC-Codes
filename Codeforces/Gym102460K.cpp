#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

priority_queue<int,vector<int>,greater<int> > p;

void solve()
{
	int n,i,a,c,b;
	long long ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b);
		p.push(b);
	}
	while(p.size()!=1)
	{
		a=p.top();
		p.pop();
		b=p.top();
		p.pop();
		ans+=a+b;
		p.push(a+b);
	}
	while(!p.empty())p.pop();
	printf("%lld\n",ans);
}

int main()
{
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
