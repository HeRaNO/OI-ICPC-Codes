#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=200050;
double dp[(1<<20)+5];
int n,k;
double p[25];
double ans[25];

int main()
{
	cin>>n>>k;
	int cnt=0;
	for(int i=0;i<n;++i)
	{
		double x;
		scanf("%lf",&x);
		p[i]=x;
		if(x==0.0)cnt++;
	}
	if(n-cnt<=k)
	{
		for(int i=0;i<n;++i)
			if(p[i]==0.0)printf("0 ");
			else printf("1 ");
		return 0;
	}
	int all=(1<<n);
	dp[0]=1.0;
	for(int st=0;st<all;++st)
	{
		double tmp=1.0;
		for(int i=0;i<n;++i)
		{
			if(st&(1<<i))
			{
				tmp-=p[i];
				if(__builtin_popcount(st)==k)ans[i]+=dp[st];
			}
		}
		for(int i=0;i<n;++i)
		{
			if(st&(1<<i))continue;
			dp[st|(1<<i)]+=dp[st]*p[i]/tmp;
		}
	}
	for(int i=0;i<n;++i)
	{
		printf("%.12lf ",ans[i]);
	}
	return 0;
}
