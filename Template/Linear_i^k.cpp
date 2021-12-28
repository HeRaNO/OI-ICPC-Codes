#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const long long M=1e9+7;

int n,k,pri[MAXN],f[MAXN],tot;
bool not_prime[MAXN];

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}

inline int fpow(int a,int b)
{
	int r=1;
	for (;b;b>>=1,a=1LL*a*a%M) if (b&1) r=1LL*r*a%M;
	return r;
}

void Linear_Shaker(int n)
{
	f[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) pri[++tot]=i,f[i]=fpow(i,k);
		for (int j=1;i*pri[j]<=n;j++)
		{
			not_prime[i*pri[j]]=true;
			f[i*pri[j]]=1LL*f[i]*f[pri[j]]%M;
			if (!(i%pri[j])) break;
		}
	}
	//for (int i=1;i<=n;i++) fadd(f[i],f[i-1]);
	return ;
}

int main()
{
	scanf("%d %d",&n,&k);
	Linear_Shaker(n);
	for (int i=1;i<=n;i++) assert(f[i]==fpow(i,k));
	return 0;
}