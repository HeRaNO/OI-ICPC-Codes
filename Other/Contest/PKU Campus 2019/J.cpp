#include <bits/stdc++.h>
#define MAXN 205
using namespace std;

const long long M=998244353;

struct Matrix
{
	long long m[MAXN][MAXN];
};

int T,n,m,rnk,_0r,_0c,alpha[MAXN],beta[MAXN];
Matrix a,ast,b,c;
long long det;
bool vis[MAXN];

inline long long fpow(long long a,long long b)
{
	long long r=1;
	if (a==1) return 1LL;
	for (;b;b>>=1,a=(a*a)%M) if (b&1) r=(r*a)%M;
	return r;
}

inline void getDetAndRank(Matrix a)
{
	memset(vis,0,sizeof vis);
	det=1;rnk=n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ast.m[i][j]=i==j;
	for (int i=1;i<=n;i++)
	{
		int now=0;
		for (int j=1;j<=n&&!now;j++) if (!vis[j]&&a.m[j][i]) now=j;
		if (!now){--rnk;continue;}
		if (now!=i) det=-det;
		vis[i]=true;
		for (int j=1;j<=n;j++)
		{
			swap(a.m[now][j],a.m[i][j]);
			swap(ast.m[now][j],ast.m[i][j]);
		}
		long long t=fpow(a.m[i][i],M-2);
		for (int j=1;j<=n;j++)
			if (j!=i)
			{
				long long x=a.m[j][i]*t%M;
				for (int k=1;k<=n;k++) 
				{
					a.m[j][k]-=x*a.m[i][k]%M;(a.m[j][k]+=M)%=M;
					ast.m[j][k]-=x*ast.m[i][k]%M;(ast.m[j][k]+=M)%=M;
				}
			}
	}
	det=(det+M)%M;
	for (int i=1;i<=n;i++)
	{
		(det*=a.m[i][i])%=M;
		long long t=fpow(a.m[i][i],M-2);
		for (int j=1;j<=n;j++) (ast.m[i][j]*=t)%=M;
	}
	return ;
}

inline Matrix Gauss_Elimination(Matrix a)
{
	memset(vis,false,sizeof vis);
	for (int i=1;i<=n;i++)
	{
		int now=0;
		for (int j=1;j<=n&&!now;j++) if (!vis[j]&&a.m[j][i]) now=j;
		if (!now) continue;
		vis[i]=true;
		for (int j=1;j<=n;j++) swap(a.m[now][j],a.m[i][j]);
		long long t=fpow(a.m[i][i],M-2);
		for (int j=1;j<=n;j++)
			if (j!=i)
			{
				long long x=a.m[j][i]*t%M;
				for (int k=1;k<=n;k++) a.m[j][k]-=x*a.m[i][k]%M,(a.m[j][k]+=M)%=M;
			}
	}
	return a;
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
		read(n);
		for (int i=1,x;i<=n;i++)
			for (int j=1;j<=n;j++)
				read(x),a.m[i][j]=x;
		getDetAndRank(a);
		if (rnk==n)
		{
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++)
					swap(ast.m[i][j],ast.m[j][i]);
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
				{
					(ast.m[i][j]*=det)%=M;
					if ((i+j)&1) ast.m[i][j]=(M-ast.m[i][j])%M;
				}
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					printf("%lld%c",ast.m[i][j],j==n?'\n':' ');
		}
		else if (rnk<=n-2)
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					printf("0%c",j==n?'\n':' ');
		}
		else
		{
			b=Gauss_Elimination(a);
			for (int i=1;i<=n;i++) if (!b.m[i][i]){_0r=i;break;}
			for (int i=1;i<=n;i++) if (i!=_0r) alpha[i]=(M-b.m[i][_0r])*fpow(b.m[i][i],M-2)%M;
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					b.m[i][j]=a.m[j][i];
			c=Gauss_Elimination(b);
			for (int i=1;i<=n;i++) if (!c.m[i][i]){_0c=i;break;}
			for (int i=1;i<=n;i++) if (i!=_0c) beta[i]=(M-c.m[i][_0c])*fpow(c.m[i][i],M-2)%M;
			m=n;n=0;
			for (int i=1;i<=m;i++)
				if (i!=_0c)
				{
					++n;
					for (int j=1,k=1;j<=m;j++)
						if (j!=_0r) b.m[n][k++]=a.m[i][j];
				}
			getDetAndRank(b);n=m;
			if ((_0r+_0c)&1) det=M-det;b.m[_0r][_0c]=det;
			for (int i=1;i<=n;i++) if (i!=_0c) b.m[_0r][i]=b.m[_0r][_0c]*beta[i]%M;
			for (int i=1;i<=n;i++)
				if (i!=_0r)
				{
					b.m[i][_0c]=alpha[i]*b.m[_0r][_0c]%M;
					for (int j=1;j<=n;j++)
						if (j!=_0c) b.m[i][j]=(b.m[i][_0c]*beta[j])%M;
				}
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++)
					swap(b.m[i][j],b.m[j][i]);
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if ((i+j)&1) b.m[i][j]=(M-b.m[i][j])%M;
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					printf("%lld%c",b.m[i][j],j==n?'\n':' ');
		}
		puts("");
	}
	return 0;
}