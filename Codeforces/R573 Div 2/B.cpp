#include <bits/stdc++.h>
using namespace std;

int a[10][3];
char s[4][2];
int ans=~(1<<31);

int f(char a)
{
	if (a=='m') return 0;
	if (a=='p') return 1;
	return 2;
}

int main()
{
	for (int i=1;i<=3;i++)
	{
		scanf("%s",s[i]);
		a[s[i][0]-'0'][f(s[i][1])]++;
	}
	for (int i=1;i<=3;i++)
	{
		ans=min(ans,3-a[s[i][0]-'0'][f(s[i][1])]);
	}
	for (int i=1;i<=3;i++)
	{
		int x=s[i][0]-'0';
		if (x-2>=1&&x-1>=1) ans=min(ans,(a[x-2][f(s[i][1])]==0)+(a[x-1][f(s[i][1])]==0));
		if (x-1>=1&&x+1<=9) ans=min(ans,(a[x-1][f(s[i][1])]==0)+(a[x+1][f(s[i][1])]==0));
		if (x+1<=9&&x+2<=9) ans=min(ans,(a[x+1][f(s[i][1])]==0)+(a[x+2][f(s[i][1])]==0));
	}
	printf("%d\n",ans);
	return 0;
}