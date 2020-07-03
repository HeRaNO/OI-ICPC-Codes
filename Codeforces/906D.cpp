#include <bits/stdc++.h>
#define MAXN 200005
#define logM 32
using namespace std;

int n,q,l,r,m,tot,a[MAXN],P[logM];

inline int phi(int x)
{
	int res=x;
	for (int i=2;i*i<=x;i++)
		if (!(x%i)){res/=i;res*=(i-1);while (!(x%i)) x/=i;}
	if (x!=1) res/=x,res*=(x-1);
	return res;
}

inline int mod(long long a,int P){return a<(P<<1)?a:a%P+P;}
inline int fpow(int a,int b,int P)
{
	int r=1;
	for (;b;b>>=1,a=mod(1LL*a*a,P)) if (b&1) r=mod(1LL*r*a,P);
	return r;
}

inline int Solve(int l,int r,int p)
{
	if (l==r||P[p]==1) return mod(a[l],P[p]);
	return fpow(a[l],Solve(l+1,r,p+1),P[p]);
}

int main()
{
	scanf("%d %d",&n,&P[0]);
	for (int i=0;P[i]>1;i++) P[i+1]=phi(P[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",Solve(l,r,0)%P[0]);
	}
	return 0;
}