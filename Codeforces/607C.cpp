#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=5e6+10,MAXM=2e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x

int n;
char s[MAXN],t[MAXN];
void trav(char &c)
{
	if(c=='N')c='S';
	else if(c=='S')c='N';
	else if(c=='W')c='E';
	else if(c=='E')c='W';
}

int nxt[MAXN];

void kmp()
{
	nxt[1]=0;
	int j=0;
	for(int i=2;i<n*2;i++)
	{
		while(j&&s[i]^s[j+1])j=nxt[j];
		if(s[i]==s[j+1])j++;
		nxt[i]=j;
	}
}

int main()
{
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	reverse(s+1,s+n);
	for(int i=1;i<n;i++)trav(s[i]);
	s[n]='#';
	for(int i=1;i<n;i++)s[i+n]=t[i];
	kmp();
	if(nxt[n*2-1])return puts("NO"),0;
	puts("YES");
	return 0;
}
