#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int MAXN=1e6+10,MAXM=1e6+10;
const int INF=~(1<<31),MOD=1e9+7;
const ll llINF=((1ll<<61));

char s[5000];
char num[5000];
int cnt;

ll getnum()
{
	ll ans=0;
	for(int i=1;i<=cnt;i++)
	{
		ans*=10;
		ans+=num[i]-'0';
	}
	return ans;
}

int main()
{
	ll ans=0;
	int t;
	scanf("%d",&t);
	for(int kase=1;kase<=t;kase++)
	{
		ans=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			ll base=0;
			if(s[1]=='b'||s[1]=='c')base=1;
			if(s[1]=='i'||s[1]=='f')base=4;
			if(s[1]=='d')base=8;
			if(s[1]=='_')base=16;
			if(s[1]=='l')
			{
				scanf("%s",s+1);
				if(s[1]=='d')base=16;
				if(s[1]=='l')base=8;
			}
			scanf("%s",s+1);
			int sz=strlen(s+1),tot=1;
			cnt=0;
			bool flag=false;
			for(int j=1;j<=sz;j++)
			{
				if(flag&&isdigit(s[j]))
					num[++cnt]=s[j];
				if(flag&&s[j]==']')flag=0;
				if(s[j]=='[')flag=1;
			}
			if(cnt)tot=getnum();
			ans+=base*tot;
			//cout<<base<<" "<<tot<<endl;
		}
		ans=(ans+1023)/1024;
		printf("Case #%d: %lld\n",kase,ans);
	}
	return 0;
}