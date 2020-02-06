#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=5050;
int n,m;
vector <int> ans1,ans2;
struct String
{
	int num1,num2,op;
	int num[1050];
}p[N];
int tot,bit[N];
string s,var;
map <string,int> vis;
inline int cal(int now,int pos)
{
	int ret=0;
	bit[0]=now;
	for(int i=1;i<=n;++i)
	{
		int a=bit[p[i].num1],b=bit[p[i].num2];
		switch(p[i].op)
		{
			case 1:
			{
				bit[i]=a&b;
				break;
			}
			case 2:
			{
				bit[i]=a|b;
				break;
			}
			case 3:
			{
				bit[i]=a^b;
				break;
			}
			case 4:
			{
				bit[i]=p[i].num[pos];
				break;
			}
		}
		ret+=bit[i];
	}
	return ret;
}

int main()
{
	cin>>n>>m;
	vis["?"]=0;
	for(int i=1;i<=n;++i)
	{
		cin>>var;cin>>s;cin>>s;
		vis[var]=++tot;
		if(s[0]=='0'||s[0]=='1')
		{
			p[i].op=4;
			for(int j=1;j<=m;++j)
				p[i].num[j]=s[j-1]-'0';
			continue;
		}
		p[i].num1=vis[s];
		cin>>s;
		if(s[0]=='A')p[i].op=1;
		else if(s[0]=='O')p[i].op=2;
		else if(s[0]=='X')p[i].op=3;
		cin>>s;
		p[i].num2=vis[s];
	}
	for(int i=1;i<=m;++i)
	{
		int tmp1=cal(0,i);
		int tmp2=cal(1,i);
		if(tmp1<=tmp2)ans1.push_back(0);else ans1.push_back(1);
		if(tmp1>=tmp2)ans2.push_back(0);else ans2.push_back(1);
	}
	for(auto i:ans1)cout<<i;
	cout<<endl;
	for(auto i:ans2)cout<<i;
	return 0;
}
