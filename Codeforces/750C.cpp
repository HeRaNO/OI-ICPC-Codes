#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,MOD=1e9+7;
const ll llINF=~(1ll<<63);

int ans=0,n,p;
int c[MAXN],d[MAXN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
		if(d[i]==2)p=1;
	}
	if(!p)return puts("Infinity"),0;
	int l=-INF,r=INF,q=0,ans=INF;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==2)l=max(l,q);
		else r=min(r,q);
		q+=c[i];
	}
	if(r<=l)return puts("Impossible"),0;
	printf("%d",1899-l+q);
	return 0;
}