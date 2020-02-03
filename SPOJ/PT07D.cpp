#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int k,n,p,f[MAXN],g[MAXN],inv[MAXN];

inline int fpow(int a,int b,int p)
{
	if (b<=0) return 1;int r=1;
	for (;b;b>>=1,(a*=a)%=p) if (b&1) (r*=a)%=p;
	return r;
}

inline int C2(int x)
{
	x%=p;
	return x*(x-1)%p*inv[2]%p;
}

int main()
{
	while (scanf("%d %d %d",&k,&n,&p)==3)
	{
		if (k<=2) printf("%d\n",fpow(n%p,n-3+k,p));
		else
		{
			f[1]=inv[1]=1;
			for (int i=1;i<=n;i++) g[i]=1;
			for (int i=2;i<n;i++) inv[i]=(p-p/i)*inv[p%i]%p; 
			for (int i=2;i<=n;i++)
			{
				f[i]=0;
				for (int j=1;j<i;j++) f[i]+=f[j]*g[i-j]%p,(f[i]>=p?f[i]-=p:0);
				(f[i]*=inv[i-1])%=p;int t=i*f[i]%p;
				for (int j=i;j<=n;j+=i) g[j]+=t,(g[j]>=p?g[j]-=p:0);
			}
			if (k==3) printf("%d\n",f[n]);
			else
			{
				if (n==2){puts("1");continue;}
				int r=0;
				for (int i=1,q=(n>>1);i<=q;i++)
					(r+=f[i]*f[n-i]%p)%=p;
				int ans=(f[n]-r+p)%p;
				if (!(n&1)) (ans+=C2(f[n>>1]+1))%=p;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}