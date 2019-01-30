#include <cstdio>
using namespace std;

const int Z=1e5;
int f[2][Z<<1|1],n,x,y,ans=1<<31;

inline int max(int a,int b){return a>b?a:b;}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	for (int i=0;i<=200000;i++) f[0][i]=-1e6-1,f[1][i]=f[0][i];f[0][Z]=0;
	read(n);int p=0;
	for (int i=1;i<=n;i++)
	{
		read(x);read(y);
		for (int j=(Z<<1);~j;j--)
			if (j-x<=200000&&j>=x) f[p^1][j]=max(f[p][j],f[p][j-x]+y);
			else f[p^1][j]=max(f[p][j],f[p^1][j]);
		p^=1;
	}
	for (int i=Z,q=(Z<<1);i<=q;i++) if (f[p][i]>=0) ans=max(ans,f[p][i]+i-Z);
	printf("%d\n",ans);
	return 0;
}
