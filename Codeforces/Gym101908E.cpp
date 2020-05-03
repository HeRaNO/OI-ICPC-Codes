#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

int n,m,ans;
char s[MAXN],t[MAXN];

int main(int argc, char const *argv[])
{
	scanf("%s",s);n=strlen(s);
	scanf("%s",t);m=strlen(t);
	for (int i=0;i<=n-m;i++)
	{
		bool f=true;
		for (int j=0;j<m&&f;j++)
			if (s[i+j]==t[j]) f=false;
		if (f) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}