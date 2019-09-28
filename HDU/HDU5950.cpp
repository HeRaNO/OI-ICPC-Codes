#include <bits/stdc++.h>
using namespace std;

const long long M=2147493647;

struct Matrix
{
	long long m[7][7];
	Matrix(){}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		for (int i=0;i<7;i++)
			for (int j=0;j<7;j++)
			{
				res.m[i][j]=0;
				for (int k=0;k<7;k++) (res.m[i][j]+=m[i][k]*a.m[k][j]%M)%=M;
			}
		return res;
	}
	void clear()
	{
		memset(m,0,sizeof m);
		for (int i=0;i<7;i++) m[i][i]=1;
		return ;
	}
	void set()
	{
		memset(m,0,sizeof m);
		m[0][0]=1;m[0][1]=1;
		m[1][0]=2;
		m[2][0]=1;m[2][2]=1;
		m[3][0]=4;m[3][2]=4;m[3][3]=1;
		m[4][0]=6;m[4][2]=6;m[4][3]=3;m[4][4]=1;
		m[5][0]=4;m[5][2]=4;m[5][3]=3;m[5][4]=2;m[5][5]=1;
		for (int i=0;i<7;i++) m[6][i]=1;m[6][1]=0;
		return ;
	}
};

Matrix r,b,ans;
int T,n,x,y;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&x,&y);
		if (n==1)
		{
			printf("%d\n",x);
			continue;
		}
		n-=2;
		r.clear();b.set();
		for (int i=0;i<7;i++)
			for (int j=0;j<7;j++)
				ans.m[i][j]=0;
		ans.m[0][0]=y;ans.m[0][1]=x;
		ans.m[0][2]=16;ans.m[0][3]=8;ans.m[0][4]=4;ans.m[0][5]=2;ans.m[0][6]=1;
		for (;n;n>>=1,b=b*b) if (n&1) r=r*b;
		ans=ans*r;
		printf("%lld\n",ans.m[0][0]);
	}
	return 0;
}