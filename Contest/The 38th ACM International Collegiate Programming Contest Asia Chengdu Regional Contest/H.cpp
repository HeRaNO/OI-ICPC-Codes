#include <bits/stdc++.h>
using namespace std;

double _2[100],_10[100];
int cas,T;
char s[100];

int main()
{
	scanf("%d",&T);_2[0]=_10[0]=1;
	for (int i=1;i<=80;i++) _2[i]=_2[i-1]*2;
	for (int i=1;i<=24;i++) _10[i]=_10[i-1]*10;
	while (T--)
	{
		scanf("%s",s);int i=0;double p;int x=0;
		for (i=0;s[i];i++)
		{
			if (s[i]=='[') break;
			x=(x<<3)+(x<<1)+s[i]-'0';
		}
		++i;
		if (s[i]=='B') p=_10[0]/_2[0];
		else if (s[i]=='K') p=_10[3]/_2[10];
		else if (s[i]=='M') p=_10[6]/_2[20];
		else if (s[i]=='G') p=_10[9]/_2[30];
		else if (s[i]=='T') p=_10[12]/_2[40];
		else if (s[i]=='P') p=_10[15]/_2[50];
		else if (s[i]=='E') p=_10[18]/_2[60];
		else if (s[i]=='Z') p=_10[21]/_2[70];
		else p=_10[24]/_2[80];
		printf("Case #%d: %.2lf",++cas,100*(1-p));
		puts("%");
	}
	return 0;
}