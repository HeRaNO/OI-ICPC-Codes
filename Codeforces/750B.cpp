#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,MOD=1e9+7;
const ll llINF=~(1ll<<63);

char s[MAXN];
int p=20000,c;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int q;
		scanf("%d",&q);
		scanf("%s",s);
		if(s[0]=='S')
		{
			c+=q;
			if(c>p)
				return puts("NO"),0;
		}
		else if(s[0]=='N')
		{
			c-=q;
			if(c<0)
				return puts("NO"),0;
		}
		else if(s[0]=='E'||s[0]=='W')
		{
			if(c==0||c==p)return puts("NO"),0;
		}
	}
	if(c)return puts("NO"),0;
	puts("YES");
	return 0;
}