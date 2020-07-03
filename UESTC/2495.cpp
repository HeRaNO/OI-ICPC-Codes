#include <bits/stdc++.h>
#define MAXN 10000005
using namespace std;

const int M=998244353;

int T,n,l,r,inv[MAXN],f[MAXN];
int prime[MAXN],e[MAXN],d[MAXN],tot;bool not_prime[MAXN];

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}

inline void LinearShaker(int n)
{
	d[1]=inv[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]){prime[++tot]=i;e[i]=1;d[i]=2;}
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j]))
			{
				d[i*prime[j]]=d[i]/(e[i]+1)*(e[i]+2);
				e[i*prime[j]]=e[i]+1;
				break;
			}
			else
			{
				d[i*prime[j]]=d[i]<<1;
				e[i*prime[j]]=1;
			}
		}
	}
	for (int i=1;i<=n;i++) fadd(d[i],d[i-1]);
	for (int i=1;i<=n;i++) fadd(d[i],d[i-1]);
	for (int i=2;i<=n;i++) inv[i]=1LL*(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) fadd(inv[i],inv[i-1]);
	for (int i=1;i<=n;i++) f[i]=1LL*i*inv[i]%M,fadd(f[i],f[i-1]);
	for (int i=1;i<=n;i++) fadd(f[i],M-d[i]);
	return ;
}

int main()
{
	LinearShaker(10000000);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&l,&r);
		int ans=f[r];fadd(ans,M-f[l-1]);
		printf("%d\n",ans);
	}
	return 0;
}