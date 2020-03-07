#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100050;
int S,n,m,id;
map <string,int> mp;
int cur[205];
int a[205][205];
string s[205];
int b[N];

int main()
{
	scanf("%d%d%d",&S,&m,&n);
	for(int i=1;i<=S;++i)
	{
		cin>>s[i];
		cur[i]=1;
	}
	sort(s+1,s+S+1);
	for(int i=1;i<=S;++i)mp[s[i]]=i;
	for(int i=1;i<=m;++i)
	{
		string x,y;
		cin>>x>>y;
		a[mp[x]][mp[y]]=a[mp[y]][mp[x]]=1;
	}
	for(int i=1;i<=n;++i)
	{
		string x;
		cin>>x;
		b[i]=mp[x];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=S;++j)
		{
			while((b[cur[j]]==inf||a[j][b[cur[j]]])&&cur[j]<=n)cur[j]++;
			if(j==b[cur[j]])
			{
				cout<<s[j]<<" ";
				b[cur[j]]=inf;
				break;
			}
		}
	}
	return 0;
}
