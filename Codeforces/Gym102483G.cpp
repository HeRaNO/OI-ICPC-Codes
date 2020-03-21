#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define noway puts("impossible")
using namespace std;
const int N=400050;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char s[25];
vector < pii > ans;
int n;
int x,y;
bool check(int i)
{
	if(s[i]=='L'&&s[i-1]=='R')return 0;
	if(s[i]=='R'&&s[i-1]=='L')return 0;
	if(s[i]=='U'&&s[i-1]=='D')return 0;
	if(s[i]=='D'&&s[i-1]=='U')return 0;
	return 1;
}

void solve()
{
//    if(s[n]=='L')ans.push_back({8,0}),x=7,y=0;
//    if(s[n]=='R')ans.push_back({-8,0}),x=-7,y=0;
//    if(s[n]=='U')ans.push_back({0,-8}),x=0,y=-7;
//    if(s[n]=='D')ans.push_back({0,8}),x=0,y=7;
	int now=0;
	for(int i=1;i<n-1;++i)
	{
		if(check(i))now+=2;
		if(s[i]=='L')
		{
			ans.push_back({now,y});
			x=-now+1;
			ans.push_back({-now,y});
		}
		if(s[i]=='R')
		{
			ans.push_back({now,y});
			x=now-1;
			ans.push_back({-now,y});
		}
		if(s[i]=='U')
		{
			ans.push_back({x,now});
			y=now-1;
			ans.push_back({x,-now});
		}
		if(s[i]=='D')
		{
			ans.push_back({x,now});
			y=-(now-1);
			ans.push_back({x,-now});
		}
	}
	if(check(n-1))now+=2;
	if(s[n-1]=='L')ans.push_back({-now,y}),x=-now+1;
	if(s[n-1]=='R')ans.push_back({now,y}),x=now-1;
	if(s[n-1]=='U')ans.push_back({x,now}),y=now-1;
	if(s[n-1]=='D')ans.push_back({x,-now}),y=-now+1;
	now+=20000;
	if(s[n]=='L')x-=now;
	if(s[n]=='R')x+=now;
	if(s[n]=='U')y+=now;
	if(s[n]=='D')y-=now;
	printf("%d %d\n",-x,-y);
	sort(ans.begin(),ans.end());
	ans.resize(unique(ans.begin(),ans.end())-ans.begin());
	cout<<ans.size()<<'\n';
	for(auto i:ans)
		printf("%d %d\n",i.first-x,i.second-y);
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n>=3)
	{
		if(s[n]=='L'&&s[n-1]=='R'&&s[n-2]=='L')return noway,0;
		if(s[n]=='R'&&s[n-1]=='L'&&s[n-2]=='R')return noway,0;
		if(s[n]=='U'&&s[n-1]=='D'&&s[n-2]=='U')return noway,0;
		if(s[n]=='D'&&s[n-1]=='U'&&s[n-2]=='D')return noway,0;
	}
	solve();
	return 0;
}
