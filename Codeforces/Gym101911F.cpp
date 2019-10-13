#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=~(1<<31),MAXN=3e5+10;

int a[40];
int num[40];
int res[MAXN];

pair<int,int> s[MAXN];

int chai(int x)
{
	int b=0,c=0;
	for(int i=1;i<=3;i++)
	{
		b+=x%10;
		x/=10;
	}
	for(int i=1;i<=3;i++)
	{
		c+=x%10;
		x/=10;
	}
	return abs(b-c);
}

int cnt=1,n;

void dfs(int dep,int ans)
{
	if(cnt>n)return;
	if(dep==7)
	{
		if(ans==s[cnt].first)
		{
			int tmp=chai(ans),pp=0;
			for(int i=0;i<tmp;i++)
				pp+=num[i];
			res[s[cnt++].second]=pp;
		}
		num[chai(ans)]++;
		return;
	}
	for(int i=0;i<=9;i++)
	{
		dfs(dep+1,ans*10+i);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i].first);
		s[i].second=i;
	}
	sort(s+1,s+n+1);
	dfs(1,0);
	for(int i=1;i<=n;i++)
		printf("%d\n",res[i]);
	return 0;
}