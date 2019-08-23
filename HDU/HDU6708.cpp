#include <bits/stdc++.h>
using namespace std;

char s[13][1025][1025];
int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		s[1][0][0]='C';s[1][0][1]='C';
		s[1][1][0]='P';s[1][1][1]='C';
		for (int i=2;i<=n;i++)
		{
			for (int j=0;j<(1<<(i-1));j++)
				for (int k=0;k<(1<<(i-1));k++)
				{
					s[i][j][k]=s[i-1][j][k];
					s[i][j+(1<<(i-1))][k]=s[i-1][j][k]=='C'?'P':'C';
					s[i][j][k+(1<<(i-1))]=s[i-1][j][k];
					s[i][j+(1<<(i-1))][k+(1<<(i-1))]=s[i-1][j][k];
				}
		}
		for (int i=0;i<(1<<n);i++) puts(s[n][i]);
		memset(s,0,sizeof s);
	}
	return 0;
}