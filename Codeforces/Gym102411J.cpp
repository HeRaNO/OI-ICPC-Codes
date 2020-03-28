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

int n,a[505][505],ans[505][505];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%1d",&a[i][j]);
	for(int i=n-1;i;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			int res=0;
			for(int k=i+1;k<j;k++)(res+=a[i][k]*ans[k][j])%=10;
			if(res!=a[i][j])ans[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)printf("%d",ans[i][j]);
	return 0;
}
