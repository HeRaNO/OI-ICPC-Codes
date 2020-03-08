#include <bits/stdc++.h>
#define MAXN 1005
#define fi first
#define se second
using namespace std;

int n,m,x,cnt[MAXN];
pair <int,int> a[MAXN];
set <int> s;
vector <int> ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d %d",&a[i].fi,&a[i].se);
	scanf("%d",&m);
	for (int j=1;j<=m;j++)
	{
		scanf("%d",&x);s.insert(x);
		for (int i=1;i<=n;i++)
			if (a[i].fi<=x&&x<=a[i].se)
				++cnt[i];
	}
	for (int i=1;i<=n;i++) if (cnt[i]>2) return puts("impossible"),0;
	for (int i=1;i<n;i++)
	{
		if (a[i].se!=a[i+1].fi) continue;
		if (cnt[i]<2&&cnt[i+1]<2&&s.find(a[i].se)==s.end())
		{
			ans.push_back(a[i].se);
			s.insert(a[i].se);
			++cnt[i];++cnt[i+1];
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=cnt[i];j<2;j++)
		{
			int p=a[i].fi+1;
			while (s.find(p)!=s.end()) ++p;
			s.insert(p);ans.push_back(p);++cnt[i];
		}
	printf("%d\n",ans.size());
	for (auto i:ans) printf("%d ",i);puts("");
	return 0;
}