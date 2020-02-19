#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair((a),(b))
using namespace std;
const int inf=0x3f3f3f3f;
const int N=500050;
const ll mod=1e9+7;
int n;
ll a,b,T;
char s[N];
ll sum[N];

int main()
{
	cin>>n>>a>>b>>T;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+1;
		if(s[i]=='w')sum[i]+=b;
	}
	int ans=0;
	if(sum[1]>T)return puts("0"),0;
	else ans=1;
	for(int l=n;l>1;--l)
	{
		if(a*(n-l+1)+sum[1]+sum[n]-sum[l-1]>T)break;
		int c=n-l+2;
		int L=1,R=l-1,tmp=0;
		ll now=a*(n-l+1)*2+sum[n]-sum[l-1];
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if(now+sum[mid]+a*(mid-1)<=T)tmp=mid,L=mid+1;
			else R=mid-1;
		}
		if(tmp!=0)ans=max(ans,c+tmp-1);
		else ans=max(ans,c);
	}
	for(int r=1;r<=n;++r)
	{
		if(a*(r-1)+sum[r]>T)break;
		int c=r;
		int L=r+1,R=n,tmp=0;
		ll now=a*2*(r-1)+sum[r];
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if(now+sum[n]-sum[mid-1]+a*(n-mid+1)<=T)tmp=mid,R=mid-1;
			else L=mid+1;
		}
		if(tmp!=0)ans=max(ans,c+n-tmp+1);
		else ans=max(ans,r);
	}
	printf("%d\n",ans);
	return 0;
}
