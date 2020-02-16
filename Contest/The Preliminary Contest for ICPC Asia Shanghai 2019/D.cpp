#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e9+7;
ll ans;
int n;
ll a[3005];
ll fac[3005],inc[3005];
int s[3005],top;
void dfs(int step,ll sum,ll product,int lst)
{
	if(product-sum>n-step+1)return;
	if(product-sum==n-step+1)
	{
		ll temp=fac[n];
		for(int i=2;i<=lst;i++)
			(temp*=inc[a[i]])%=M;
		temp=temp*inc[n-step+1]%M;
		ans+=temp;return;
	}
	for(int i=lst;i<=n;++i)
	{
		if(product*i-sum-i>n-step)break;
		a[i]++;
		dfs(step+1,sum+i,product*i,i);
		a[i]--;
	}
}

ll ksm(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret=ret*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ret;
}

ll res[3005];

int main()
{
	fac[1]=1;
	inc[0]=inc[1]=1;
	for(ll i=2;i<=3000;i++)fac[i]=fac[i-1]*i%M,inc[i]=ksm(fac[i],M-2);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		if(res[n])ans=res[n];
		else dfs(1,0,1,2);
		printf("%lld\n",res[n]=ans%M);
	}
	return 0;
}