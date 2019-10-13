#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
int n,m;
int a[N];
int q[N];
int l[N],r[N];
set <int> v[N];
bool vis[N];
int _next[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		v[a[i]].insert(i);
		_next[i]=i+1;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&q[i]);
	}
	for(int i=1;i<=m;++i)
	{
		int c=q[i];
		if(v[c].size()<2||vis[c])
		{
			vis[c]=1;
			continue;
		}
		int L=*v[c].begin(),R=*v[c].rbegin();
		set<int>::iterator p=v[c].end();
		set<int>::iterator j=v[c].begin();
		j++;
		p--;
		for(;v[c].size()>2;++j)
			v[c].erase(j);
		for(int j=L+1;j<=R-1;j=_next[j])
		{
			if(a[j]!=c)
			{
				set<int>::iterator it=v[a[j]].find(j);
				if(it!=v[a[j]].end())
				{
					v[a[j]].erase(it);
				}
				a[j]=c;
			}
		}
		_next[L]=R+1;
	}
	for(int i=1;i<=n;i=_next[i])
	{
		for(int j=i;j<_next[i];j++)
		printf("%d ",a[i]);
	}
	return 0;
}