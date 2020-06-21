#include <bits/stdc++.h>
using namespace std;

char s[4][15];
int p,q;

int main()
{
	scanf("%s",s[1]+1);
	scanf("%s",s[2]+1);
	scanf("%s",s[3]+1);
	for (int i=1;i<=3&&!p&&!q;i++)
		for (int j=1;j<=10&&!p&&!q;j++)
			if (s[i][j]=='=')
			{
				p=i;q=j;break;
			}
	for (int j=q+1;j<=10;j++)
		if (s[p][j]!='.')
		{
			putchar(s[p][j]);putchar('\n');
			return 0;
		}
	puts("You shall pass!!!");
	return 0;
}