#include <bits/stdc++.h>
#define MAXN 10000005
using namespace std;

char s[MAXN];
int n,p1,p2;

int main()
{
	scanf("%s",s);n=strlen(s);
	p1=0;p2=n-1;
	while (p1<p2)
	{
		if (s[p1]==s[p2]){++p1;--p2;}
		else if (s[p1]==s[p2-1]) s[p2--]=0;
		else if (s[p1+1]==s[p2]) s[p1++]=0;
		else if (s[p1+1]==s[p2-1])
		{
			s[p1++]=0;s[p2--]=0;
		}
	}
	int cnt=0;
	for (int i=0;i<n;i++) if (s[i]) ++cnt;
	if(cnt<n/2) printf("IMPOSSIBLE\n");
	else
	{
		for (int i=0;i<n;i++) if (s[i]) putchar(s[i]);
		putchar('\n');
	}
	return 0;
}