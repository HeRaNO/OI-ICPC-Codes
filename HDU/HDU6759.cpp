#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct line
{
	long long k,b;
	line(){}
	line(long long _,long long __):k(_),b(__){}
	bool operator < (const line &a)const{
		if (k==a.k) return b<a.b;
		return k<a.k;
	}
};

line a[MAXN],sta[MAXN];
int n,top;
map <line,int> mp;

void insert(line a)
{
	while (top)
	{
		if (sta[top].k==a.k) --top;
		else if (top>1&&(sta[top-1].b-a.b)*(sta[top].k-sta[top-1].k)<=(sta[top-1].b-sta[top].b)*(a.k-sta[top-1].k))
			--top;
		else break;
	}
	sta[++top]=a;
	return;
}

inline void Solve()
{
	scanf("%d",&n);top=0;int mxy=0;int ans=0;
	mp.clear();
	memset(a,0,sizeof a);memset(sta,0,sizeof sta);
	for (int i=1;i<=n;i++)
	{
		int p,A;
		scanf("%d %d",&p,&A);
		a[i].k=A;a[i].b=p;
		mxy=max(mxy,p);++mp[a[i]];
	}
	sort(a+1,a+n+1);
	insert(line(0,mxy));
	for (int i=1;i<=n;i++) insert(a[i]);
	for (int i=1;i<=top;i++) if (mp[sta[i]]==1) ++ans;
	printf("%d\n",ans);
	return ;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}