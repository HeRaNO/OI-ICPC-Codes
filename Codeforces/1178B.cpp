#include <bits/stdc++.h>
#define MAXN 10000005
using namespace std;

int n,p,pre[MAXN],suf[MAXN];
char s[MAXN];
long long ans;

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='v') ++p;
		else{pre[i]=max(p-1,0);p=0;}
	}
	pre[n+1]=p;p=0;
	for (int i=n;i;i--)
	{
		if (s[i]=='v') ++p;
		else{suf[i]=max(p-1,0);p=0;}
	}
	suf[0]=p;
	for (int i=1;i<=n+1;i++) pre[i]+=pre[i-1];
	for (int i=n;~i;i--) suf[i]+=suf[i+1];
	for (int i=1;i<=n;i++) if (s[i]=='o') ans+=1LL*pre[i]*suf[i];
	printf("%lld\n",ans);
	return 0;
}