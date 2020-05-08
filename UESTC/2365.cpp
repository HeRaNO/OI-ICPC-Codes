#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

int n,a[MAXN],b[MAXN],c[MAXN],cnt[MAXN],C,S,ans,mn=~(1<<31);
vector <int> g[MAXN];
set <int> s;

inline void add(int u,int v){g[u].push_back(v);return ;}

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
	for (int i=1;i<=n;i++) read(a[i]),++cnt[a[i]],add(a[i],i);
	for (int i=1;i<=n;i++) read(b[i]);
	for (int i=1;i<=n;i++) read(c[i]);
	for (int i=1;i<=n;i++)
	{
		C+=cnt[i];
		if (mn>C-i) mn=C-i,S=i;
	}
	for (int i=1;i<=n;i++)
	{
		++S;if (S>n) S=1;
		for (auto v:g[S]) s.insert(c[v]);
		auto it=s.upper_bound(b[S]);
		if (it==s.end()) s.erase(s.begin());
		else ++ans,s.erase(it);
	}
	printf("%d\n",ans);
	return 0;
}