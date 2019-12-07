#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,MOD=1e9+7;
const ll llINF=~(1ll<<63);

char s[MAXM];
int num[30],l=0,r=26;
int n,len,k;
string ans[1005];

char getl()
{
	while(!num[l])l++;
	num[l]--;
	return l+'a';
}

char getr()
{
	while(!num[r])r--;
	num[r]--;
	return r+'a';
}

bool check(int p,int len)
{
	for(int i=0;i<len;i++)
		if(ans[p][i]!=ans[k][i])return false;
	return true;
}

int main()
{
	scanf("%d%d%d",&n,&len,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n*len;i++)
		num[s[i]-'a']++;
	for(int i=1;i<=k;i++)
		ans[i]+=getl();
	for(int i=k+1;i<=n;i++)
		ans[i]+=getr();
	for(int j=1;j<len;j++)
		for(int i=1;i<=n;i++)
		{
			if(check(i,j))ans[i]+=getl();
			else ans[i]+=getr();
		}
	sort(ans+1,ans+n+1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
