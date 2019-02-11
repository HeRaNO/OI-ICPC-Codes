#include <cstdio>
#define MAXN 15626
using namespace std;

int n,x;
unsigned long long a[MAXN];

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);
	for (int i=1;i<n;i++){read(x);a[x>>6]|=1LL<<(x&63);}
	for (int i=1;i<=n;i++) if (!(a[i>>6]&(1LL<<(i&63)))) return printf("%d\n",i),0;
	return 0;
}