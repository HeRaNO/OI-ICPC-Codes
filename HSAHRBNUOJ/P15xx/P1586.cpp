#include <cstdio>
using namespace std;

typedef long long ll;

int n,T,_P;
ll P;

struct M
{
	ll x[2][2];
	M(){}
	M(ll _00,ll _01,ll _10,ll _11){x[0][0]=_00;x[0][1]=_01;x[1][0]=_10;x[1][1]=_11;}
	M operator * (const M &a)const{
		M c(x[0][0]*a.x[0][0]+x[0][1]*a.x[1][0],
			x[0][0]*a.x[0][1]+x[0][1]*a.x[1][1],
			x[1][0]*a.x[0][0]+x[1][1]*a.x[1][0],
			x[1][0]*a.x[0][1]+x[1][1]*a.x[1][1]);
		c.x[0][0]%=P;c.x[0][1]%=P;c.x[1][0]%=P;c.x[1][1]%=P;
		return c;
	}
	ll fib(){return x[0][0];}
};

long long F(int n)
{
	M a(1,1,1,0),r(1,0,0,1);
	if (!n) return 0%P;
	if (n==1) return 1%P;
	for (--n;n;n>>=1,a=a*a) if (n&1) r=r*a;
	return r.fib();
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
		printf("%lld\n",F(n));
	}
	return 0;
}