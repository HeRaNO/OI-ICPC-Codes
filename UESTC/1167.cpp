#include <cstdio>
using namespace std;

int n,_P,T;long long P;

long long qpow(long long a,int b)
{
	long long r=1;
	for (;b;a=(a*a)%P,b>>=1) if (b&1) r=(r*a)%P;
	return r;
}

long long Lucas(long long n,long long m)
{
	if (n<P&&m<P)
	{
		long long a=1LL,b=1LL;
		for (int i=n;i>n-m;i--) (a*=i)%=P;
		for (int i=1;i<=m;i++) (b*=i)%=P;
		return a*qpow(b,P-2)%P;
	}
	if (m>n) return 0;
	return !m?1LL:Lucas(n%P,m%P)*Lucas(n/P,m/P)%P;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);read(_P);P=_P;
		printf("%lld\n",Lucas(2*n,n)*qpow(n+1,P-2)%P);
	}
	return 0;
}