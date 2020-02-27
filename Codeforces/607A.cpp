
#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,biszeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair((a),(b))
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=100050;
int n;
int id[N*10],s[N*10];
struct beacon
{
	int a,b;
	bool operator < (const beacon &x)const
	{
		return a<x.a;
	}
}p[N];
int dp[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].a);p[i].a++;
		scanf("%d",&p[i].b);
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i)id[p[i].a]=i;
	for(int i=1;i<=1000001;++i)s[i]=s[i-1]+(id[i]>0);
	int now=0;
	for(int i=1;i<=1000001;++i)
	{
		if(id[i]){continue;}
		id[i]=id[i-1];
	}
//    for(int i=1;i<=10;++i)printf("%d ",id[i]);cout<<endl;
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[id[max(0,p[i].a-p[i].b-1)]]+s[max(0,p[i].a-1)]-s[max(0,p[i].a-p[i].b-1)];
	}
	int ans=inf;
	for(int i=0;i<=n;++i)
	{
//        printf("%d\n",dp[i]);
		ans=min(ans,dp[i]+n-i);
	}
	cout<<ans<<endl;
	return 0;
}
