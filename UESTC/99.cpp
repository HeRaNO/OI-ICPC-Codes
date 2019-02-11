#include <cstdio>
using namespace std;

int n,T,ans;

void dfs(int x,int w)
{
	if (x==n){++ans;return ;}
	if (w==4) dfs(x+1,3);
	else if (w==1) dfs(x+1,2);
	else if (w==2) {dfs(x+1,3);dfs(x+1,1);}
	else{dfs(x+1,4);dfs(x+1,2);}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans=0;scanf("%d",&n);dfs(1,1);printf("%d\n",ans);
	}
	return 0;
}