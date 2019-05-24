#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long M=16711680LL;
const int num[]={0,4,7,5,0};

char L[MAXN],R[MAXN];
int n,a[MAXN];
long long dp[MAXN][5],_10pow[MAXN],suf[MAXN];
//4750
long long dfs(int x,int _is475,bool up)
{
	if (x==n) return _is475==4;
	if (!up&&~dp[x][_is475]) return dp[x][_is475];
	long long cnt=_is475==4;
	int tt=_is475;if (_is475==4) _is475=0;
	if (!up) cnt=(cnt*_10pow[n-x])%M;
	else cnt=(cnt*(suf[x]+1))%M;
	for (int i=0,mx=up?a[x]:9;i<=mx;i++)
	{
		if (num[_is475+1]==i)
		{
			cnt=(cnt+dfs(x+1,_is475+1,up&&i==mx))%M;
		}
		else
		{
			cnt=(cnt+dfs(x+1,i==4,up&&i==mx))%M;
		}
	}
	if (!up) dp[x][tt]=cnt;
	return cnt;
}

long long Digital_DP(char p[])
{
	n=strlen(p);
	if (n<4) return 0;
	memset(dp,-1,sizeof dp);memset(suf,0,sizeof suf);
	for (int i=0;i<n;i++) a[i]=p[i]-'0';
	long long _10=1;
	for (int i=n-1;~i;i--) suf[i]=(suf[i+1]+a[i]*_10)%M,(_10*=10)%=M;
	return dfs(0,0,true);
}

long long Get(char a[])
{
	n=strlen(a);long long res=0;
	for (int i=0;i<n-3;i++)
		if (a[i]=='4'&&a[i+1]=='7'&&a[i+2]=='5'&&a[i+3]=='0') ++res;
	return res%M;
}

int main()
{
	_10pow[0]=1LL;for (int i=1;i<MAXN;i++) _10pow[i]=_10pow[i-1]*10%M;
	scanf("%s",L);scanf("%s",R);
	printf("%lld\n",(Digital_DP(R)-Digital_DP(L)+Get(L)+M)%M);
	return 0;
}
