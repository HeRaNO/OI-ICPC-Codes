//The data may be wrong...
#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int cnt[MAXN],n,m,x;

inline void read(int &x)
{
	x=0;bool f=false;char ch;
	if ((ch=getchar())==EOF){x=-1;return ;}
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	while(scanf("%d %d",&n,&m)==2)
	{
		for (int i=1;i<=n;i++) scanf("%d",&x),++cnt[x+500000];
		for (int i=1000000;~i&&m;i--)
			while (cnt[i]&&m)
			{
				printf("%d ",i-500000);
				--cnt[i];--m;
			}
		puts("");
		memset(cnt,0,sizeof cnt);
	}
	return 0;
}
