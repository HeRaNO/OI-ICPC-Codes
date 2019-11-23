#include <bits/stdc++.h>
using namespace std;

int k,n;

inline int fp(int x,int y)
{
	int ans=1;
	for (int i=1;i<=y;i++) ans*=x;
	return ans;
}

int main()
{
	scanf("%d %d",&k,&n);int ans=0;
	for (int i=1;i<=n;i++) ans+=fp(k,i);
	printf("%d.00\n",ans);
	return 0;
}