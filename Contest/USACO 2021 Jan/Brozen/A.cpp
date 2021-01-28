#include <bits/stdc++.h>
using namespace std;

int f[26],p[1005];
char s[1005],a[1005];

int main(int argc, char const *argv[])
{
	scanf("%s",a);
	for (int i=0;i<26;i++) f[a[i]-'a']=i;
	scanf("%s",s);
	int n=strlen(s);
	for (int i=0;i<n;i++) p[i]=f[s[i]-'a'];
	int ans=1;
	for (int i=1;i<n;i++) if (p[i]<=p[i-1]) ++ans;
	printf("%d\n",ans);
	return 0;
}