#include <cstdio>
#include <cstring>
#include <queue>
#include <bitset>
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define defor(i,a,b) for(int i=a;i>=b;--i)
#define infor(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int n;
int ans;
int d[7][25]={
    {0,1,8,14,4,3,7,13,17,9,10,2,6,12,16,15,5,11,18,19,20,21,22,23},
    {0,1,11,5,4,16,12,6,2,9,10,17,13,7,3,15,14,8,18,19,20,21,22,23},
    {1,3,0,2,23,22,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20,21,9,8},
    {2,0,3,1,6,7,8,9,23,22,10,11,12,13,14,15,16,17,18,19,20,21,5,4},
    {6,1,12,3,5,11,16,7,8,9,4,10,18,13,14,15,20,17,22,19,0,21,2,23},
    {20,1,22,3,10,4,0,7,8,9,11,5,2,13,14,15,6,17,12,19,16,21,18,23},
};

void dfs(int step,int *a){
	int ret=0;
	if(a[0]==a[1]&&a[0]==a[2]&&a[0]==a[3])ret++;
	if(a[4]==a[5]&&a[4]==a[10]&&a[4]==a[11])ret++;
	if(a[6]==a[7]&&a[6]==a[12]&&a[6]==a[13])ret++;
	if(a[8]==a[9]&&a[8]==a[14]&&a[8]==a[15])ret++;
	if(a[16]==a[17]&&a[16]==a[18]&&a[16]==a[19])ret++;
	if(a[20]==a[21]&&a[20]==a[22]&&a[20]==a[23])ret++;
	ans=max(ans,ret);
	if(step==0||ans==6)return;
	int v[25];
	for(int i=0;i<6;++i){
		for(int j=0;j<24;++j){
			v[j]=a[d[i][j]];
		}
		dfs(step-1,v);
	}
}
int b[25];

int main(){
	while(~scanf("%d",&n)){
		ans=0;
		for(int i=0;i<24;++i)read(b[i]);
		dfs(n,b);
		printf("%d\n",ans);
	}
	return 0;
}