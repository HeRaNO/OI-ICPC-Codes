#include <bits/stdc++.h>
#define MAXN 60
using namespace std;

int n,ans,cnt,h[MAXN],a[MAXN],dp[MAXN];
char aa[]="23456789TJQKA";
char b[]="cdhs";
char s[MAXN][3];

int binary(int x)
{
	int left = 0, right = ans, middle;
	while (left < right)
	{
		middle = (left + right) >> 1;
		if (dp[middle] <= x) left = middle + 1;
		else right = middle;
	}
	return left;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]);
	do{
		for (int i=0;i<4;i++) h[b[i]-'a']=i;
		for (int sta=0;sta<16;sta++)
		{
			ans=0;
			for (int i=1;i<=n;i++)
			{
				int p=h[s[i][1]-'a'],q=-1;
				for (int j=0;j<13&&q==-1;j++) if (s[i][0]==aa[j]) q=j;
				if (sta&(1<<p)) q=12-q;
				a[i]=p*13+q;
			}
			dp[0]=-1;
			for (int i=1;i<=n;i++)
			{
				if (a[i]>=dp[ans]) dp[++ans]=a[i];
				else dp[binary(a[i])]=a[i];
			}
			cnt=max(ans,cnt);
		}
	}while (next_permutation(b,b+4));
	printf("%d\n",n-cnt);
	return 0;
}