#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=3e6+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;

int a[MAXN];

int main()
{
	int n,m,k=INF;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		k=min(k,r-l+1);
	}
	printf("%d\n",k);
	for(int i=1;i<=n;i++) printf("%d ",i%k);
	return 0;
}