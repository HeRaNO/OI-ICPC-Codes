#include <bits/stdc++.h>
using namespace std;

int n;
char s[1000005];

int main()
{
	scanf("%s",s);n=strlen(s);
	for (int i=0;i+2<n;i++)
		if (s[i]=='A'&&s[i+1]=='C'&&s[i+2]=='M')
			return puts("Fun!"),0;
	puts("boring...");
	return 0;
}