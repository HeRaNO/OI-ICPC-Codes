#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
const int INF=0x7fffffff;
const int MOD=20100403;

char s[MAXN],t[MAXN];
vector<int> v[30];

int main()
{
	int n,m,ans=-1;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++)
	{
		int c=s[i]-'a';
		for(int j=c;j>=0;j--)
			v[j].push_back(i);
	}
	int now=1;
	for(int i=1;i<=m;i++)
	{
		int c=t[i]-'a'+1;
		int temp=(int)(lower_bound(v[c].begin(),v[c].end(),now)-v[c].begin());
		if(temp<v[c].size())
		{
			temp=n-v[c][temp]+1;
			if(temp)
				ans=max(ans,i+temp-1);
		}
		while(s[now]!=t[i]&&now<=n)now++;
		if(now>n)break;
		now++;
	}
	if(now<=n) ans=max(ans,n-now+m+1);
	printf("%d",ans);
}