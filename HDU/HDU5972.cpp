#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3+10,MAXM=5e6+10;
const int MOD=1e9+7,INF=~(1<<31);
const ll llINF=1999999999999999999;
#define lowbit(x) x&-x

bitset <1001> all[11],ans;

char s[MAXM];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p,temp;
		scanf("%d",&p);
		for(int j=1;j<=p;j++)
		{
			scanf("%d",&temp);
			all[temp][i]=1;
		}
	}
	gets(s);
	gets(s+1);
	int sz=strlen(s+1);
	for(int i=1;i<=sz;i++)
	{
		ans<<=1;
		int now=s[i]-'0';
		ans[0]=1;
		ans&=all[s[i]-'0'];
		if(ans[n-1])
		{
			char t=s[i+1];s[i+1]=0;
			puts(s+i-n+1);s[i+1]=t;
		}
	}
	return 0;
}