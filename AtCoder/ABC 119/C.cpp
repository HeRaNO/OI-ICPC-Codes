#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,l[10],o[10],ans=~(1<<31);
bool len[1010],vis[10];

inline int f(int l,int s,int p)
{
	if (l==1) return abs(p-s);
	else return (l-1)*10+abs(p-s);
}

void check(int le)
{
	for (int i=1;i<le;i++)
		for (int j=i+1;j<le;j++)
		{
			int l1=i,l2=j-i,l3=le-j;
			int s1=0,s2=0,s3=0;
			for (int k=1;k<=i;k++) s1+=l[o[k]];
			for (int k=i+1;k<=j;k++) s2+=l[o[k]];
			for (int k=j+1;k<=le;k++) s3+=l[o[k]];
			ans=min(ans,f(l1,s1,a)+f(l2,s2,b)+f(l3,s3,c));
			ans=min(ans,f(l1,s1,a)+f(l2,s2,c)+f(l3,s3,b));
			ans=min(ans,f(l1,s1,b)+f(l2,s2,a)+f(l3,s3,c));
			ans=min(ans,f(l1,s1,b)+f(l2,s2,c)+f(l3,s3,a));
			ans=min(ans,f(l1,s1,c)+f(l2,s2,b)+f(l3,s3,a));
			ans=min(ans,f(l1,s1,c)+f(l2,s2,a)+f(l3,s3,b));
		}
	return ;
}

void dfs(int x,int l)
{
	if (x==l+1)
	{
		check(l);
		return ;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			vis[i]=true;o[x]=i;dfs(x+1,l);vis[i]=false;
		}
	return ;
}

int main()
{
	scanf("%d %d %d %d",&n,&a,&b,&c);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
		len[l[i]]=true;
	}
	if (len[a]&&len[b]&&len[c])
	{
		puts("0");return 0;
	}
	for (int i=3;i<=n;i++) dfs(1,i);
	printf("%d\n",ans);
	return 0;
}