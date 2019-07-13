#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,m,p,x,a[MAXN];
long long ans;
bool f;
map <int,int> cnt;

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

inline long long fx(int x){return x>0?x:0;}

int main()
{
	read(n);
	for (int i=1;i<=n;i++)
	{
		read(a[i]);
		if (a[i]) f=true;
		++cnt[a[i]];
		if (cnt[a[i]]==2){++p;x=a[i];}
		if (cnt[a[i]]==3) return puts("cslnb"),0;
	}
	if (p>1) return puts("cslnb"),0;
	if (!f||cnt[0]>1) return puts("cslnb"),0;
	if (p==1&&cnt[x-1]>0) return puts("cslnb"),0;
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) ans+=(a[i]-i+1);
	puts(ans&1?"sjfnb":"cslnb");
	return 0;
}