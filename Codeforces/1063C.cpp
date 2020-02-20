#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

char s[MAXN],p[50];
int l,r;
void ask(int x)
{
	printf("%d 1\n",x);
	fflush(stdout);
	scanf("%s",s+1);
	if(s[1]^p[1])r=x;
	else l=x;
}

int main()
{
	int n;
	scanf("%d",&n);
	l=0,r=1e9;
	puts("0 1");
	fflush(stdout);
	scanf("%s",s+1);
	p[1]=s[1];
	for(int i=1;i<n;i++)
	{
		int mid=(l+r)>>1;
		ask(mid);
	}
	printf("%d 0 %d 2",(l+r)/2,(l+r)/2+1);
	return 0;
}
