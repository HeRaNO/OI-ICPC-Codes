#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e5+10,MAXM=2e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

void solve()
{
	int a,b,c,ans;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a+b+c;i++)
	{
		int aa=a,bb=0,cc=c;
		if(aa>i)bb=aa-i,aa=i;
		if(cc>i)
		{
			if(bb)continue;
			bb=cc-i;
			cc=i;
		}
		if(aa>i||bb>i||cc>i)continue;
		if(aa+bb+cc+b>i*3)continue;
		ans=i;
		break;
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
