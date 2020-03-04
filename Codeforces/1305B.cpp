#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

char s[MAXN];
bool vis[MAXN];
vector<int> ans[MAXN];
int n,cnt;

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for (cnt=1;cnt<=n;cnt++)
	{
		int l=1,r=n;
		while (l<r)
		{
			while ((s[l]!='('||vis[l])&&l<r) ++l;
			while ((s[r]!=')'||vis[r])&&l<r) --r;
			if (l==r) break;
			vis[l]=vis[r]=true;
			ans[cnt].push_back(l);
			ans[cnt].push_back(r);
		}
	}
	while (cnt&&ans[cnt].empty()) --cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d\n",ans[i].size());
		sort(ans[i].begin(),ans[i].end());
		for (auto j:ans[i]) printf("%d ",j);putchar('\n');
	}
	return 0;
}