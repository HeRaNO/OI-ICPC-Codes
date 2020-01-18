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

int main()
{
	int n;
	puts("YES");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,d,p;
		scanf("%d%d%d%d",&x,&y,&d,&p);
		int ans=1;
		if(x&1)ans+=1;
		if(y&1)ans+=2;
		printf("%d\n",ans);
	}
	return 0;
}