#include <bits/stdc++.h>
#define MAXN 3005
using namespace std;

int n,k,all,p,q;
int a[MAXN],cnt;
char s[MAXN];
bool vis[MAXN];
vector <int> ans[MAXN];

int main()
{
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		++cnt;memset(vis,false,sizeof vis);
		for (int j=1;j<n;j++)
			if (s[j]=='R'&&s[j+1]=='L'&&!vis[j]&&!vis[j+1])
			{
				vis[j]=vis[j+1]=true;++all;
				s[j]='L';s[j+1]='R';
				ans[cnt].push_back(j);
			}
		if (!ans[cnt].size())
		{
			--cnt;break;
		}
	}
	if (k<cnt||k>all) return puts("-1"),0;
	for (int i=1;i<=cnt;i++)
	{
		for (int j=0;j<ans[i].size();j++)
		{
			if (k==cnt-i+1)
			{
				p=i;q=j;
				break;
			}
			--k;
			printf("1 %d\n",ans[i][j]);
		}
		if (p) break;
	}
	printf("%d",ans[p].size()-q);
	for (int i=q;i<ans[p].size();i++) printf(" %d",ans[p][i]);
	puts("");
	for (int i=p+1;i<=cnt;i++)
	{
		printf("%d",ans[i].size());
		for (auto j:ans[i]) printf(" %d",j);
		puts("");
	}
	return 0;
}