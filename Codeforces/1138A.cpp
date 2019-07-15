#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,a[MAXN],s[MAXN],ans;
vector <int> p;

int main()
{
	scanf("%d",&n);s[1]=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;i++)
	{
		if (a[i]==a[i-1]) s[i]=s[i-1]+1;
		else{s[i]=1;p.push_back(i-1);}
	}
	p.push_back(n);
	for (int i=1;i<p.size();i++) ans=max(ans,min(s[p[i]],s[p[i-1]])<<1);
	printf("%d\n",ans);
	return 0;
}