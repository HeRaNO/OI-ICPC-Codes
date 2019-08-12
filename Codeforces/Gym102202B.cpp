#include <bits/stdc++.h>
#define MAXN 3005
using namespace std;

char s[MAXN];
int n,m,cnt[MAXN],ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=n;j++) cnt[i]+=s[j]=='W';
		if (cnt[i]>cnt[ans]) ans=i;
	}
	if (cnt[ans]==n-1) printf("1 %d\n",ans);
	else printf("2 %d\n",ans);
	return 0;
}