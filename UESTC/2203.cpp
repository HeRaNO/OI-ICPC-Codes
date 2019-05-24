#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;

long long x,s[MAXN],dp[MAXN],L;
int n,q[MAXN],head,tail;

long long f(int x,int y){return dp[x]-dp[y]+s[x]*s[x]-s[y]*s[y];}

long long g(int x,int y){return s[x]-s[y];}

int main()
{
	scanf("%d %lld",&n,&L);++L;
	for (int i=1;i<=n;i++){scanf("%lld",&x);s[i]=s[i-1]+x+1;}
	for (int i=1;i<=n;i++)
	{
		while (head<tail)
		{
			//k(q[head],q[head+1])<=2*(s[i]-L)
			long long ff=f(q[head],q[head+1]),gg=g(q[head],q[head+1]);
			if (gg>0)
			{
				if (ff<=gg*2*(s[i]-L)) ++head;
				else break;
			}
			else
			{
				if (ff>=gg*2*(s[i]-L)) ++head;
				else break;
			}
		}
		dp[i]=dp[q[head]]+(s[i]-s[q[head]]-L)*(s[i]-s[q[head]]-L);
		while (head<tail)
		{
			//k(q[tail],q[tail-1])>=k(i,q[tail])
			long long f1=f(q[tail],q[tail-1]),g1=g(q[tail],q[tail-1]);
			long long f2=f(i,q[tail]),g2=g(i,q[tail]);
			int x=(g1<0)+(g2<0);
			if (x&1)
			{
				if (f1*g2<=f2*g1) --tail;
				else break;
			}
			else
			{
				if (f1*g2>=f2*g1) --tail;
				else break;
			}
		}
		q[++tail]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}