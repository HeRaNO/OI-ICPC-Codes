#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,k;
char s[MAXN];

int main()
{
	scanf("%d %d",&n,&k);
	scanf("%s",s);
	if (!k) return puts(s),0;
	if (n==1) return puts("0"),0;
	int cnt;
	if (s[0]>'1')
	{
		cnt=k-1;s[0]='1';
	}
	else
	{
		cnt=k;
	}
	for (int i=1;i<n;i++)
	{
		if (s[i]=='0') continue;
		if (!cnt) break;
		s[i]='0';--cnt;
	}
	puts(s);
	return 0;
}