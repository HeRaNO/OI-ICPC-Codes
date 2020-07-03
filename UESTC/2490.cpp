#include <bits/stdc++.h>
#define MAXM 10000000
#define MAXN 200005
using namespace std;

int n,q,l,r,m,tot,a[MAXN],pri[MAXM],phi[MAXM];
bool not_prime[MAXM];

inline void LinearShaker(int n)
{
	phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]){pri[++tot]=i;phi[i]=i-1;}
		for (int j=1;i*pri[j]<=n;j++)
		{
			not_prime[i*pri[j]]=true;
			if (!(i%pri[j]))
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	return ;
}

inline int mod(long long a,int P){return a<(P<<1)?a:a%P+P;}
inline int fpow(int a,int b,int P)
{
	int r=1;
	for (;b;b>>=1,a=mod(1LL*a*a,P)) if (b&1) r=mod(1LL*r*a,P);
	return r;
}

inline int Solve(int l,int r,int P)
{
	if (l==r||P==1) return mod(a[l],P);
	return fpow(a[l],Solve(l+1,r,phi[P]),P);
}

int main()
{
	LinearShaker(10000000);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	while (q--)
	{
		scanf("%d %d %d",&l,&r,&m);
		printf("%d\n",Solve(l,r,m)%m);
	}
	return 0;
}