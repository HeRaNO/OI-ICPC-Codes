#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=500050;
int n,k;ll ans=LLONG_MAX;
int c[N];

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		int x;scanf("%d",&x);
		c[x]++;
	}
	sort(c+1,c+k+1,greater<int>());
	int mx=0;
	for(int i=1,j=k;i<=j;++i,--j)
	{
		if(i!=j)mx=max(mx,c[i]+c[j]);
		else mx=max(c[i],mx);
	}
	for(int i=c[1];i<=mx;++i)
	{
		int p1=1,p2=k;
		int cnt=0;
		while(p1<=p2)
		{
			++cnt;
			if(p1<p2&&c[p1]+c[p2]<=i)p1++,p2--;
			else p1++;
		}
		ans=min(ans,1LL*cnt*i);
	}
	cout<<ans<<endl;
	return 0;
}
