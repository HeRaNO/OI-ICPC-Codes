#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
const int MAXN = 1e5+5;
const long long INF = 1e5+5;
const long long mod = 1e7+7;
long long x[MAXN],n,k,max1=-INF,max2=-INF,ans;
bool vis[MAXN];
struct Mat{
    int wid;
    long long mat[105][105];
    Mat operator * (const Mat &w) {
        Mat ret;
        ret.wid=wid;
        for(int i=1;i<=wid;i++) {
            for(int j=1;j<=wid;j++) {
                ret.mat[i][j]=0;
                for(int k=1;k<=wid;k++) {
                    ret.mat[i][j]=(ret.mat[i][j]+(mat[i][k]*w.mat[k][j])%mod)%mod;
                }
            }
        }
        return ret;
    }
    void print() {
        for(int i=1;i<=wid;i++) {
            for(int j=1;j<=wid;j++) {
                cout<<mat[i][j]<<' ';
            }
            cout<<endl;
        }
    }
};
long long find() {
	int pos=0;
	long long temp=-INF;
	for(int i=1;i<=n;i++) {
		if(temp<x[i] && !vis[i]) {
			temp=x[i];
			pos=i;
		}
	}
	vis[pos]=true;
	return temp;
}
Mat power(Mat base,long long r) {
    Mat ret;
    ret.wid=base.wid;
    for(int i=1;i<=ret.wid;i++) {
        for(int j=1;j<=ret.wid;j++) {
            ret.mat[i][j]=0;
        }
        ret.mat[i][i]=1;
    }
    while(r) {
        if(r&1) ret=ret*base;
        base=base*base;
        r>>=1;
    }
    return ret;
}
Mat base1;
int main() {
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)	scanf("%lld",&x[i]);
	max1=find();
	max2=find();
	if(max1+max2<0) {
		ans=((max1+max2+mod)*(k%mod))%mod;
		for(int i=1;i<=n;i++)	ans=(ans+x[i]+mod)%mod;
		printf("%lld\n",ans%mod);
		return 0;
	}
	base1.wid=3;
	base1.mat[1][1]=1;base1.mat[1][2]=1;base1.mat[1][3]=0;
	base1.mat[2][1]=1;base1.mat[2][2]=0;base1.mat[2][3]=0;
	base1.mat[3][1]=1;base1.mat[3][2]=1;base1.mat[3][3]=1;
	Mat temp;
	if(max1+max2==0)	temp=power(base1,k-1);
	else temp=power(base1,k);
	if(max1+max2==0)	ans=(max1*temp.mat[3][1])%mod;
	else	ans=((max1*temp.mat[3][1])%mod+(mod+(max2*temp.mat[3][2])%mod)%mod)%mod;
//	cout<<ans<<endl;;
	for(int i=1;i<=n;i++)
			ans=(ans+mod+x[i])%mod;
	cout<<ans%mod<<endl;
	return 0;
}