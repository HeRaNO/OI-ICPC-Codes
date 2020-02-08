#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=300050;
int x;
string s;

int main()
{
	cin>>x;
	cin>>s;cin>>s;
	if(s[0]=='m')
	{
		if(x==31)puts("7");
		else if(x==30)puts("11");
		else puts("12");
	}
	else
	{
		if(x==5||x==6)puts("53");
		else puts("52");
	}
	return 0;
}
