#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,a[MAXN],c[MAXN];
long long ans;

inline int lowbit(int x){return x&-x;}
inline void modify(int x){for (;x<=n;x+=lowbit(x)) ++c[x];return ;}
inline long long query(int x){long long r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i;i--)
	{
		ans+=query(a[i]);
		modify(a[i]);
	}
	puts((ans&1)^(n&1)?"Um_nik":"Petr");
	return 0;
}