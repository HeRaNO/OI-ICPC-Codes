#include <bits/stdc++.h>
#define MAXN 10000005
using namespace std;

const int M=1e9+7;

int T,n,S[MAXN];
int prime[MAXN],phi[MAXN],mu[MAXN],tot;
bool not_prime[MAXN];

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}
inline int sqr(int x){return 1LL*x*x%M;}
inline int f(int x){return 1LL*x*(x+1)/2%M;}

inline void EratosthenesShaker(int n)
{
	phi[1]=mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i])
		{
			prime[++tot]=i;
			phi[i]=i-1;mu[i]=-1;
		}
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j]))
			{
				mu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			mu[i*prime[j]]=-mu[i];
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	for (int i=1;i<=n;i++) fadd(mu[i],M);
	for (int i=1;i<=n;i++)
		for (int j=1;j*i<=n;j++)
			fadd(S[i*j],1LL*mu[i]*phi[j]%M);
	for (int i=1;i<=n;i++) S[i]=1LL*S[i]*sqr(i)%M;
	for (int i=1;i<=n;i++) fadd(S[i],S[i-1]);
	return ;
}

int main()
{
	EratosthenesShaker(10000000);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int ans=0;
		for (int l=1,r;l<=n;l=r+1)
		{
			r=n/(n/l);
			int t=S[r];fadd(t,M-S[l-1]);
			t=1LL*t*sqr(f(n/l))%M;fadd(ans,t);
		}
		printf("%d\n",ans);
	}
	return 0;
}