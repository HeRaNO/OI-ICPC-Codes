#include <cstdio>

const int d[5][2]={
	{0,1},{0,-1},
	{1,0},{-1,0},{0,0}
};

int n,T;int ans;
bool p[11][11];

bool f(int x,int y)
{
	if (x>=1&&x<=n&&y>=1&&y<=n) return true;
	return false;
}

void dfs(int x,int y)
{
	bool fl=false;
	if (x==n&&y==n+1){++ans;return ;}
	if (y>n){++x;y=1;}
	dfs(x,y+1);
	for (int i=0;i<5;i++)
		if (f(x+d[i][0],y+d[i][1]))
			fl|=p[x+d[i][0]][y+d[i][1]];
	if (!fl)
	{
		p[x][y]=true;
		dfs(x,y+1);
		p[x][y]=false;
	}
	return ;
}

//OEIS A006506

int main()
{
	//scanf("%d",&n);dfs(1,1);printf("%d\n",ans);
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		if (n==1) puts("2");
		else if (n==2) puts("7");
		else if (n==3) puts("63");
		else if (n==4) puts("1234");
		else if (n==5) puts("55447");
		else if (n==6) puts("5598861");
		else if (n==7) puts("1280128950");
		else if (n==8) puts("660647962955");
		else if (n==9) puts("770548397261707");
		else puts("2030049051145980050");
	}
	return 0;
}
