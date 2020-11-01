#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int M=1000000007;
int n,x,a[MAXN],b[MAXN];

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}

inline int fpow(int a,int b)
{
	int r=1;
	for (;b;b>>=1,a=1LL*a*a%M) if (b&1) r=1LL*r*a%M;
	return r;
}

int main()
{
	while (scanf("%d %d",&n,&x)==2)
	{
		int ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		int xn_1=fpow(x,n-1);
		for (int i=1;i<=n;i++) fadd(ans,1LL*a[i]*b[i]%M*xn_1%M);
		xn_1=1LL*xn_1*x%M;
		fadd(ans,xn_1);
		printf("%d\n",ans);
	}
	return 0;
}