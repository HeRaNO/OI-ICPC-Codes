#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 200010
#define MAXB 450
using namespace std;

struct Modui
{
	int l,r,id,ans;
};

Modui ans[MAXN];
int n,T,m,c,pos[MAXN],a[MAXN],cnt[MAXN],cnt2[MAXN],all;
int p[MAXN];
pair <int,int*> b[MAXN];

bool cmp(Modui a,Modui b){return pos[a.l]==pos[b.l]?a.r<b.r:a.l<b.l;}

inline void Discretization()
{
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		if (b[i].first!=b[i-1].first) ++c;
		*b[i].second=c;
	}
	return ;
}

void update(int x,int v)
{
	x=a[x];
	if (!~v)
	{
		--cnt2[cnt[x]];cnt2[--cnt[x]]++;
		while (!cnt2[all]) --all;
	}
	else
	{
		--cnt2[cnt[x]];cnt2[++cnt[x]]++;
		while (cnt2[all+1]) ++all;
	}
}

inline void ModuiAlgo()
{
	sort(ans+1,ans+T+1,cmp);cnt2[0]=n;
	int l=1,r=0;
	for (int i = 1; i <= T; i++)
	{
		while (r<ans[i].r) update(++r, 1);
		while (r>ans[i].r) update(r--,-1);
		while (l<ans[i].l) update(l++,-1);
		while (l>ans[i].l) update(--l, 1);
		p[ans[i].id]=all;
	}
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(T);m=sqrt(n);
	for (int i=1;i<=n;i++)
	{
		read(a[i]);
		b[i]=make_pair(a[i],&a[i]);
		pos[i]=(i-1)/m+1;
	}
	Discretization();
	for (int i=1;i<=T;i++)
	{
		read(ans[i].l);read(ans[i].r);
		ans[i].id=i;
	}
	ModuiAlgo();
	for (int i=1;i<=T;i++) printf("%d\n",p[i]);
	return 0;
}
