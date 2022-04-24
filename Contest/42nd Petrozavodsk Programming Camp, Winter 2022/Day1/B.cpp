#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

int n;
char s[MAXN][MAXN];

inline void addCol(int i,int num,char x)
{
	for (int j=0;j<num;j++) s[j][i]=x;
	return ;
}

inline void addRow(int i,int num,char x)
{
	for (int j=0;j<num;j++) s[i][j]=x;
	return ;
}

int main()
{
	scanf("%d",&n);
	s[0][0]='B';s[0][1]='W';
	s[1][0]='W';s[1][1]='W';
	for (int i=2;i<n;i++)
	{
		if (i&1)
		{
			addCol(i,i+1,'W');
			addRow(i,i,'B');
		}
		else
		{
			addCol(i,i,'B');
			addRow(i,i+1,'W');
		}
	}
	for (int i=0;i<n;i++) puts(s[i]);
	return 0;
}
