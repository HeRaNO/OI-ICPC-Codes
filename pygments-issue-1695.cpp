#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int main(){
	long long n;
	//n=6;//
	cin>>n;
	int result_0=1,result_1=0;
	int cur_0=0,cur_1=1;
	long long temp_0,temp_1,temp_2;
	while(n){
		if(n&1){
			temp_0=(long long)cur_0*result_0;
			temp_1=(long long)cur_0*result_1+(long long)cur_1*result_0;
			//temp_2=(long long)result_1*result_1;<---------------
			temp_2=(long long)cur_1*result_1;
			//result_0=(temp_0-temp_2)%mod;<-----------------
			//result_1=(temp_1-2*temp_2)%mod;
			result_0=(temp_0+temp_2)%mod;
			result_1=(temp_1+temp_2)%mod;
		}
		temp_0=(long long)cur_0*cur_0;
		temp_1=(long long)cur_0*cur_1*2;
		temp_2=(long long)cur_1*cur_1;
		//cur_0=(temp_0-temp_2)%mod;<-----------------
		//cur_1=(temp_1-2*temp_2)%mod;
		cur_0=(temp_0+temp_2)%mod;
		cur_1=(temp_1+temp_2)%mod;
		n>>=1;
	}
	int m11=((result_0*1+/*cur*/result_1*1)%mod+mod)%mod;
	int m12=((result_0*0+result_1*1)%mod+mod)%mod;
	int m21=((result_0*0+result_1*/*0<-----*/1)%mod+mod)%mod;
	int m22=((result_0*1+result_1*/*1<-----*/0)%mod+mod)%mod;
	cout<<(long long)(m11*1+m12*0)%mod*(/*m12*0+m22*1<------*/m21*1+m22*0)%mod<<endl;
}
