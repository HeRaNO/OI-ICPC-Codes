#include <bits/stdc++.h>
using namespace std;
char s[2005];
int zero,one;

int main(){
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;++i){
		if(s[i]=='0')zero++;
		else one++;
	}
	if(zero==one){
		if(s[0]=='0'){
			s[0]='1';
			for(int i=1;i<n;++i){
				if(s[i]=='1')s[i]='0';
			}
		}
		else if(s[0]=='1'){
			s[0]='0';
			for(int i=1;i<n;++i){
				if(s[i]=='0')s[i]='1';
			}
		}
	}
	else{
		if(zero>one){
			for(int i=0;i<n;++i){
				if(s[i]=='0')s[i]='1';
			}
		}
		else if(zero<one){
			for(int i=0;i<n;++i){
				if(s[i]=='1')s[i]='0';
			}
		}
	}
	cout<<s<<endl;
	return 0;
}
