#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e6+10,INF=0x7fffffff;

char s[505][505];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int ans=0;
	if(n==1||m==1)
	{
		if(n==1)
			for(int j=2;j<m;j++)
				if(s[1][j]=='.')ans++;
		if(m==1)
			for(int j=2;j<n;j++)
				if(s[j][1]=='.')ans++;
	}
	else if(n==2||m==2)
	{
		if(n==2)
			for(int i=2;i<m;i++)
				if(s[1][i]=='.'&&s[2][i]=='.')ans++;
		if(m==2)
			for(int i=2;i<n;i++)
				if(s[i][1]=='.'&&s[i][2]=='.')ans++;
	}
	else if(n>2&&m>2)
	{
		for(int i=2;i<n;i++)
			for(int j=2;j<m;j++)
				if(s[i][j]=='.')ans++;
		int temp=1;
		for(int i=2;i<n;i++)
		{
			if(s[i][1]=='#')temp=0;
			if(s[i][m]=='#')temp=0;
		}
		for(int i=2;i<m;i++)
		{
			if(s[1][i]=='#')temp=0;
			if(s[n][i]=='#')temp=0;
		}
		ans+=temp;
	}
	printf("%d",ans);
	return 0;
}

