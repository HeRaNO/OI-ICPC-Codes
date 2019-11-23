#include <bits/stdc++.h>
using namespace std;

int T;
map <int,int> f;

inline int fpow(int a,int b,int p)
{
	int r=1;
	for (;b;b>>=1,a=(1LL*a*a)%p) if (b&1) r=(1LL*r*a)%p;
	return r;
}

int phi(int x)
{
	int res=x;
	for (int i=2;i*i<=x;i++)
		if (x%i==0)
		{
			res/=i;res*=(i-1);
			while (x%i==0) x/=i;
		}
	if (x!=1) res/=x,res*=(x-1);
	return res;
}

int F(int x)
{
	if (x==1) return f[x]=0;
	if (f.count(x)) return f[x];
	int p=phi(x);return f[x]=fpow(2,F(p)+p,x);
}

int main()
{
	for (int x=scanf("%d",&T);T;T--) scanf("%d",&x),printf("%d\n",F(x));
	return 0;
}