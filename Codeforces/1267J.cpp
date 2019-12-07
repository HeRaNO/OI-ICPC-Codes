#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,MOD=1e9+7;
const ll llINF=~(1ll<<63);

int num[MAXM],n;

bool check(int p,int s)
{
	if((s-(p%s))%s>(p+s-1)/s)
		return false;
	return true;
}

set<int> ss,st;
set<int> ::iterator it;
vector< set<int> ::iterator> v;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ss.clear();
		st.clear();
		memset(num,0,(n+2)*sizeof(int));
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			num[a]++;
		}
		for(int i=1;i<=n;i++)
			if(num[i])st.insert(num[i]);
		for(int i=1;i<=n+1;i++)
			ss.insert(i);
		for(auto j:st)
		{
			v.resize(0);
			for(it=ss.begin();it!=ss.end();it++)
			{
				if(!check(j,*it))v.push_back(it);
			}
			for(auto p:v)
				ss.erase(p);
		}
		int val=*ss.rbegin(),ans=0;
		for(int i=1;i<=n;i++)
			ans+=(num[i]+val-1)/val;
		printf("%d\n",ans);
	}
	return 0;
}