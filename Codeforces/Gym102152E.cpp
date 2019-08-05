#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
const int INF=0x7fffffff;
int num[30];
char  a[50000];
char b[MAXN];
char nn[MAXN];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		for(int i=0;i<30;i++)
			num[i]=INF;
		scanf("%d%d",&n,&m);
		scanf("%s",a);
		scanf("%s",nn);
		for(int i=0;i<n;i++)
		{
			int ch;
			ch=nn[i]-'0';
			num[a[i]-'a']=min(num[a[i]-'a'],ch);
		}
		scanf("%s",b);
		ll ans=0;
		bool flag=false;
		for(int i=0;i<m;i++)
		{
			if(num[b[i]-'a']==INF)
			{
				printf("-1\n");
				flag=true;
				break;
			}
			ans+=num[b[i]-'a'];
		}
		if(flag)
		{
			continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}