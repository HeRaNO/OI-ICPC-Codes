#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e3+10,INF=~(1<<31),MOD=1e9+7,mod=998244353;
const int MAXM=5e6+10;
const ll llINF=~(1ll<<63);
const double Pi=acos(-1.0);
#define lowbit(x) x&-x

char a[MAXN];
int n;
int lst,p;

bool peak(int sz)
{
	if(sz==-1)return false;
	for(int i=1;i+a[sz]<p+'a';++i)
	{
		if((sz>0&&a[sz]+i==a[sz-1])||(sz>1&&a[sz]+i==a[sz-2]))continue;
		a[sz]+=i;return true;
	}
	if(!peak(sz-1))return false;
	a[sz]='a';
	for(int i=0;i+a[sz]<p+'a';++i)
	{
		if((sz>0&&a[sz]+i==a[sz-1])||(sz>1&&a[sz]+i==a[sz-2]))continue;
		a[sz]+=i;return true;
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&p);
	scanf("%s",a);
	if(peak(n-1))printf("%s\n",a);
	else puts("NO");
	return 0;
}