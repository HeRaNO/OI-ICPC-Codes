#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e6+10,MAXM=1e4+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;
const ll llINF=~(1ll<<63);

char s[MAXN];
bool vis[5005][5005];

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=0,q=0;
		for(int j=i;j<=n;j++)
		{
			if(s[j]=='(')l++;
			if(s[j]==')')r++;
			if(s[j]=='?')q++;
			if(r>l+q)break;
			if((r+l+q)%2==0)vis[i][j]=1;
		}
	}
	for(int j=n;j>0;j--)
	{
		int l=0,r=0,q=0;
		for(int i=j;i>0;i--)
		{
			if(s[i]=='(')l++;
			if(s[i]==')')r++;
			if(s[i]=='?')q++;
			if(l>r+q)break;
			if((r+l+q)%2==0&&vis[i][j])ans++;
		}
	}
	cout<<ans;
	return 0;
}