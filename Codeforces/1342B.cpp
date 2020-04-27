#include <bits/stdc++.h>
using namespace std;

int T;
char s[105];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s);int n=strlen(s);int p=0;
		for (int i=0;i<n;i++) p|=(1<<(s[i]-'0'));
		if (p==3)
		{
			for (int i=0;i<(n<<1);i++)
				putchar(i&1?'1':'0');
			putchar('\n');
		}
		else puts(s);
	}
	return 0;
}