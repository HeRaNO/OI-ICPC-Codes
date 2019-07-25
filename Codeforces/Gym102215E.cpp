#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

struct line
{
	pair<int,int> w;
	int id;
	bool operator < (const line &a)const{
		return w<a.w;
	}
};

line a[MAXN];
int n,m;
vector <int> ans;

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].w.first,&a[i].w.second);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	a[n+1].w.first=~(1<<31);
	int t=0,tp=0,now=0;bool f=false;
	for (int i=1;i<=n;i++)
		if (a[i].w.first<=t+1)
		{
			if (tp<a[i].w.second)
			{
				now=a[i].id;
				tp=a[i].w.second;
				f=true;
			}
			if (a[i+1].w.first>t+1&&f)
			{
				ans.push_back(now);
				t=tp;f=false;
			}
		}
	if (t<m) return puts("NO"),0;
	if (!ans.size()) return puts("NO"),0;
	puts("YES");
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
	return 0;
}