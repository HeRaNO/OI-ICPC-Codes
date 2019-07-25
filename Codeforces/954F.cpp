#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

const long long M=1e9+7;

struct matrix
{
	long long m[3][3];
	matrix() {
		memset(m,0,sizeof m);
		m[0][0]=m[1][1]=m[2][2]=1;
		return ;
	}
	matrix operator * (const matrix &a)const{
		matrix res;
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
			{
				res.m[i][j]=0;
				for (int k=0;k<3;k++) (res.m[i][j]+=m[i][k]*a.m[k][j]%M)%=M;
			}
		return res;
	}
};

struct line
{
	int a;long long l,r;
};

matrix ans,g,ng;
line a[MAXN];
int n,p,s[4][MAXN<<1],sc[4];
long long m,ori[MAXN<<1],b[MAXN<<1];

inline matrix fpow(matrix a,long long b)
{
	matrix r;
	for (;b;a=a*a,b>>=1) if (b&1) r=r*a;
	return r;
}

int main()
{
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			g.m[i][j]=1;
	g.m[0][2]=g.m[2][0]=0;
	scanf("%d %lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %lld %lld",&a[i].a,&a[i].l,&a[i].r);
		b[++b[0]]=a[i].l-1;b[++b[0]]=a[i].r;
	}
	b[++b[0]]=1;b[++b[0]]=m;
	sort(b+1,b+b[0]+1);
	p=unique(b+1,b+b[0]+1)-b-1;
	for (int i=1;i<=n;i++)
	{
		int l=lower_bound(b+1,b+p+1,a[i].l)-b;
		int r=lower_bound(b+1,b+p+1,a[i].r)-b;
		++s[a[i].a][l];--s[a[i].a][r+1];
	}
	for (int i=1;i<=3;i++)
		for (int j=1;j<=p;j++)
			s[i][j]+=s[i][j-1];
	memset(ans.m,0,sizeof ans.m);
	ans.m[1][0]=1;
	for (int i=2;i<=p;i++)
	{
		ng=g;
		if (s[1][i]) ng.m[0][1]=ng.m[0][2]=ng.m[0][0]=0LL;
		if (s[2][i]) ng.m[1][1]=ng.m[1][2]=ng.m[1][0]=0LL;
		if (s[3][i]) ng.m[2][1]=ng.m[2][2]=ng.m[2][0]=0LL;
		ans=fpow(ng,b[i]-b[i-1])*ans;
	}
	printf("%lld\n",ans.m[1][0]);
	return 0;
}