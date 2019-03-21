#pragma GCC optimize("Ofast")
#include <cstdio>
#define MAXN 1001
using namespace std;

const unsigned long long bs=19260817LL;

int n,m,T,l1,r1,l2,r2,l3,r3,l4,r4,a[MAXN][MAXN];
unsigned long long c[MAXN][MAXN],hs[MAXN],hs1,hs2,t;

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

inline void readch(int &x)
{
	char ch=getchar();
	while (ch!='0'&&ch!='1') ch=getchar();
	x=ch-'0';return ;
}

int main()
{
	read(n);read(m);hs[0]=1;
	for (int i=1;i<=m;i++) hs[i]=hs[i-1]*bs;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			readch(a[i][j]);
			c[i][j]=c[i][j-1]*bs+(unsigned long long)a[i][j];
		}
	read(T);
	while (T--)
	{
		read(l1);read(r1);read(l2);read(r2);
		read(l3);read(r3);read(l4);read(r4);
		++l1;++l2;++r1;++r2;
		++l3;++l4;++r3;++r4;
		int cnt=0,px;t=hs[r2-r1+1];
		for (int i=l1,j=l3;i<=l2;i++,j++)
		{
			hs1=c[i][r2]-c[i][r1-1]*t;
			hs2=c[j][r4]-c[j][r3-1]*t;
			if (hs1!=hs2)
			{
				++cnt;px=i;
				if (cnt>1) break;
			}
		}
		if (cnt>1)
		{
			puts("Wrong");continue;
		}
		if (!cnt)
		{
			puts("Perfect");continue;
		}
		cnt=0;
		for (int i=r1,j=r3,pt=px-l1+l3;i<=r2;i++,j++)
		{
			cnt+=(a[px][i]^a[pt][j]);
			if (cnt>1) break;
		}
		if (cnt>1) puts("Wrong");
		else puts("One difference");
	}
	return 0;
}