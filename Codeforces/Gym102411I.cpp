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
const int MAXN=5e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

void solve()
{
	int n,l=INF,r=-INF,u=-INF,d=INF;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,h;
		scanf("%d%d%d",&x,&y,&h);
		l=min(l,x-h);r=max(r,x+h);
		u=max(u,y+h);d=min(d,y-h);
	}
	int p=max(r-(l+r)/2,u-(u+d)/2),q=max((l+r)/2-l,(u+d)/2-d);
	printf("%d %d %d",(l+r)/2,(u+d)/2,max(p,q));
}

int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--)solve();
	return 0;
}
