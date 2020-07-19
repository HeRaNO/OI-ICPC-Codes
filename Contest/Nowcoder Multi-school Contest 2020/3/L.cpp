#include <bits/stdc++.h>
using namespace std;

char s[10000000];
int n;

int main()
{
	scanf("%s",s);n=strlen(s);
	for (int i=0;i<n;i++) s[i]=tolower(s[i]);
	if (s[0]=='l'&&s[1]=='o'&&s[2]=='v'&&s[3]=='e'&&s[4]=='l'&&s[5]=='y')
		puts("lovely");
	else puts("ugly");
	return 0;
}