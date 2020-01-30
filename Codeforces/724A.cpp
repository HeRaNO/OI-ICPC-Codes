#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1004535809,mod=998244353;
const int Lim=1<<15;
const int MAXN=4e5+10,INF=INT_MAX;

int p[]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string,int>mp;

int main()
{
	mp["monday"]=0;
	mp["tuesday"]=1;
	mp["wednesday"]=2;
	mp["thursday"]=3;
	mp["friday"]=4;
	mp["saturday"]=5;
	mp["sunday"]=6;
	string a,b;
	cin>>a>>b;
	int aa=mp[a],bb=mp[b];
	for(int i=0;i<=11;i++)
	{
		if((bb-aa+7)%7==p[i]%7)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
