#include <bits/stdc++.h>
#define MAXN 100010

char s[MAXN],sta[MAXN],c[3];
int n,k,i,top,p;

int main()
{
	while (~scanf("%d %d",&n,&k))
	{
		for (i=1;i<=n;i++){scanf("%s",c);s[i]=c[0];}
		top=0;i=1;p=n-k;
		while (i<=n)
		{
			while (sta[top]<s[i]&&top&&p) --top,--p;
			sta[++top]=s[i++];
		}
		for (int i=1;i<=k;i++) putchar(sta[i]);putchar('\n');
	}
	return 0;
}