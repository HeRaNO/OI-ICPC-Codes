#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=998244353,mod=119;
const int Lim=1<<20;

char s[MAXN];

int main()
{
	scanf("%s",s+1);
	int sz=strlen(s+1);
	for(int i=1;i<=sz;i++)s[sz*2-i+1]=s[i];
	s[sz*2+1]='\0';
	cout<<s+1;
	return 0;
}
