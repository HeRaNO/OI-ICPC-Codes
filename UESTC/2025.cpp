#include <cstdio>
using namespace std;

int n,k,p;

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(k);
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		for (int j=1,x;j<=k;j++)
		{
			read(x);
			if (x) ++cnt;
		}
		if (cnt<=(k>>1)) ++p;
	}
	if (p) puts("YES");
	else puts("no");
	return 0;
}