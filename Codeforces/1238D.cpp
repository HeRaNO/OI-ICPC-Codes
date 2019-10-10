#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

int n,cnt1=-1,cnt2=-1;
long long ans;
char s[MAXN];

int main()
{
	scanf("%d",&n);ans=1LL*n*(n-1)/2;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='A')
		{
			cnt1=0;
			if(cnt2>=0) ++cnt2;
			if(cnt2>1) --ans;
		}
		else
		{
			if (cnt1>=0) cnt1++;
			cnt2=0;
			if (cnt1>1) --ans;
		}
	}
	cnt1=cnt2=-1;
	for(int i=n;i>=1;i--)
	{
		if (s[i]=='A')
		{
			cnt1=0;
			if (cnt2>=0) ++cnt2;
			if (cnt2>1) --ans;
		}
		else
		{
			if (cnt1>=0) ++cnt1;
			cnt2=0;
			if (cnt1>1) --ans;
		}
	}
	for (int i=1;i<n;i++) if(s[i]!=s[i+1]) --ans;
	printf("%lld\n",ans);
	return 0;
}