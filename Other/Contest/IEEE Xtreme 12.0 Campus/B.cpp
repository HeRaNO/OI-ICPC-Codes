//Decision's template
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define DP_maxn 16
#define maxn 5007
#define INF 1e18
#define mod 100000007
#define mst(s,k) memset(s,k,sizeof(s))
typedef long long ll;
struct Edge{
	int from,to,dist;
	Edge(int u,int v):from(u),to(v){}
};
/*-------------------------------template End--------------------------------*/

int n;
char s1[20000007],s2[20000007];
long long p[20000007],id = 1,mx = 1,ans = 0;

int init(){
	s2[0] = '$';
	s2[1] = '#';
	int j = 2;
	int len = strlen(s1);
	for(int i = 0;i<len;i++){
		s2[j++] = s1[i];
		s2[j++] = '#';
	}
	s2[j] = '\0';
	return j;
}

int main(){
	cin>>n;
	memset(p,0,sizeof(p));
	cin>>s1;
	int len = init();
	for(int i = 1;i<len;i++){
		if(i < mx) p[i] = min(p[2 * id - 1],mx - i);
		else p[i] = 1;
		while(s2[i - p[i]] == s2[i + p[i]]){
			p[i] ++;
		}
		if(mx < i + p[i]){
			id = i;
			mx = i + p[i];
		}
//		cout<<s2[i]<<' '<<p[i]<<endl;
		if(s2[i]=='#')	ans=(ans + (p[i]-1)/2)%mod;
		else	ans = (ans + (p[i]) / 2) % mod;
	}
	ans = ans % mod;
//	cout<<len<<' '<<s2<<endl;
	cout<<ans<<endl;
	return 0;
}