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
const int MOD=998244353,mod=1e9+7;
const int Lim=1<<20;

vector<int> v;
int num[26];

int main()
{
	v.push_back(0);
	for(int i=1;i<1000;i++)v.push_back((i-1)*i/2);
	int k;
	scanf("%d",&k);
	for(int i=0;i<26;i++)
	{
		num[i]=upper_bound(v.begin(),v.end(),k)-v.begin()-1;
		k-=v[num[i]];
	}
	for(int i=0;i<26;i++)while(num[i]--)printf("%c",'a'+i);
	return 0;
}