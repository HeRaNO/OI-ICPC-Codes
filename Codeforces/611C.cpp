#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=550;
char s[N][N];
int x[N][N],y[N][N];
int sumx[N][N],sumy[N][N];
int n,m,Q;

void Init()
{
	for(int i=1;i<=n;++i)
		for(int j=2;j<=m;++j)
			if(s[i][j]=='.'&&s[i][j-1]=='.')
				x[i][j]=1;
	for(int j=1;j<=m;++j)
		for(int i=2;i<=n;++i)
			if(s[i][j]=='.'&&s[i-1][j]=='.')
				y[i][j]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			sumx[i][j]=sumx[i-1][j]+sumx[i][j-1]+x[i][j]-sumx[i-1][j-1];
			sumy[i][j]=sumy[i-1][j]+sumy[i][j-1]+y[i][j]-sumy[i-1][j-1];
		}
	return ;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	Init();
	cin>>Q;
	while(Q--)
	{
		int X1,X2,Y1,Y2;
		scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
		int ansx=sumx[X2][Y2]-sumx[X2][Y1]-sumx[X1-1][Y2]+sumx[X1-1][Y1];
		int ansy=sumy[X2][Y2]-sumy[X2][Y1-1]-sumy[X1][Y2]+sumy[X1][Y1-1];
		printf("%d\n",ansx+ansy);
	}
	return 0;
}
