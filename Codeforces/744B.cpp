#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define lowbit(x) x&-x
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=3e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int n;
int tag[MAXN];
int ans[MAXN];

void ask()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=tag[i];
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		if(tag[i])printf("%d ",i);
	puts("");
	fflush(stdout);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(!tag[i])ans[i]=min(ans[i],tmp);
	}
}

int main()
{
	memset(ans,0x3f,sizeof(ans));
	scanf("%d",&n);
	for(int i=0;i<10&&(1<<i)<n;i++)
	{
		int p=(1<<i);
		for(int j=1;j<=n;j++)
			tag[j]=((p&j)>0);
		ask();
		for(int j=1;j<=n;j++)
			tag[j]^=1;
		ask();
	}
	printf("-1\n");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}