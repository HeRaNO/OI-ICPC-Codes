#include <bits/stdc++.h>
#define MAXN 105
#define MAXL 505
using namespace std;

const int M=998244353;

struct otomad
{
	int r;
	char s[MAXL];
};

int n,lenS,m[MAXN],nxt[MAXL],dp[MAXN][MAXL],pos[MAXN][MAXL];
otomad a[MAXN][MAXL];
char s[MAXL];

void GetNext(char S[])
{
	int i=0,j=-1;lenS=strlen(S);
	nxt[0]=-1;
	while (i!=lenS)
	{
		if (!~j||S[i]==S[j]) nxt[++i]=++j;
		else j=nxt[j];
	}
	return ;
}

inline void fadd(int &a,int b){a+=b;if (a>=M) a-=M;return ;}

int dfs(int x,int p)
{
	if (dp[x][p]!=-1) return dp[x][p];
	int j=p;dp[x][p]=0;
	for (int i=1;i<=m[x];i++)
		if (a[x][i].r)
		{
			fadd(dp[x][p],dfs(a[x][i].r,j));
			j=pos[a[x][i].r][j];
		}
		else
		{
			int k=0;
			while (a[x][i].s[k]&&j<lenS)
			{
				if (!~j||a[x][i].s[k]==s[j])
				{
					++k;++j;
					if (j==lenS)
					{
						fadd(dp[x][p],1);
						j=nxt[j-1];--k;
					}
				}
				else j=nxt[j];
			}
		}
	pos[x][p]=j;
	return dp[x][p];
}

int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		for (int j=1;j<=m[i];j++)
		{
			scanf("%s",a[i][j].s);
			if (a[i][j].s[0]>='0'&&a[i][j].s[0]<='9')
			{
				int x=0;
				for (int k=0;a[i][j].s[k];k++)
					x=x*10+a[i][j].s[k]-'0';
				a[i][j].r=x;
			}
		}
	}
	scanf("%s",s);
	GetNext(s);
	printf("%d\n",dfs(n,0));
	return 0;
}