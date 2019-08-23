#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

int T,opt,x,y,ans[710][710],a[MAXN];

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(opt);read(x);read(y);
		if (opt==1)
		{
			for (int i=1;i<=708;i++) ans[i][x%i]+=y;
			a[x]+=y;
		}
		else
		{
			if (x<=708) printf("%d\n",ans[x][y]);
			else
			{
				int s=0;
				for (int i=y;i<=500000;i+=x) s+=a[i];
				printf("%d\n",s);
			}
		}
	}
	return 0;
}