#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

int T,n;
string ans;
char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);scanf("%s",s+1);ans.clear();
		for (int i=1;i<=n;i++) ans.push_back('z');
		int k=1;string now;
		for(int i=1;i<=n;i++)
		{
			now.clear();
			for (int j=i;j<=n;j++) now.push_back(s[j]);
			if ((n-i+1)&1)
			{
				for(int j=i-1;j;j--) now.push_back(s[j]);
			}
			else
			{
				for (int j=1;j<i;j++) now.push_back(s[j]);
			}
			if (now<ans)
			{
				ans=now;
				k=i;
			}
		}
		cout<<ans<<'\n';
		cout<<k<<'\n';
	}
	return 0;
}