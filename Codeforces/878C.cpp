#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=5e4+10,MAXM=1e6+10;
const int INF=~(1<<31),MOD=1e9+7;
int n,k;
struct Node
{
	int mx[11],mi[11];
	int num;
	bool operator < (const Node &rhs)const
	{
		bool flag=true;
		for(int i=1;i<=k;i++)
			if(mi[i]<rhs.mx[i])
			flag=false;
		return flag;
	}
}s[MAXN];
 
set <Node> st;
set <Node> ::iterator it;
 
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&s[i].mx[j]);
			s[i].mi[j]=s[i].mx[j];
			s[i].num=1;
		}
	for(int i=1;i<=n;i++)
	{
		int ans=1;
		while((it=st.find(s[i]))!=st.end())
		{
			ans+=it->num;
			for(int j=1;j<=k;j++)
			{
				s[i].mi[j]=min(it->mi[j],s[i].mi[j]);
				s[i].mx[j]=max(it->mx[j],s[i].mx[j]);
			}
			st.erase(it);
		}
		s[i].num=ans;
		st.insert(s[i]);
		printf("%d\n",st.begin()->num);
	}
	return 0;
}