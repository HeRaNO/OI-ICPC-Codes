#include <cmath>
#include <cstdio>

int n,T;

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);
		printf("%.0lf\n",ceil(log2(n)));
	}
	return 0;
}