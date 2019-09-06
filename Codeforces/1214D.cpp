#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,m;
bool a[MAXN];
char s[MAXN];

inline int f(int x,int y){return (x-1)*m+y;}

inline bool dfs(int x,int y)
{
	if (x==n&&y==m) return true;
	a[f(x,y)]=true;
	if (x<n&&!a[f(x+1,y)]&&dfs(x+1,y)) return true;
	if (y<m&&!a[f(x,y+1)]&&dfs(x,y+1)) return true;
	return false;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<m;j++) if (s[j]=='#') a[f(i,j+1)]=true;
	}
	if (!dfs(1,1)) return puts("0"),0;
	a[1]=false;
	if (!dfs(1,1)) return puts("1"),0;
	puts("2");
	return 0;
}