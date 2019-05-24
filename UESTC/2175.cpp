#include <bits/stdc++.h>
#define MAXN 101
#define MAXS 256
#define MAXT 9
using namespace std;

int A,n,k,m,f[2][MAXS][MAXN][MAXT],ans,kas;

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	while (true)
	{
		read(n);read(k);if (!n) break;
		memset(f,0x7f,sizeof f);A=0;ans=~(1<<31);
		for (int i=1;i<=n;i++)
		{
			read(m);m-=114514;
			memset(f[i&1],0x7f,sizeof(f[i&1]));
			f[i&1][1<<m][i-1][m]=1;
			for (int j=0,ll=min(k,i-1);j<=ll;j++)
				for (int x=A;x;x=(x-1)&A)
					for (int p=0;(1<<p)<=x;p++)
						if (f[(i-1)&1][x][j][p]<0x7f7f7f7f)
						{
							int t=f[(i-1)&1][x][j][p];
							if (p==m){if (f[i&1][x][j][p]>t) f[i&1][x][j][p]=t;}
							else
							{
								if (f[i&1][x][j+1][p]>t) f[i&1][x][j+1][p]=t;
								if (f[i&1][x|(1<<m)][j][m]>t+1) f[i&1][x|(1<<m)][j][m]=t+1;
							}
						}
			A|=(1<<m);
		}
		for (int j=0;j<=k;j++)
			for (int x=A;x;x=(x-1)&A)
				for (int p=0;(1<<p)<=x;p++)
					ans=min(ans,f[n&1][x][j][p]+__builtin_popcount(A^x));
		printf("Case %d: %d\n\n",++kas,ans);
	}
	return 0;
}