#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int n;
bool flag=true;
struct Answer
{
	int a,b;
}q[N];
unordered_map <ll,bool> mp;
inline ll h(ll a,ll b)
{
	return a*100000000LL+b;
}
inline void fenjie(int pos,int x)
{
	int t=sqrt(x);
	for(int i=1;i<=t;++i)
	{
		if(x%i)continue;
		int p=x/i;
		if(!mp[h(i,p)])
		{
			mp[h(i,p)]=1;
			q[pos].a=i;
			q[pos].b=p;
			return;
		}
		if(!mp[h(p,i)])
		{
			mp[h(p,i)]=1;
			q[pos].a=p;
			q[pos].b=i;
			return;
		}
	}
	flag=false;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int c;
		scanf("%d",&c);
		fenjie(i,c);
		if(flag==false)break;
	}
	if(!flag)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=n;++i)
	{
		printf("%d %d\n",q[i].a,q[i].b);
	}
	return 0;
}