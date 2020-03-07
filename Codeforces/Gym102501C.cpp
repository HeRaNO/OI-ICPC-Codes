#include <bits/stdc++.h>
using namespace std;

int n;
char s[105];
bool vis[1000000];

int main()
{
	scanf("%d",&n);
	for (int T=1;T<=n;T++)
	{
		scanf("%s",s);int x=0;
		if (s[0]=='-') continue;
		if (strlen(s)>=7) continue;
		for (int i=0;s[i];i++) x=(x<<3)+(x<<1)+s[i]-'0';
		vis[x]=true;
	}
	for (int i=0;i<1000000;i++)
		if (!vis[i]) return printf("%d\n",i),0;
	puts("1000000");
	return 0;
}