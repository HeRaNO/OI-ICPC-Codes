#include <bits/stdc++.h>
using namespace std;

int n;int cnt[20];

int main()
{
	while (true)
	{
		memset(cnt,0,sizeof cnt);
		string s;
		cin>>n;getline(cin,s);
		if (!n) break;
		for (int i=1;i<=n;i++)
		{
			getline(cin,s);int l=s.length();
			s=s.substr(l-8,4);
			if (s==" no ") cnt[i]=-1;
			else cnt[i]=1;
		}
		for (int i=1;i<=(n+1)>>1;i++) printf("%d ",i);
		puts("Score");
		int c=0;
		for (int i=1;i<=(n+1)>>1<<1;i+=2)
		{
			if (!~cnt[i]) printf("X ");
			else if (!cnt[i]) printf("- ");
			else printf("O "),++c;
		}
		printf("%d\n",c);c=0;
		for (int i=2;i<=(n+1)>>1<<1;i+=2)
		{
			if (!~cnt[i]) printf("X ");
			else if (!cnt[i]) printf("- ");
			else printf("O "),++c;
		}
		printf("%d\n",c);c=0;
	}
	return 0;
}