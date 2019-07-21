#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const char huh[]="AHIMOTUVWXY\0";

bool ok[26];
int n,p;
char s[10000];

int main()
{
	int T;
	scanf("%d",&T);
	p=strlen(huh);
	for (int i=0;i<p;i++) ok[huh[i]-'A']=true;
	while (T--)
	{
		scanf("%s",s);n=strlen(s);
		bool f=true;
		for (int i=0;i<n&&f;i++)
			if (!ok[s[i]-'A']) f=false;
		for (int i=0;i<n&&f;i++)
			if (s[i]!=s[n-i-1]) f=false;
		puts(f?"yes":"no");
	}
	return 0;
}