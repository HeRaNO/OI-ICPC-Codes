#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define flush fflush(stdout)
#define pb(x) push_back(x)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=400050;
int n;
int a[N],b[N];
int ans;
int solve(int bit)
{
	for(int i=1;i<=n;++i)b[i]=(a[i]%(1<<(bit+1)));
	sort(b+1,b+n+1);
	ll tmp=0;
	for(int i=1;i<=n;++i)
	{
		tmp+=upper_bound(b+1,b+n+1,(1<<(bit+1))-1-b[i])
			-lower_bound(b+1,b+n+1,(1<<bit)-b[i])
			+upper_bound(b+1,b+n+1,inf)
			-lower_bound(b+1,b+n+1,(1<<bit)+(1<<(bit+1))-b[i]);
		if((b[i]<<1)>=(1<<bit)&&(b[i]<<1)<(1<<(bit+1)))tmp--;
		if((b[i]<<1)>=(1<<bit)+(1<<(bit+1)))tmp--;
	}
	return (tmp/2)%2;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=0;i<=25;++i)
	{
		int t=solve(i);
		if(t==1)ans+=(1<<i);
	}
	printf("%d\n",ans);
	return 0;
}
