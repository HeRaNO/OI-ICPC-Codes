#include <bits/stdc++.h>
using namespace std;

int n,k;
char a[200010];

int main()
{
	int ans=0;
	scanf("%d %d",&n,&k);
	scanf("%s",a);
	for (char i='a';i<='z';i++)
	{
		int cnt=0,p=0;
		for (int j=0;j<n;j++)
		{
			if (a[j]!=i)
			{
				cnt+=p/k;p=0;
			}
			else p++;
		}
		cnt+=p/k;
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}