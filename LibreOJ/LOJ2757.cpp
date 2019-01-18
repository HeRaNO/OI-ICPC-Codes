#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 505
#define MAXM 10010
using namespace std;

int m,n,x,y,ans,a[MAXM],f[MAXM];

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(m);read(n);memset(f,0x7f,sizeof f);f[0]=0;
	for (int i=1;i<=m;i++) read(a[i]);
	sort(a+1,a+m+1,[](int a, int b) -> bool { return a > b; });
	for (int i=1;i<=m;i++) a[i]+=a[i-1];
	for (int i=1;i<=n;i++)
	{
		read(x);read(y);
		for (int j=m;~j;j--) f[j]=min(f[j],f[max(j-x,0)]+y);
	}
	for (int i=1;i<=m;i++) ans=max(ans,a[i]-f[i]);
	printf("%d\n",ans);
	return 0;
}
