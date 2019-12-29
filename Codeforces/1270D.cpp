#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

int n,k,res;
map <int,int> mp;
bool vis[MAXN];

void ask()
{
	putchar('?');int pos,x;
	for (int i=1;i<=k+1;i++) if (!vis[i]) printf(" %d",i);
	putchar('\n');fflush(stdout);
	scanf("%d %d",&pos,&x);
	mp[x]++;res=max(res,x);
	return ;
}

void answer(int x)
{
	printf("! %d\n",x);fflush(stdout);
	return ;
}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=k+1;i++)
	{
		vis[i]=true;
		ask();
		vis[i]=false;
	}
	answer(mp[res]);
	return 0;
}