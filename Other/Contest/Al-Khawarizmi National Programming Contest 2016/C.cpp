#include <bits/stdc++.h>
using namespace std;

char mon[15][5]={
	"\0","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep"
	,"Oct","Nov","Dec"
};

int n,kas,d,m,y;
int cnt[13];

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
		read(n);memset(cnt,0,sizeof cnt);
		if (!n) break;
		for (int i=1;i<=n;i++)
		{
			read(d);read(m);read(y);
			++cnt[m];
		}
		printf("Case #%d:\n", ++kas);
		for (int i=1;i<=12;i++)
		{
			printf("%s:", mon[i]);
			for (int j=1;j<=cnt[i];j++) putchar('*');
			putchar('\n');
		}
	}
	return 0;
}