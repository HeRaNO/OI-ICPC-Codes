#include <bits/stdc++.h>
#define MAXM 105
using namespace std;

const long long M=1e9+7;

struct matrix
{
	long long m[MAXM][MAXM];int s;
	matrix operator *(const matrix &a)const{
		matrix res;res.s=s;
		for (int i=0;i<=s;i++)
			for (int j=0;j<=s;j++)
			{
				res.m[i][j]=0LL;
				for (int k=0;k<=s;k++)
					res.m[i][j]=(res.m[i][j]+m[i][k]*a.m[k][j]%M)%M;
			}
		return res;
	}
}a,dp,res;

int n,m,x,y;

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(m);--n;bool f=n;
	if (n<0) return puts("0"),0;
	read(x);read(x);read(y);read(y);
	dp.s=m;a.s=m;res.s=m;
	dp.m[0][0]=1000-x-m*y;dp.m[1][0]=m*y;dp.m[m][0]+=x;
	a.m[0][0]=1000-x-m*y;
	for (int i=1;i<m;i++)
	{
		a.m[i][i-1]=(m-i+1)*y%M;
		a.m[i][i]=1000-x-(m-i)*y;
	}
	for (int i=0;i<m;i++) a.m[m][i]=x;a.m[m][m-1]+=y;a.m[m][m]=1000;
	for (int i=0;i<=m;i++) res.m[i][i]=1;
	while (n)
	{
		if (n&1) res=res*a;
		a=a*a;
		n>>=1;
	}
	if (f) dp=res*dp;
	printf("%lld\n",dp.m[m][0]);
	return 0;
}
