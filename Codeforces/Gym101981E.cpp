#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int n,k,cnt[MAXN],now;
char a[MAXN],b[MAXN];
int stk[MAXN][2],top1;
int stkk[MAXN][2],top2;

int main()
{
	scanf("%d %d",&n,&k);
	if (k==1) return puts("Yes"),0;
	scanf("%s",a+1);scanf("%s",b+1);
	for (int i=1;i<=n;i++)
	{
		if (stk[top1][0]==a[i]-'0')
		{
			int p,q;
			p=a[i]-'0';q=stk[top1][1]+1;
			if (q==k) top1-=(k-1);
			else
			{
				stk[++top1][0]=p;stk[top1][1]=q;
			}
		}
		else
		{
			stk[++top1][0]=a[i]-'0';
			stk[top1][1]=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (stkk[top2][0]==b[i]-'0')
		{
			int p,q;
			p=b[i]-'0';q=stkk[top2][1]+1;
			if (q==k) top2-=(k-1);
			else
			{
				stkk[++top2][0]=p;stkk[top2][1]=q;
			}
		}
		else
		{
			stkk[++top2][0]=b[i]-'0';
			stkk[top2][1]=1;
		}
	}
	for (int i=top1+1;i<=n;i++) stk[i][0]=0;
	for (int i=top2+1;i<=n;i++) stkk[i][0]=0;
	for (int i=1;i<=n;i++) if (stk[i][0]!=stkk[i][0]) return puts("No"),0;
	puts("Yes");
	return 0;
}