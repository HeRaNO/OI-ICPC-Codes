#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,k;
vector <pair<int,char> > v;

inline void print()
{
	printf("%d\n",v.size());
	for (auto i:v) printf("%d %c\n",i.first,i.second);
	return ;
}

inline void go(int l,char c)
{
	if (!l) return ;
	if (k<=l)
	{
		v.push_back({k,c});print();
		exit(0);
	}
	k-=l;v.push_back({l,c});
	return;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	if (k>4*n*m-2*n-2*m) return puts("NO"),0;
	puts("YES");go(n-1,'D');
	for (int i=1;i<n;i++) go(m-1,'R'),go(m-1,'L'),go(1,'U');
	for (int i=1;i<m;i++) go(1,'R'),go(n-1,'D'),go(n-1,'U');
	go(m-1,'L');
	return 0;
}
