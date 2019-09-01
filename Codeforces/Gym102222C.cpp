#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e6+10,INF=0x7fffffff;
const ll llINF=0x7fffffffffffffff,MOD=1e9+7;
#define lowbit(x) x&-x

int n,m;
char s[105];
char s1[105];
char s2[105];

int main()
{
	int t,kase=0;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s%s%s",s1,s2,s);
		int c=s1[0]-s2[0];
		printf("Case #%d: ",++kase);
		for(int i=0;i<m;i++)
			printf("%c",(s[i]-'A'+c+26)%26+'A');
		cout<<endl;
	}
	return 0;
}