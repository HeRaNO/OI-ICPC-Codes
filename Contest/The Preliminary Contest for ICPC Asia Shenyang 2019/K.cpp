#include <bits/stdc++.h>
#define MAXN 75
using namespace std;

const long long M=1e9+7;

int T,k,a[MAXN<<1];
long long n;
bool vis[MAXN];

inline long long fpow(long long a,long long b)
{
	long long r=1;
	if (a==1) return 1LL;
	for (;b;b>>=1,a=(a*a)%M) if (b&1) r=(r*a)%M;
	return r;
}

struct Matrix
{
	long long m[MAXN][MAXN];
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		for (int i=0;i<=k;i++)
			for (int j=0;j<=k;j++)
			{
				res.m[i][j]=0;
				for (int l=0;l<=k;l++) (res.m[i][j]+=m[i][l]*a.m[l][j]%M)%=M;
			}
		return res;
	}
};

Matrix p;
Matrix r,b;

inline Matrix Gauss_Elimination(Matrix a)
{
	for (int i = 1; i <= k; i++)
	{
		int now = i;
		for (int j = i + 1; j <= k; j++)
			if (a.m[now][i] < a.m[j][i]) now = j;
		swap(a.m[now], a.m[i]);
		long long t = fpow(a.m[i][i], M - 2);
		for (int j = 1; j <= k + 1; j++) (a.m[i][j] *= t) %= M;
		for (int j = 1; j <= k; j++)
			if (j != i)
			{
				t = a.m[j][i];
				for (int l = 1; l <= k + 1; l++)
				{
					a.m[j][l] -= t * a.m[i][l] % M;
					(a.m[j][l] += M) %= M;
				}
			}
	}
	return a;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		long long s=0;
		scanf("%d %lld",&k,&n);
		for (int i=1;i<=k*2;i++)
		{
			scanf("%d",&a[i]);
			(s+=a[i])%=M;
		}
		for (int i=1;i<=k;i++)
			for (int j=1;j<=k+1;j++) p.m[i][j]=a[i+j-1];
		p=Gauss_Elimination(p);
		if (n<=k)
		{
			long long ans=0;
			for (int i=1;i<=n;i++) (ans+=a[i])%=M;
			printf("%lld\n",ans);
		}
		else
		{
			memset(b.m,0,sizeof b.m);
			memset(r.m,0,sizeof r.m);
			for (int i=0;i<=k;i++) r.m[i][i]=1;
			for (int i=0;i<k;i++) b.m[i][0]=p.m[i+1][k+1];
			for (int i=1;i<k;i++) b.m[i-1][i]=1;
			b.m[0][k]=1;b.m[k][k]=1;
			long long pl=n-2*k;
			while (pl)
			{
				if (pl&1) r=r*b;
				b=b*b;
				pl>>=1;
			}
			memset(b.m,0,sizeof b.m);
			for (int i=0;i<k;i++) b.m[0][i]=a[2*k-i];
			b.m[0][k]=s;
			r=b*r;
			printf("%lld\n",r.m[0][k]);
		}
	}
	return 0;
}